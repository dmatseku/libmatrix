#ifndef MATRIX_CONVERSION_H
#define MATRIX_CONVERSION_H

#include <vector.h>
#include <matrix.h>
#include <quaternion.h>

t_quaternion    quaternion_from_axis(const t_vec3 *axis, t_float angle);

t_quaternion    quaternion_from_euler(const t_vec3 *euler);

t_quaternion    quaternion_from_matrix(const t_mat4 *matrix);

t_mat4          matrix_from_quaternion(const t_quaternion *quaternion);

//  ----DESTINATION----

void            quaternion_from_axis_d(const t_vec3 *axis, t_float angle, t_quaternion *dest);

void            quaternion_from_matrix_d(const t_mat4 *matrix, t_quaternion *dest);

void            quaternion_from_euler_d(const t_vec3 *euler, t_quaternion *dest);

void            matrix_from_quaternion_d(const t_quaternion *quaternion, t_mat4 *dest);

#endif /*MATRIX_CONVERSION_H*/
