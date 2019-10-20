//PartTypes.h 
#pragma once

#ifndef _PART_TYPES_H
#define _PART_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

typedef unsigned short part_t;

/*
**	Each type will have it's own flag. This will allow
**	kits, and composite parts.
*/

#define FRAME_FLAG 				0x0001
#define MOTOR_FLAG 				0x0002
#define ESC_FLAG 				0x0004
#define FLIGHTCONTROLLER_FLAG 	0x0008
#define PDB_FLAG 				0x0010
#define BATTERY_FLAG 			0x0020
#define PROPELLER_FLAG 			0x0040

/* //To be added later potentially...
#define FPVANTENNA_FLAG 		0x0080
#define FPVTRANSMITTER_FLAG 	0x0100
#define FPVCAMERA_FLAG	 		0x0200
#define HDCAMERA_FLAG			0x0400
*/

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //_PART_TYPES_H
