#include <matrix.h>
#include <math.h>

void
mat4_add_d(const t_mat4 *const matrix_left, const t_mat4 *const matrix_right, t_mat4 *const dest)
{
    dest->m00 = matrix_left->m00 + matrix_right->m00;
    dest->m01 = matrix_left->m01 + matrix_right->m01;
    dest->m02 = matrix_left->m02 + matrix_right->m02;
    dest->m03 = matrix_left->m03 + matrix_right->m03;
    dest->m10 = matrix_left->m10 + matrix_right->m10;
    dest->m11 = matrix_left->m11 + matrix_right->m11;
    dest->m12 = matrix_left->m12 + matrix_right->m12;
    dest->m13 = matrix_left->m13 + matrix_right->m13;
    dest->m20 = matrix_left->m20 + matrix_right->m20;
    dest->m21 = matrix_left->m21 + matrix_right->m21;
    dest->m22 = matrix_left->m22 + matrix_right->m22;
    dest->m23 = matrix_left->m23 + matrix_right->m23;
    dest->m30 = matrix_left->m30 + matrix_right->m30;
    dest->m31 = matrix_left->m31 + matrix_right->m31;
    dest->m32 = matrix_left->m32 + matrix_right->m32;
    dest->m33 = matrix_left->m33 + matrix_right->m33;
}

void
mat4_sub_d(const t_mat4 *const matrix_left, const t_mat4 *const matrix_right, t_mat4 *const dest)
{
    dest->m00 = matrix_left->m00 - matrix_right->m00;
    dest->m01 = matrix_left->m01 - matrix_right->m01;
    dest->m02 = matrix_left->m02 - matrix_right->m02;
    dest->m03 = matrix_left->m03 - matrix_right->m03;
    dest->m10 = matrix_left->m10 - matrix_right->m10;
    dest->m11 = matrix_left->m11 - matrix_right->m11;
    dest->m12 = matrix_left->m12 - matrix_right->m12;
    dest->m13 = matrix_left->m13 - matrix_right->m13;
    dest->m20 = matrix_left->m20 - matrix_right->m20;
    dest->m21 = matrix_left->m21 - matrix_right->m21;
    dest->m22 = matrix_left->m22 - matrix_right->m22;
    dest->m23 = matrix_left->m23 - matrix_right->m23;
    dest->m30 = matrix_left->m30 - matrix_right->m30;
    dest->m31 = matrix_left->m31 - matrix_right->m31;
    dest->m32 = matrix_left->m32 - matrix_right->m32;
    dest->m33 = matrix_left->m33 - matrix_right->m33;
}

