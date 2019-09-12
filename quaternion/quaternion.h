#ifndef QUATERNION_H
#define QUATERNION_H

#include <libmatrix_structs.h>

t_vec4	quaternion_conjugate(t_vec4 quaternion);

float	quaternion_norm(t_vec4 quaternion);

float	quaternion_norm_nosqrt(t_vec4 quaternion);

t_vec4	quaternion_reverse(t_vec4 quaternion);

#endif