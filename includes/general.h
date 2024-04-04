#ifndef MATRIX_GENERAL_H
#define MATRIX_GENERAL_H

#include <math.h>

typedef double t_float;

#define INTERPOLATE(a, b, t) a + ((b - a) * t)

#define RAD(degree) (M_PI / 180) * degree

#define DEGREE(radian) (180.0 / M_PI) * radian

#endif /*MATRIX_GENERAL_H*/
