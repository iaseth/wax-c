#include "wax_convert.h"



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


