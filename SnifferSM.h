/* 
 * File:   SnifferSM.h
 * Author: nikos
 *
 * Created on January 9, 2019, 11:52 AM
 */

#include <stdbool.h>

#ifndef SNIFFERSM_H
#define	SNIFFERSM_H

// This eventually translates into a 0.5ms timer interval. Don't ask
#define MDB_WAIT_FOR_TICKS 1000

// The magic address that will trigger the sniffing
#define MDB_WATCH_ADDR 0x13 //0x12

// 50 8-bit bytes max. (Throw away address bit - not sending over adserial)
#define MDB_BUF_MAX 50

#ifdef	__cplusplus
extern "C" {
#endif

    enum State {
        WAIT,
        NEXT_BYTE,
        OVERFLOW,
        TIMEOUT,
        SEND_AD,
        BAD_CKSUM
    };

    // Volatile: value of state may change between consecutive statements
    // Force compiler to emit instructions that fetch state from memory every time it's read
    // (instead of using a value of state that might be in the registers)
    volatile extern enum State state;

    /**
     * Advance the sniffer SM.
     */
    void step(void);
    
    /**
     * Run when the timer expires.
     */
    inline void timer_expire(void);



#ifdef	__cplusplus
}
#endif

#endif	/* SNIFFERSM_H */

