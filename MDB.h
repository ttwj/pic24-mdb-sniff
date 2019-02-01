/* 
 * File:   MDB.h
 * Author: nikos
 *
 * Created on January 9, 2019, 11:56 AM
 */
#include <stdint.h>
#include <stddef.h>

#ifndef MDB_H
#define	MDB_H

#ifdef	__cplusplus
extern "C" {
#endif

/**
 * Calculate MDB message checksum.
 * 
 * @param arr 
 * Array of bytes that form the message (excluding the included checksum byte)
 * 
 * @param arr_size
 * Number of bytes in the message
 * 
 * @return 
 * Unsigned checksum
 */
uint8_t calc_checksum(uint8_t arr[], size_t arr_size);


#ifdef	__cplusplus
}
#endif

#endif	/* MDB_H */

