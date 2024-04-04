#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <vector.h>
#include <general.h>

typedef struct  s_mat4
{
    t_float     m00, m01, m02, m03;
    t_float     m10, m11, m12, m13;
    t_float     m20, m21, m22, m23;
    t_float     m30, m31, m32, m33;
}               t_mat4;

typedef struct  s_mat3
{
    t_float     m00, m01, m02;
    t_float     m10, m11, m12;
    t_float     m20, m21, m22;
}               t_mat3;

typedef struct  s_mat2
{
    t_float     m00, m01;
    t_float     m10, m11;
}               t_mat2;

#define mat4 (t_mat4) \
{ \
    .m00 = 1, .m01 = 0, .m02 = 0, .m03 = 0, \
    .m10 = 0, .m11 = 1, .m12 = 0, .m13 = 0, \
    .m20 = 0, .m21 = 0, .m22 = 1, .m23 = 0, \
    .m30 = 0, .m31 = 0, .m32 = 0, .m33 = 1  \
}

#define mat3 (t_mat3) \
{ \
    .m00 = 1, .m01 = 0, .m02 = 0, \
    .m10 = 0, .m11 = 1, .m12 = 0, \
    .m20 = 0, .m21 = 0, .m22 = 1  \
}

#define mat2 (t_mat2) \
{ \
    .m00 = 1, .m01 = 0, \
    .m10 = 0, .m11 = 1  \
}

#define mat4_zero (t_mat4) \
{ \
    .m00 = 0, .m01 = 0, .m02 = 0, .m03 = 0, \
    .m10 = 0, .m11 = 0, .m12 = 0, .m13 = 0, \
    .m20 = 0, .m21 = 0, .m22 = 0, .m23 = 0, \
    .m30 = 0, .m31 = 0, .m32 = 0, .m33 = 0  \
}

#define mat3_zero (t_mat3) \
{ \
    .m00 = 0, .m01 = 0, .m02 = 0, \
    .m10 = 0, .m11 = 0, .m12 = 0, \
    .m20 = 0, .m21 = 0, .m22 = 0  \
}

#define mat2_zero (t_mat2) \
{ \
    .m00 = 0, .m01 = 0, \
    .m10 = 0, .m11 = 0  \
}

//  ----MATRIX 4x4----

t_mat4  mat4_add(const t_mat4 *matrix_left, const t_mat4 *matrix_right);

t_mat4  mat4_sub(const t_mat4 *matrix_left, const t_mat4 *matrix_right);

t_mat4  mat4_mult(const t_mat4 *matrix_left, const t_mat4 *matrix_right);

t_vec4  mat4_trans(const t_mat4 *matrix, const t_vec4 *vector);

t_mat4  mat4_transpose(const t_mat4 *matrix);

void    mat4_set_identity(t_mat4 *dest_matrix);

void    mat4_set_zero(t_mat4 *dest_matrix);

t_mat4  mat4_negate(const t_mat4 *matrix);

void    mat4_negate_self(t_mat4 *matrix);

t_mat4  mat4_invert(const t_mat4 *matrix);

void    mat4_invert_self(t_mat4 *matrix);

t_float mat4_det(const t_mat4 *matrix);

void    mat4_scale_self(t_mat4 *matrix, const t_vec3 *scale);

void    mat4_rotate_self(t_mat4 *matrix, const t_vec3 *euler_axis, t_float angle);

void    mat4_translate_self(t_mat4 *matrix, const t_vec3 *translation);

//  ----MATRIX 4x4 WITH DESTINATION----

void    mat4_add_d(const t_mat4 *matrix_left, const t_mat4 *matrix_right, t_mat4 *dest);

void    mat4_sub_d(const t_mat4 *matrix_left, const t_mat4 *matrix_right, t_mat4 *dest);

void    mat4_mult_d(const t_mat4 *matrix_left, const t_mat4 *matrix_right, t_mat4 *restrict dest);

void    mat4_trans_d(const t_mat4 *matrix, const t_vec4 *restrict vector, t_vec4 *restrict dest);

void    mat4_transpose_d(const t_mat4 *restrict matrix, t_mat4 *restrict dest);

