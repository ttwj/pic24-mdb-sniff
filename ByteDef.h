/* 
 * File:   ByteDef.h
 * Author: nikos
 *
 * Created on December 27, 2018, 12:09 AM
 * 
 * This file's only purpose is to avoid "redefinition of typedef 'byte'" errors
 */

#include <stdint.h>

#ifndef BYTEDEF_H
#define	BYTEDEF_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef uint8_t byte;


#ifdef	__cplusplus
}
#endif

#endif	/* BYTEDEF_H */

