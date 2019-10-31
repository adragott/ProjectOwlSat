/*
 * project_owlsat.h
 *
 * Created: 10/10/2019 3:17:41 AM
 *  Author: penguin
 */ 
#ifndef _PROJECT_OWLSAT_H_
#define _PROJECT_OWLSAT_H_

#include <asf.h>
#include <inttypes.h>

#define ENABLE_DEBUG	(1)
#define ENABLE_USB		(1)
#define ENABLE_SD		(1)
#define ENABLE_GPS		(0)
#define ENABLE_IMU		(1)
#define ENABLE_PRESSURE	(1)

// return status for owlsat level
typedef enum os_status
{
	OS_GOOD = 0,
	OS_BAD = 1
}os_status;

typedef union u16
{
	// bytes
	uint8_t b[2];
	// value
	uint16_t v;
}u16;

typedef union i16
{
	// bytes
	uint8_t b[2];
	// value
	int16_t v;
}i16;

typedef union u32
{
	// bytes
	uint8_t b[4];
	// value
	uint32_t v;
}u32;

typedef union i32
{
	// bytes
	uint8_t b[4];
	// value
	int32_t v;
}i32;

#define Stringize( L )     #L
#define MakeString( M, L ) M(L)
#define $Line MakeString( Stringize, __LINE__ )
#define Reminder __FILE__ "(" $Line ") : Reminder: "

#endif