void    mat4_negate_d(const t_mat4 *matrix, t_mat4 *dest);

void    mat4_invert_d(const t_mat4 *restrict matrix, t_mat4 *restrict dest);

void    mat4_scale_d(const t_mat4 *matrix, const t_vec3 *scale, t_mat4 *dest);

void    mat4_rotate_d(const t_mat4 *matrix, const t_vec3 *euler_axis, t_float angle, t_mat4 *restrict dest);

void    mat4_translate_d(const t_mat4 *matrix, const t_vec3 *translation, t_mat4 *dest);

//  ----MATRIX 3x3----

t_mat3  mat3_add(const t_mat3 *matrix_left, const t_mat3 *matrix_right);

t_mat3  mat3_sub(const t_mat3 *matrix_left, const t_mat3 *matrix_right);

t_mat3  mat3_mult(const t_mat3 *matrix_left, const t_mat3 *matrix_right);

t_vec3  mat3_trans(const t_mat3 *matrix, const t_vec3 *vector);

t_mat3  mat3_transpose(const t_mat3 *matrix);

void    mat3_set_identity(t_mat3 *matrix);

void    mat3_set_zero(t_mat3 *matrix);

t_mat3  mat3_negate(const t_mat3 *matrix);

void    mat3_negate_self(t_mat3 *matrix);

t_mat3  mat3_invert(const t_mat3 *matrix);

void    mat3_invert_self(t_mat3 *matrix);

t_float mat3_det(const t_mat3 *matrix);

//  ----MATRIX 3x3 WITH DESTINATION----

void    mat3_add_d(const t_mat3 *matrix_left, const t_mat3 *matrix_right, t_mat3 *dest);

void    mat3_sub_d(const t_mat3 *matrix_left, const t_mat3 *matrix_right, t_mat3 *dest);

void    mat3_mult_d(const t_mat3 *matrix_left, const t_mat3 *matrix_right, t_mat3 *restrict dest);

void    mat3_trans_d(const t_mat3 *matrix, const t_vec3 *restrict vector, t_vec3 *restrict dest);

void    mat3_transpose_d(const t_mat3 *restrict matrix, t_mat3 *restrict dest);

void    mat3_negate_d(const t_mat3 *matrix, t_mat3 *dest);

void    mat3_invert_d(const t_mat3 *restrict matrix, t_mat3 *restrict dest);

//  ----MATRIX 2x2----

t_mat2  mat2_add(const t_mat2 *matrix_left, const t_mat2 *matrix_right);

t_mat2  mat2_sub(const t_mat2 *matrix_left, const t_mat2 *matrix_right);

t_mat2  mat2_mult(const t_mat2 *matrix_left, const t_mat2 *matrix_right);

t_vec2  mat2_trans(const t_mat2 *matrix, const t_vec2 *vector);

t_mat2  mat2_transpose(const t_mat2 *matrix);

void    mat2_set_identity(t_mat2 *matrix);

void    mat2_set_zero(t_mat2 *matrix);

t_mat2  mat2_negate(const t_mat2 *matrix);

void    mat2_negate_self(t_mat2 *matrix);

t_mat2  mat2_invert(const t_mat2 *matrix);

void    mat2_invert_self(t_mat2 *matrix);

t_float mat2_det(const t_mat2 *matrix);

//  ----MATRIX 2x2 WITH DESTINATION----

void    mat2_add_d(const t_mat2 *matrix_left, const t_mat2 *matrix_right, t_mat2 *dest);

void    mat2_sub_d(const t_mat2 *matrix_left, const t_mat2 *matrix_right, t_mat2 *dest);

void    mat2_mult_d(const t_mat2 *matrix_left, const t_mat2 *matrix_right, t_mat2 *restrict dest);

void    mat2_trans_d(const t_mat2 *matrix, const t_vec2 *vector, t_vec2 *restrict dest);

void    mat2_transpose_d(const t_mat2 *restrict matrix, t_mat2 *restrict dest);

void    mat2_negate_d(const t_mat2 *matrix, t_mat2 *dest);

void    mat2_invert_d(const t_mat2 *restrict matrix, t_mat2 *restrict dest);

#endif /*MATRIX_MATRIX_H*/
