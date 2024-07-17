#include "wax_convert.h"



TimeOfDay xtod (u32 timestamp)
{
	timestamp += 330 * 60;
	u32 extra_seconds = timestamp % 86400;
	TimeOfDay t;
	t.hh = extra_seconds / 3600;
	t.mm = (extra_seconds / 60) % 60;
	t.ss = extra_seconds % 60;
	return t;
}

double x100 (u32 price) {
	double x = price;
	x = x / 100;
	return x;
}

double xk (u32 volume) {
	double x = volume;
	x = x / 1000;
	return x;
}

double xm (u32 volume) {
	double x = volume;
	x = x / 1000000;
	return x;
}


