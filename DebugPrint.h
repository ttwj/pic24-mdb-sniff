/* 
 * File:   DebugPrint.h
 * Author: nikos
 *
 * Created on December 26, 2018, 11:52 PM
 */

#ifndef DEBUGPRINT_H
#define	DEBUGPRINT_H

#include <string.h>
#include "ByteDef.h"
#include "mcc_generated_files/uart2.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define DEBUG
    
#ifdef DEBUG    //Macros 


    
// Exceed 16 bytes at your own peril
#define DEBUG_PRINTHEX_MAX 16
#define DebugPrint(x)    _debug_print_str(x)  //debug print, do not need to put text in between of double quotes
#define DebugPrintHexStrLn(x, l)   _debug_println_hex(x, l)
#define DebugPrintHexStr(x, l)   _debug_print_hex(x, l)
#define DebugPrintLn(x)  _debug_println_str(x)  //debug print with new line
#define DebugPrintInt(x) _debug_print_int(x)
#define DebugPrintUInt(x) _debug_print_uint(x)
    
extern unsigned int last_output;
    
/**
 * Print a null-terminated string
 * @param str
 */
void _debug_print_str(char* str);

/**
 * Print a null-terminated string followed by a newline
 * @param str
 */
void _debug_println_str(char* str);

/**
 * Print a sequence of bytes in hex form (maximum length 256)
 * @param buf
 * @param len
 */
void _debug_print_hex(byte* buf, size_t len);

/**
 * Print a sequence of bytes in hex, followed by a newline
 * @param buf
 * @param len
 */
void _debug_println_hex(byte* buf, size_t len);

/**
 * Print an integer
 * @param x
 */
void _debug_print_int(int x);

/**
 * Print an unsigned integer
 * @param x
 */
void _debug_print_uint(unsigned int x);
    
#else // DEBUG

#define DEBUG_PRINTHEX_MAX 1
#define DebugPrint(x)    
#define DebugPrintHexStrLn(x, l)
#define DebugPrintHexStr(x, l)
#define DebugPrintLn(x)
#define DebugPrintInt(x) 
#define DebugPrintUInt(x)
    
extern unsigned int last_output;
   

#endif // DEBUG

#ifdef	__cplusplus
}
#endif

#endif	/* DEBUGPRINT_H */