void
mat4_mult_d(const t_mat4 *const matrix_left, const t_mat4 *const matrix_right, t_mat4 *const restrict dest)
{
    dest->m00 =  matrix_left->m00 * matrix_right->m00 + matrix_left->m10 * matrix_right->m01 +
                 matrix_left->m20 * matrix_right->m02 + matrix_left->m30 * matrix_right->m03;
    dest->m01 =  matrix_left->m01 * matrix_right->m00 + matrix_left->m11 * matrix_right->m01 +
                 matrix_left->m21 * matrix_right->m02 + matrix_left->m31 * matrix_right->m03;
    dest->m02 =  matrix_left->m02 * matrix_right->m00 + matrix_left->m12 * matrix_right->m01 +
                 matrix_left->m22 * matrix_right->m02 + matrix_left->m32 * matrix_right->m03;
    dest->m03 =  matrix_left->m03 * matrix_right->m00 + matrix_left->m13 * matrix_right->m01 +
                 matrix_left->m23 * matrix_right->m02 + matrix_left->m33 * matrix_right->m03;

    dest->m10 =  matrix_left->m00 * matrix_right->m10 + matrix_left->m10 * matrix_right->m11 +
                 matrix_left->m20 * matrix_right->m12 + matrix_left->m30 * matrix_right->m13;
    dest->m11 =  matrix_left->m01 * matrix_right->m10 + matrix_left->m11 * matrix_right->m11 +
                 matrix_left->m21 * matrix_right->m12 + matrix_left->m31 * matrix_right->m13;
    dest->m12 =  matrix_left->m02 * matrix_right->m10 + matrix_left->m12 * matrix_right->m11 +
                 matrix_left->m22 * matrix_right->m12 + matrix_left->m32 * matrix_right->m13;
    dest->m13 =  matrix_left->m03 * matrix_right->m10 + matrix_left->m13 * matrix_right->m11 +
                 matrix_left->m23 * matrix_right->m12 + matrix_left->m33 * matrix_right->m13;

    dest->m20 =  matrix_left->m00 * matrix_right->m20 + matrix_left->m10 * matrix_right->m21 +
                 matrix_left->m20 * matrix_right->m22 + matrix_left->m30 * matrix_right->m23;
    dest->m21 =  matrix_left->m01 * matrix_right->m20 + matrix_left->m11 * matrix_right->m21 +
                 matrix_left->m21 * matrix_right->m22 + matrix_left->m31 * matrix_right->m23;
    dest->m22 =  matrix_left->m02 * matrix_right->m20 + matrix_left->m12 * matrix_right->m21 +
                 matrix_left->m22 * matrix_right->m22 + matrix_left->m32 * matrix_right->m23;
    dest->m23 =  matrix_left->m03 * matrix_right->m20 + matrix_left->m13 * matrix_right->m21 +
                 matrix_left->m23 * matrix_right->m22 + matrix_left->m33 * matrix_right->m23;

    dest->m30 =  matrix_left->m00 * matrix_right->m30 + matrix_left->m10 * matrix_right->m31 +
                 matrix_left->m20 * matrix_right->m32 + matrix_left->m30 * matrix_right->m33;
    dest->m31 =  matrix_left->m01 * matrix_right->m30 + matrix_left->m11 * matrix_right->m31 +
                 matrix_left->m21 * matrix_right->m32 + matrix_left->m31 * matrix_right->m33;
    dest->m32 =  matrix_left->m02 * matrix_right->m30 + matrix_left->m12 * matrix_right->m31 +
                 matrix_left->m22 * matrix_right->m32 + matrix_left->m32 * matrix_right->m33;
    dest->m33 =  matrix_left->m03 * matrix_right->m30 + matrix_left->m13 * matrix_right->m31 +
                 matrix_left->m23 * matrix_right->m32 + matrix_left->m33 * matrix_right->m33;
}

void
mat4_trans_d(const t_mat4 *const matrix, const t_vec4 *const restrict vector, t_vec4 *const restrict dest)
{
    dest->x =   matrix->m00 * vector->x +
                matrix->m10 * vector->y +
                matrix->m20 * vector->z +
                matrix->m30 * vector->w;
    dest->y =   matrix->m01 * vector->x +
                matrix->m11 * vector->y +
                matrix->m21 * vector->z +
                matrix->m31 * vector->w;
    dest->z =   matrix->m02 * vector->x +
                matrix->m12 * vector->y +
                matrix->m22 * vector->z +
                matrix->m32 * vector->w;
    dest->w =   matrix->m03 * vector->x +
                matrix->m13 * vector->y +
                matrix->m23 * vector->z +
                matrix->m33 * vector->w;
}

void
mat4_transpose_d(const t_mat4 *const restrict matrix, t_mat4 *const restrict dest)
{
    dest->m00 = matrix->m00;
    dest->m01 = matrix->m10;
    dest->m02 = matrix->m20;
    dest->m03 = matrix->m30;
    dest->m10 = matrix->m01;
    dest->m11 = matrix->m11;
    dest->m12 = matrix->m21;
    dest->m13 = matrix->m31;
    dest->m20 = matrix->m02;
    dest->m21 = matrix->m12;
    dest->m22 = matrix->m22;
    dest->m23 = matrix->m32;
    dest->m30 = matrix->m03;
    dest->m31 = matrix->m13;
    dest->m32 = matrix->m23;
    dest->m33 = matrix->m33;
}

void
mat4_negate_d(const t_mat4 *const matrix, t_mat4 *const dest)
{
    dest->m00 = -matrix->m00;
    dest->m01 = -matrix->m01;
    dest->m02 = -matrix->m02;
    dest->m03 = -matrix->m03;

    dest->m10 = -matrix->m10;
    dest->m11 = -matrix->m11;
    dest->m12 = -matrix->m12;
    dest->m13 = -matrix->m13;

    dest->m20 = -matrix->m20;
    dest->m21 = -matrix->m21;
    dest->m22 = -matrix->m22;
    dest->m23 = -matrix->m23;

    dest->m30 = -matrix->m30;
    dest->m31 = -matrix->m31;
    dest->m32 = -matrix->m32;
    dest->m33 = -matrix->m33;
}

