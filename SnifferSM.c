#include "SnifferSM.h"
#include "DebugPrint.h"
#include "mcc_generated_files/tmr1.h"
#include "MDB.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/uart2.h"

volatile enum State state = WAIT;


uint8_t input_buf[MDB_BUF_MAX]; // 50 byte buffer to store mdb stuff
volatile size_t input_len = 0; // current input length

// Signal while-loop in NEXT_BYTE state
volatile bool next_byte_loop = true;

void step(void) {
    // Copied 9 bit "byte" from USART rx
    uint16_t current_dword = 0;

    // Calculated checksum for payload
    uint8_t checksum = 0;

    // array iteration
    size_t i;

    switch (state) {
        case WAIT:
            while (1) {
                if (!UART1_ReceiveBufferIsEmpty()) {
                    current_dword = UART1_Read();

                    DebugPrint("[wait] addr=");
                    DebugPrintHexStrLn(&current_dword, 1);

                    if (current_dword == MDB_WATCH_ADDR) {
                         DebugPrint("[MATCH]");
                        DebugPrintHexStrLn(&current_dword, 1);
                        // Reset and turn on timer
                        TMR1_Counter16BitSet(0);
                        TMR1_Start();

                        // Also disregard anything previously in the buffer
                        input_buf[0] = (uint8_t)current_dword;
                        input_len = 1;

                        state = NEXT_BYTE;
                        break;
                    }
                }
            }
            break;

        case NEXT_BYTE:
            DebugPrintLn("[NEXT_BYTE] Waiting...");

            // volatile
            next_byte_loop = true;
            while (next_byte_loop) {
                if (!UART1_ReceiveBufferIsEmpty()) {
                    if (input_len == MDB_BUF_MAX) {
                        state = OVERFLOW;
                        break;
                    }

                    current_dword = UART1_Read();

                    DebugPrint("[NEXT_BYTE] Got byte=");
                    DebugPrintHexStr(&current_dword, 1);

                    if (0x0100 & current_dword) {
                        DebugPrintLn("<<Address>>");
                        DebugPrintLn("[NEXT_BYTE] Discarding this byte and transitioning");
                        if (!next_byte_loop) {
                            DebugPrintLn("Next_byte_loop timing issue?");
                        }
                        state = TIMEOUT;
                        break;
                    }
                    
                    input_buf[input_len] = (uint8_t)current_dword;
                    input_len++;

                    DebugPrint(", new length=");
                    DebugPrintUInt(input_len);

                    // remember to reset the timer
                    TMR1_Counter16BitSet(0);
                }
            }
            break;

        case OVERFLOW:
            DebugPrint("[OVERFLOW] input_len=");
            DebugPrintUInt(input_len);
            DebugPrint(", input_buf=");            
            DebugPrintHexStr(input_buf, input_len);
            DebugPrintLn("");
            DebugPrintLn("[OVERFLOW] Discarding current sequence");

            input_len = 0;
            state = WAIT;
            break;

        case TIMEOUT:
            // Disable timer interrupt
            TMR1_Stop();

            // Calculate checksum
            checksum = calc_checksum(input_buf, input_len - 1);

            DebugPrint("[TIMEOUT] calculated checksum=");
            DebugPrintHexStr(&checksum, 1);
            DebugPrint(", received checksum=");
            DebugPrintHexStrLn(input_buf + input_len - 1, 1);

            if (checksum == input_buf[input_len - 1]) {
                state = SEND_AD;
            } else {
                state = BAD_CKSUM;
            }
            break;

        case SEND_AD:
            DebugPrintLn("[SEND_AD] Writing...");

            //for (i = 0; i < input_len; i++) {
            //    UART2_Write(input_buf[i]);
            //}
            
            UART2_WriteBuffer(input_buf, input_len);

            DebugPrint("[SEND_AD] Wrote bytes=");
            DebugPrintUInt(input_len);
            DebugPrintLn("");
            state = WAIT;
            break;

        case BAD_CKSUM:
            DebugPrintLn("[BAD_CKSUM] Going back to wait");
            input_len = 0;
            state = WAIT;
            break;

        default:
            DebugPrintLn("[Unknown state, resetting]");
            state = WAIT;
            break;
    }
}

void timer_expire(void) {
    // timer expired: signal main loop to disable timer, check checksum and send buffer over UART2
    // (goto is probably cleaner, but it can't jump across functions - that would wreck the stack)
    if (state == NEXT_BYTE) {
        state = TIMEOUT;
        next_byte_loop = false;
        DebugPrintLn("[T!]");
    }
}

// Override mcc_generated_files/tmr1.c::TMR1_CallBack

void TMR1_CallBack(void) {
    timer_expire();
}
