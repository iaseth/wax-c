#ifndef WAX_CONVERT_H
#define WAX_CONVERT_H

#include "wax/common.h"


typedef struct TimeOfDay {
	u32 hh, mm, ss;
} TimeOfDay;

TimeOfDay xtod (u32 timestamp);
double x100 (u32 price);
double xk (u32 price);
double xm (u32 price);


#endif