#define mat3_det_inline(m00, m01, m02, m10, m11, m12, m20, m21, m22) m00 * (m11 * m22 - m12 * m21) + m01 * (m12 * m20 - m10 * m22) + m02 * (m10 * m21 - m11 * m20)

void
mat4_invert_d(const t_mat4 *const restrict matrix, t_mat4 *const restrict dest)
{
    t_float det = mat4_det(matrix);

    if (det != 0)
    {
        t_float det_invert = 1.0 / det;

        dest->m00 = mat3_det_inline
        (
            matrix->m11, matrix->m12, matrix->m13,
            matrix->m21, matrix->m22, matrix->m23,
            matrix->m31, matrix->m32, matrix->m33
        ) * det_invert;
        dest->m01 = -mat3_det_inline
        (
            matrix->m10, matrix->m12, matrix->m13,
            matrix->m20, matrix->m22, matrix->m23,
            matrix->m30, matrix->m32, matrix->m33
        ) * det_invert;
        dest->m02 = mat3_det_inline
        (
            matrix->m10, matrix->m11, matrix->m13,
            matrix->m20, matrix->m21, matrix->m23,
            matrix->m30, matrix->m31, matrix->m33
        ) * det_invert;
        dest->m03 = -mat3_det_inline
        (
            matrix->m10, matrix->m11, matrix->m12,
            matrix->m20, matrix->m21, matrix->m22,
            matrix->m30, matrix->m31, matrix->m32
        ) * det_invert;

        dest->m10 = -mat3_det_inline
        (
            matrix->m01, matrix->m02, matrix->m03,
            matrix->m21, matrix->m22, matrix->m23,
            matrix->m31, matrix->m32, matrix->m33
        ) * det_invert;
        dest->m11 = mat3_det_inline
        (
            matrix->m00, matrix->m02, matrix->m03,
            matrix->m20, matrix->m22, matrix->m23,
            matrix->m30, matrix->m32, matrix->m33
        ) * det_invert;
        dest->m12 = -mat3_det_inline
        (
            matrix->m00, matrix->m01, matrix->m03,
            matrix->m20, matrix->m21, matrix->m23,
            matrix->m30, matrix->m31, matrix->m33
        ) * det_invert;
        dest->m13 = mat3_det_inline
        (
            matrix->m00, matrix->m01, matrix->m02,
            matrix->m20, matrix->m21, matrix->m22,
            matrix->m30, matrix->m31, matrix->m32
        ) * det_invert;

        dest->m20 = mat3_det_inline
        (
            matrix->m01, matrix->m02, matrix->m03,
            matrix->m11, matrix->m12, matrix->m13,
            matrix->m31, matrix->m32, matrix->m33
        ) * det_invert;
        dest->m21 = -mat3_det_inline
        (
            matrix->m00, matrix->m02, matrix->m03,
            matrix->m10, matrix->m12, matrix->m13,
            matrix->m30, matrix->m32, matrix->m33
        ) * det_invert;
        dest->m22 = mat3_det_inline
        (
            matrix->m00, matrix->m01, matrix->m03,
            matrix->m10, matrix->m11, matrix->m13,
            matrix->m30, matrix->m31, matrix->m33
        ) * det_invert;
        dest->m23 = -mat3_det_inline
        (
            matrix->m00, matrix->m01, matrix->m02,
            matrix->m10, matrix->m11, matrix->m12,
            matrix->m30, matrix->m31, matrix->m32
        ) * det_invert;

        dest->m30 = -mat3_det_inline
        (
            matrix->m01, matrix->m02, matrix->m03,
            matrix->m11, matrix->m12, matrix->m13,
            matrix->m21, matrix->m22, matrix->m23
        ) * det_invert;
        dest->m31 = mat3_det_inline
        (
            matrix->m00, matrix->m02, matrix->m03,
            matrix->m10, matrix->m12, matrix->m13,
            matrix->m20, matrix->m22, matrix->m23
        ) * det_invert;
        dest->m32 = -mat3_det_inline
        (
            matrix->m00, matrix->m01, matrix->m03,
            matrix->m10, matrix->m11, matrix->m13,
            matrix->m20, matrix->m21, matrix->m23
        ) * det_invert;
        dest->m33 = mat3_det_inline
        (
            matrix->m00, matrix->m01, matrix->m02,
            matrix->m10, matrix->m11, matrix->m12,
            matrix->m20, matrix->m21, matrix->m22
        ) * det_invert;
    }
    else
    {
        *dest = *matrix;
    }
}

