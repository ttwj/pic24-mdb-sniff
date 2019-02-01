#include "DebugPrint.h"
#include <stdio.h>
#include <stdbool.h>

unsigned int last_output = 0;
bool tx_overflowed = false;

void _debug_print_str(char* str) {
    size_t len = strlen(str);
    last_output = UART2_WriteBuffer((uint8_t*)str, len);
    if (UART2_StatusGet() & UART2_TX_FULL) {
        tx_overflowed = true;
    }
    // Might as well wait for write to complete
//    UART2_Flush();
}

void _debug_println_str(char* str) {
    _debug_print_str(str);
    //UART2_Write('\r');
    UART2_Write('\n');
//    UART2_Flush();
}

// hex mode: one byte becomes 'xFF '
char formatted_str[DEBUG_PRINTHEX_MAX * 4];

void _debug_print_hex(byte* buf, size_t len) {
    size_t i, real_len;
    
    // Maximum length acceptable is DEBUG_PRINTHEX_MAX
    real_len = (len > DEBUG_PRINTHEX_MAX) ? DEBUG_PRINTHEX_MAX : len;
    
    // hex it
    for (i=0; i<real_len; i++) {
        sprintf(formatted_str + i*4, "x%02X ", buf[i]);
    }
    
    // only write as many bytes as we actually wrote
    UART2_WriteBuffer((uint8_t*)formatted_str, (size_t)real_len*4);
//    UART2_Flush();
}

void _debug_println_hex(byte* buf, size_t len) {
    _debug_print_hex(buf, len);
    UART2_Write('\n');
//    UART2_Flush();
}

void _debug_print_int(int x) {
    int str_len = sprintf(formatted_str, "%d", x);
    UART2_WriteBuffer((uint8_t*)formatted_str, str_len);
//    UART2_Flush();
} 

void _debug_print_uint(unsigned int x) {
    int str_len = sprintf(formatted_str, "%u", x);
    UART2_WriteBuffer((uint8_t*)formatted_str, str_len);
//    UART2_Flush();
}