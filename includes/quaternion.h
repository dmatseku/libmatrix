#ifndef MATRIX_QUATERNION_H
#define MATRIX_QUATERNION_H

#include <matrix.h>
#include <general.h>

typedef struct  s_quaternion
{
    t_float     x;
    t_float     y;
    t_float     z;
    t_float     w;
}               t_quaternion;

#define quaternion(vx, vy, vz, vw) (t_quaternion){ .x = vx, .y = vy, .z = vz, .w = vw }

t_float         quaternion_length(const t_quaternion *quaternion);

t_quaternion    quaternion_mult(const t_quaternion *quaternion_left, const t_quaternion *quaternion_right);

t_vec3          quaternion_vec3_mult(const t_quaternion *quaternion, const t_vec3 *vector);

t_vec4          quaternion_vec4_mult(const t_quaternion *quaternion, const t_vec4 *vector);

t_quaternion    quaternion_slerp(const t_quaternion *quaternion_left, const t_quaternion *quaternion_right, t_float blend);

t_quaternion    quaternion_look_rotation(const t_vec3 *forward, const t_vec3 *up);

void            quaternion_set_identity(t_quaternion *restrict dest_quaternion);

void            quaternion_normalize_self(t_quaternion *quaternion);

void            quaternion_negate_self(t_quaternion *quaternion);

t_vec4          quaternion_rotate_hamilton(const t_quaternion *quaternion, const t_vec4 *vector);

t_vec3          quaternion_rotate_hamilton3(const t_quaternion *quaternion, const t_vec3 *vector);

//  ----DESTINATION----

void            quaternion_mult_d(const t_quaternion *quaternion_left, const t_quaternion *quaternion_right, t_quaternion *restrict dest);

void            quaternion_vec3_mult_d(const t_quaternion *quaternion, const t_vec3 *vector, t_vec3 *restrict dest);

void            quaternion_vec4_mult_d(const t_quaternion *quaternion, const t_vec4 *vector, t_vec4 *restrict dest);

void            quaternion_slerp_d(const t_quaternion *quaternion_left, const t_quaternion *quaternion_right, t_float blend, t_quaternion *dest);

void            quaternion_look_rotation_d(const t_vec3 *forward, const t_vec3 *up, t_quaternion *dest);

void            quaternion_rotate_hamilton_d(const t_quaternion *quaternion, const t_vec4 *vector, t_vec4 *dest);

void            quaternion_rotate_hamilton3_d(const t_quaternion *quaternion, const t_vec3 *vector, t_vec3 *dest);

#endif /*MATRIX_QUATERNION_H*/