void
mat4_scale_d(const t_mat4 *const matrix, const t_vec3 *const scale, t_mat4 *const dest)
{
    dest->m00 = matrix->m00 * scale->x;
    dest->m01 = matrix->m01 * scale->x;
    dest->m02 = matrix->m02 * scale->x;
    dest->m03 = matrix->m03 * scale->x;

    dest->m10 = matrix->m10 * scale->y;
    dest->m11 = matrix->m11 * scale->y;
    dest->m12 = matrix->m12 * scale->y;
    dest->m13 = matrix->m13 * scale->y;

    dest->m20 = matrix->m20 * scale->z;
    dest->m21 = matrix->m21 * scale->z;
    dest->m22 = matrix->m22 * scale->z;
    dest->m23 = matrix->m23 * scale->z;
}

void
mat4_rotate_d(const t_mat4 *const matrix, const t_vec3 *const euler_axis, t_float angle, t_mat4 *const restrict dest)
{
    t_float cos_angle = cos(angle);
    t_float sin_angle = sin(angle);
    t_float oneminuscos = 1.0 - cos_angle;
    t_float xy = euler_axis->x * euler_axis->y;
    t_float yz = euler_axis->y * euler_axis->z;
    t_float zx = euler_axis->z * euler_axis->x;
    t_float xsin = euler_axis->x * sin_angle;
    t_float ysin = euler_axis->y * sin_angle;
    t_float zsin = euler_axis->z * sin_angle;

    t_float d00 = euler_axis->x * euler_axis->x * oneminuscos + cos_angle;
    t_float d01 = xy * oneminuscos + zsin;
    t_float d02 = zx * oneminuscos - ysin;
    t_float d10 = xy * oneminuscos - zsin;
    t_float d11 = euler_axis->y * euler_axis->y * oneminuscos + cos_angle;
    t_float d12 = yz * oneminuscos + xsin;
    t_float d20 = zx * oneminuscos + ysin;
    t_float d21 = yz * oneminuscos - xsin;
    t_float d22 = euler_axis->z * euler_axis->z * oneminuscos + cos_angle;

    dest->m00 = matrix->m00 * d00 + matrix->m10 * d01 + matrix->m20 * d02;
    dest->m01 = matrix->m01 * d00 + matrix->m11 * d01 + matrix->m21 * d02;
    dest->m02 = matrix->m02 * d00 + matrix->m12 * d01 + matrix->m22 * d02;
    dest->m03 = matrix->m03 * d00 + matrix->m13 * d01 + matrix->m23 * d02;
    dest->m10 = matrix->m00 * d10 + matrix->m10 * d11 + matrix->m20 * d12;
    dest->m11 = matrix->m01 * d10 + matrix->m11 * d11 + matrix->m21 * d12;
    dest->m12 = matrix->m02 * d10 + matrix->m12 * d11 + matrix->m22 * d12;
    dest->m13 = matrix->m03 * d10 + matrix->m13 * d11 + matrix->m23 * d12;
    dest->m20 = matrix->m00 * d20 + matrix->m10 * d21 + matrix->m20 * d22;
    dest->m21 = matrix->m01 * d20 + matrix->m11 * d21 + matrix->m21 * d22;
    dest->m22 = matrix->m02 * d20 + matrix->m12 * d21 + matrix->m22 * d22;
    dest->m23 = matrix->m03 * d20 + matrix->m13 * d21 + matrix->m23 * d22;
}

void
mat4_translate_d(const t_mat4 *const matrix, const t_vec3 *const translation, t_mat4 *const dest)
{
    dest->m30 += matrix->m00 * translation->x + matrix->m10 * translation->y + matrix->m20 * translation->z;
    dest->m31 += matrix->m01 * translation->x + matrix->m11 * translation->y + matrix->m21 * translation->z;
    dest->m32 += matrix->m02 * translation->x + matrix->m12 * translation->y + matrix->m22 * translation->z;
    dest->m33 += matrix->m03 * translation->x + matrix->m13 * translation->y + matrix->m23 * translation->z;
}