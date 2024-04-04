#include <matrix.h>
#include <math.h>

t_mat4
mat4_add(const t_mat4 *const matrix_left, const t_mat4 *const matrix_right)
{
    return (t_mat4)
    {
        .m00 = matrix_left->m00 + matrix_right->m00,
        .m01 = matrix_left->m01 + matrix_right->m01,
        .m02 = matrix_left->m02 + matrix_right->m02,
        .m03 = matrix_left->m03 + matrix_right->m03,

        .m10 = matrix_left->m10 + matrix_right->m10,
        .m11 = matrix_left->m11 + matrix_right->m11,
        .m12 = matrix_left->m12 + matrix_right->m12,
        .m13 = matrix_left->m13 + matrix_right->m13,

        .m20 = matrix_left->m20 + matrix_right->m20,
        .m21 = matrix_left->m21 + matrix_right->m21,
        .m22 = matrix_left->m22 + matrix_right->m22,
        .m23 = matrix_left->m23 + matrix_right->m23,

        .m30 = matrix_left->m30 + matrix_right->m30,
        .m31 = matrix_left->m31 + matrix_right->m31,
        .m32 = matrix_left->m32 + matrix_right->m32,
        .m33 = matrix_left->m33 + matrix_right->m33
    };
}

t_mat4
mat4_sub(const t_mat4 *const matrix_left, const t_mat4 *const matrix_right)
{
    return (t_mat4)
    {
        .m00 = matrix_left->m00 - matrix_right->m00,
        .m01 = matrix_left->m01 - matrix_right->m01,
        .m02 = matrix_left->m02 - matrix_right->m02,
        .m03 = matrix_left->m03 - matrix_right->m03,

        .m10 = matrix_left->m10 - matrix_right->m10,
        .m11 = matrix_left->m11 - matrix_right->m11,
        .m12 = matrix_left->m12 - matrix_right->m12,
        .m13 = matrix_left->m13 - matrix_right->m13,

        .m20 = matrix_left->m20 - matrix_right->m20,
        .m21 = matrix_left->m21 - matrix_right->m21,
        .m22 = matrix_left->m22 - matrix_right->m22,
        .m23 = matrix_left->m23 - matrix_right->m23,

        .m30 = matrix_left->m30 - matrix_right->m30,
        .m31 = matrix_left->m31 - matrix_right->m31,
        .m32 = matrix_left->m32 - matrix_right->m32,
        .m33 = matrix_left->m33 - matrix_right->m33
    };
}

t_mat4
mat4_mult(const t_mat4 *const matrix_left, const t_mat4 *const matrix_right)
{
    return (t_mat4)
    {
        .m00 =  matrix_left->m00 * matrix_right->m00 + matrix_left->m10 * matrix_right->m01 +
                matrix_left->m20 * matrix_right->m02 + matrix_left->m30 * matrix_right->m03,
        .m01 =  matrix_left->m01 * matrix_right->m00 + matrix_left->m11 * matrix_right->m01 +
                matrix_left->m21 * matrix_right->m02 + matrix_left->m31 * matrix_right->m03,
        .m02 =  matrix_left->m02 * matrix_right->m00 + matrix_left->m12 * matrix_right->m01 +
                matrix_left->m22 * matrix_right->m02 + matrix_left->m32 * matrix_right->m03,
        .m03 =  matrix_left->m03 * matrix_right->m00 + matrix_left->m13 * matrix_right->m01 +
                matrix_left->m23 * matrix_right->m02 + matrix_left->m33 * matrix_right->m03,

        .m10 =  matrix_left->m00 * matrix_right->m10 + matrix_left->m10 * matrix_right->m11 +
                matrix_left->m20 * matrix_right->m12 + matrix_left->m30 * matrix_right->m13,
        .m11 =  matrix_left->m01 * matrix_right->m10 + matrix_left->m11 * matrix_right->m11 +
                matrix_left->m21 * matrix_right->m12 + matrix_left->m31 * matrix_right->m13,
        .m12 =  matrix_left->m02 * matrix_right->m10 + matrix_left->m12 * matrix_right->m11 +
                matrix_left->m22 * matrix_right->m12 + matrix_left->m32 * matrix_right->m13,
        .m13 =  matrix_left->m03 * matrix_right->m10 + matrix_left->m13 * matrix_right->m11 +
                matrix_left->m23 * matrix_right->m12 + matrix_left->m33 * matrix_right->m13,

        .m20 =  matrix_left->m00 * matrix_right->m20 + matrix_left->m10 * matrix_right->m21 +
                matrix_left->m20 * matrix_right->m22 + matrix_left->m30 * matrix_right->m23,
        .m21 =  matrix_left->m01 * matrix_right->m20 + matrix_left->m11 * matrix_right->m21 +
                matrix_left->m21 * matrix_right->m22 + matrix_left->m31 * matrix_right->m23,
        .m22 =  matrix_left->m02 * matrix_right->m20 + matrix_left->m12 * matrix_right->m21 +
                matrix_left->m22 * matrix_right->m22 + matrix_left->m32 * matrix_right->m23,
        .m23 =  matrix_left->m03 * matrix_right->m20 + matrix_left->m13 * matrix_right->m21 +
                matrix_left->m23 * matrix_right->m22 + matrix_left->m33 * matrix_right->m23,

        .m30 =  matrix_left->m00 * matrix_right->m30 + matrix_left->m10 * matrix_right->m31 +
                matrix_left->m20 * matrix_right->m32 + matrix_left->m30 * matrix_right->m33,
        .m31 =  matrix_left->m01 * matrix_right->m30 + matrix_left->m11 * matrix_right->m31 +
                matrix_left->m21 * matrix_right->m32 + matrix_left->m31 * matrix_right->m33,
        .m32 =  matrix_left->m02 * matrix_right->m30 + matrix_left->m12 * matrix_right->m31 +
                matrix_left->m22 * matrix_right->m32 + matrix_left->m32 * matrix_right->m33,
        .m33 =  matrix_left->m03 * matrix_right->m30 + matrix_left->m13 * matrix_right->m31 +
                matrix_left->m23 * matrix_right->m32 + matrix_left->m33 * matrix_right->m33
    };
}

t_vec4
mat4_trans(const t_mat4 *const matrix, const t_vec4 *const vector)
{
    return vec4
    (
        matrix->m00 * vector->x + matrix->m10 * vector->y + matrix->m20 * vector->z + matrix->m30 * vector->w,
        matrix->m01 * vector->x + matrix->m11 * vector->y + matrix->m21 * vector->z + matrix->m31 * vector->w,
        matrix->m02 * vector->x + matrix->m12 * vector->y + matrix->m22 * vector->z + matrix->m32 * vector->w,
        matrix->m03 * vector->x + matrix->m13 * vector->y + matrix->m23 * vector->z + matrix->m33 * vector->w
    );
}

t_mat4
mat4_transpose(const t_mat4 *const matrix)
{
    return (t_mat4)
    {
        .m00 = matrix->m00,
        .m01 = matrix->m10,
        .m02 = matrix->m20,
        .m03 = matrix->m30,
        .m10 = matrix->m01,
        .m11 = matrix->m11,
        .m12 = matrix->m21,
        .m13 = matrix->m31,
        .m20 = matrix->m02,
        .m21 = matrix->m12,
        .m22 = matrix->m22,
        .m23 = matrix->m32,
        .m30 = matrix->m03,
        .m31 = matrix->m13,
        .m32 = matrix->m23,
        .m33 = matrix->m33
    };
}
void
mat4_set_identity(t_mat4 *const dest_matrix)
{
    dest_matrix->m00 = 1.0;
    dest_matrix->m01 = 0;
    dest_matrix->m02 = 0;
    dest_matrix->m03 = 0;

    dest_matrix->m10 = 0;
    dest_matrix->m11 = 1.0;
    dest_matrix->m12 = 0;
    dest_matrix->m13 = 0;

    dest_matrix->m20 = 0;
    dest_matrix->m21 = 0;
    dest_matrix->m22 = 1.0;
    dest_matrix->m23 = 0;

    dest_matrix->m30 = 0;
    dest_matrix->m31 = 0;
    dest_matrix->m32 = 0;
    dest_matrix->m33 = 1.0;
}

void
mat4_set_zero(t_mat4 *const dest_matrix)
{
    dest_matrix->m00 = 0;
    dest_matrix->m01 = 0;
    dest_matrix->m02 = 0;
    dest_matrix->m03 = 0;

    dest_matrix->m10 = 0;
    dest_matrix->m11 = 0;
    dest_matrix->m12 = 0;
    dest_matrix->m13 = 0;

    dest_matrix->m20 = 0;
    dest_matrix->m21 = 0;
    dest_matrix->m22 = 0;
    dest_matrix->m23 = 0;

    dest_matrix->m30 = 0;
    dest_matrix->m31 = 0;
    dest_matrix->m32 = 0;
    dest_matrix->m33 = 0;
}

t_mat4
mat4_negate(const t_mat4 *const dest_matrix)
{
    return (t_mat4)
    {
        .m00 = -dest_matrix->m00,
        .m01 = -dest_matrix->m01,
        .m02 = -dest_matrix->m02,
        .m03 = -dest_matrix->m03,
        .m10 = -dest_matrix->m10,
        .m11 = -dest_matrix->m11,
        .m12 = -dest_matrix->m12,
        .m13 = -dest_matrix->m13,
        .m20 = -dest_matrix->m20,
        .m21 = -dest_matrix->m21,
        .m22 = -dest_matrix->m22,
        .m23 = -dest_matrix->m23,
        .m30 = -dest_matrix->m30,
        .m31 = -dest_matrix->m31,
        .m32 = -dest_matrix->m32,
        .m33 = -dest_matrix->m33
    };
}

void
mat4_negate_self(t_mat4 *const dest_matrix)
{
    dest_matrix->m00 = -dest_matrix->m00;
    dest_matrix->m01 = -dest_matrix->m01;
    dest_matrix->m02 = -dest_matrix->m02;
    dest_matrix->m03 = -dest_matrix->m03;

    dest_matrix->m10 = -dest_matrix->m10;
    dest_matrix->m11 = -dest_matrix->m11;
    dest_matrix->m12 = -dest_matrix->m12;
    dest_matrix->m13 = -dest_matrix->m13;

    dest_matrix->m20 = -dest_matrix->m20;
    dest_matrix->m21 = -dest_matrix->m21;
    dest_matrix->m22 = -dest_matrix->m22;
    dest_matrix->m23 = -dest_matrix->m23;

    dest_matrix->m30 = -dest_matrix->m30;
    dest_matrix->m31 = -dest_matrix->m31;
    dest_matrix->m32 = -dest_matrix->m32;
    dest_matrix->m33 = -dest_matrix->m33;
}

#define mat3_det_inline(m00, m01, m02, m10, m11, m12, m20, m21, m22) m00 * (m11 * m22 - m12 * m21) + m01 * (m12 * m20 - m10 * m22) + m02 * (m10 * m21 - m11 * m20)

t_mat4
mat4_invert(const t_mat4 *const matrix)
{
    t_float det = mat4_det(matrix);

    if (det != 0)
    {
        t_float det_invert = 1.0 / det;

        return (t_mat4)
        {
            .m00 = mat3_det_inline
            (
                matrix->m11, matrix->m12, matrix->m13,
                matrix->m21, matrix->m22, matrix->m23,
                matrix->m31, matrix->m32, matrix->m33
            ) * det_invert,
            .m01 = -mat3_det_inline
            (
                matrix->m10, matrix->m12, matrix->m13,
                matrix->m20, matrix->m22, matrix->m23,
                matrix->m30, matrix->m32, matrix->m33
            ) * det_invert,
            .m02 = mat3_det_inline
            (
                matrix->m10, matrix->m11, matrix->m13,
                matrix->m20, matrix->m21, matrix->m23,
                matrix->m30, matrix->m31, matrix->m33
            ) * det_invert,
            .m03 = -mat3_det_inline
            (
                matrix->m10, matrix->m11, matrix->m12,
                matrix->m20, matrix->m21, matrix->m22,
                matrix->m30, matrix->m31, matrix->m32
            ) * det_invert,

            .m10 = -mat3_det_inline
            (
                matrix->m01, matrix->m02, matrix->m03,
                matrix->m21, matrix->m22, matrix->m23,
                matrix->m31, matrix->m32, matrix->m33
            ) * det_invert,
            .m11 = mat3_det_inline
            (
                matrix->m00, matrix->m02, matrix->m03,
                matrix->m20, matrix->m22, matrix->m23,
                matrix->m30, matrix->m32, matrix->m33
            ) * det_invert,
            .m12 = -mat3_det_inline
            (
                matrix->m00, matrix->m01, matrix->m03,
                matrix->m20, matrix->m21, matrix->m23,
                matrix->m30, matrix->m31, matrix->m33
            ) * det_invert,
            .m13 = mat3_det_inline
            (
                matrix->m00, matrix->m01, matrix->m02,
                matrix->m20, matrix->m21, matrix->m22,
                matrix->m30, matrix->m31, matrix->m32
            ) * det_invert,

            .m20 = mat3_det_inline
            (
                matrix->m01, matrix->m02, matrix->m03,
                matrix->m11, matrix->m12, matrix->m13,
                matrix->m31, matrix->m32, matrix->m33
            ) * det_invert,
            .m21 = -mat3_det_inline
            (
                matrix->m00, matrix->m02, matrix->m03,
                matrix->m10, matrix->m12, matrix->m13,
                matrix->m30, matrix->m32, matrix->m33
            ) * det_invert,
            .m22 = mat3_det_inline
            (
                matrix->m00, matrix->m01, matrix->m03,
                matrix->m10, matrix->m11, matrix->m13,
                matrix->m30, matrix->m31, matrix->m33
            ) * det_invert,
            .m23 = -mat3_det_inline
            (
                matrix->m00, matrix->m01, matrix->m02,
                matrix->m10, matrix->m11, matrix->m12,
                matrix->m30, matrix->m31, matrix->m32
            ) * det_invert,

            .m30 = -mat3_det_inline
            (
                matrix->m01, matrix->m02, matrix->m03,
                matrix->m11, matrix->m12, matrix->m13,
                matrix->m21, matrix->m22, matrix->m23
            ) * det_invert,
            .m31 = mat3_det_inline
            (
                matrix->m00, matrix->m02, matrix->m03,
                matrix->m10, matrix->m12, matrix->m13,
                matrix->m20, matrix->m22, matrix->m23
            ) * det_invert,
            .m32 = -mat3_det_inline
            (
                matrix->m00, matrix->m01, matrix->m03,
                matrix->m10, matrix->m11, matrix->m13,
                matrix->m20, matrix->m21, matrix->m23
            ) * det_invert,
            .m33 = mat3_det_inline
            (
                matrix->m00, matrix->m01, matrix->m02,
                matrix->m10, matrix->m11, matrix->m12,
                matrix->m20, matrix->m21, matrix->m22
            ) * det_invert
        };
    }

    return *matrix;
}

void
mat4_invert_self(t_mat4 *const matrix)
{
    t_float det = mat4_det(matrix);

    if (det != 0)
    {
        t_float det_invert = 1.0 / det;

        *matrix = (t_mat4)
        {
            .m00 = mat3_det_inline
            (
                matrix->m11, matrix->m12, matrix->m13,
                matrix->m21, matrix->m22, matrix->m23,
                matrix->m31, matrix->m32, matrix->m33
            ) * det_invert,
            .m01 = -mat3_det_inline
            (
                matrix->m10, matrix->m12, matrix->m13,
                matrix->m20, matrix->m22, matrix->m23,
                matrix->m30, matrix->m32, matrix->m33
            ) * det_invert,
            .m02 = mat3_det_inline
            (
                matrix->m10, matrix->m11, matrix->m13,
                matrix->m20, matrix->m21, matrix->m23,
                matrix->m30, matrix->m31, matrix->m33
            ) * det_invert,
            .m03 = -mat3_det_inline
            (
                matrix->m10, matrix->m11, matrix->m12,
                matrix->m20, matrix->m21, matrix->m22,
                matrix->m30, matrix->m31, matrix->m32
            ) * det_invert,

            .m10 = -mat3_det_inline
            (
                matrix->m01, matrix->m02, matrix->m03,
                matrix->m21, matrix->m22, matrix->m23,
                matrix->m31, matrix->m32, matrix->m33
            ) * det_invert,
            .m11 = mat3_det_inline
            (
                matrix->m00, matrix->m02, matrix->m03,
                matrix->m20, matrix->m22, matrix->m23,
                matrix->m30, matrix->m32, matrix->m33
            ) * det_invert,
            .m12 = -mat3_det_inline
            (
                matrix->m00, matrix->m01, matrix->m03,
                matrix->m20, matrix->m21, matrix->m23,
                matrix->m30, matrix->m31, matrix->m33
            ) * det_invert,
            .m13 = mat3_det_inline
            (
                matrix->m00, matrix->m01, matrix->m02,
                matrix->m20, matrix->m21, matrix->m22,
                matrix->m30, matrix->m31, matrix->m32
            ) * det_invert,

            .m20 = mat3_det_inline
            (
                matrix->m01, matrix->m02, matrix->m03,
                matrix->m11, matrix->m12, matrix->m13,
                matrix->m31, matrix->m32, matrix->m33
            ) * det_invert,
            .m21 = -mat3_det_inline
            (
                matrix->m00, matrix->m02, matrix->m03,
                matrix->m10, matrix->m12, matrix->m13,
                matrix->m30, matrix->m32, matrix->m33
            ) * det_invert,
            .m22 = mat3_det_inline
            (
                matrix->m00, matrix->m01, matrix->m03,
                matrix->m10, matrix->m11, matrix->m13,
                matrix->m30, matrix->m31, matrix->m33
            ) * det_invert,
            .m23 = -mat3_det_inline
            (
                matrix->m00, matrix->m01, matrix->m02,
                matrix->m10, matrix->m11, matrix->m12,
                matrix->m30, matrix->m31, matrix->m32
            ) * det_invert,

            .m30 = -mat3_det_inline
            (
                matrix->m01, matrix->m02, matrix->m03,
                matrix->m11, matrix->m12, matrix->m13,
                matrix->m21, matrix->m22, matrix->m23
            ) * det_invert,
            .m31 = mat3_det_inline
            (
                matrix->m00, matrix->m02, matrix->m03,
                matrix->m10, matrix->m12, matrix->m13,
                matrix->m20, matrix->m22, matrix->m23
            ) * det_invert,
            .m32 = -mat3_det_inline
            (
                matrix->m00, matrix->m01, matrix->m03,
                matrix->m10, matrix->m11, matrix->m13,
                matrix->m20, matrix->m21, matrix->m23
            ) * det_invert,
            .m33 = mat3_det_inline
            (
                matrix->m00, matrix->m01, matrix->m02,
                matrix->m10, matrix->m11, matrix->m12,
                matrix->m20, matrix->m21, matrix->m22
            ) * det_invert
        };
    }
}

t_float
mat4_det(const t_mat4 *const matrix)
{
    /* Наш небесный Отец, пусть святится твоё имя.                                                  */
    /* Пусть придёт твоё Царство. Пусть твоя воля исполнится на земле, как она исполняется на небе. */
    /* Дай нам хлеб на этот день                                                                    */
    /* и прости нам наши долги, как и мы простили наших должников.                                  */
    /* Помоги нам не поддаться искушению и избавь нас от Дьявола                                    */
    return matrix->m00 * ((
        matrix->m11 * matrix->m22 * matrix->m33
        + matrix->m12 * matrix->m23 * matrix->m31
        + matrix->m13 * matrix->m21 * matrix->m32
    )
    ) - matrix->m13 * matrix->m22 * matrix->m31
           - matrix->m11 * matrix->m23 * matrix->m32
           - matrix->m12 * matrix->m21 * matrix->m33

           - matrix->m01 * ((
        matrix->m10 * matrix->m22 * matrix->m33
        + matrix->m12 * matrix->m23 * matrix->m30
        + matrix->m13 * matrix->m20 * matrix->m32
    )
    ) - matrix->m13 * matrix->m22 * matrix->m30
           - matrix->m10 * matrix->m23 * matrix->m32
           - matrix->m12 * matrix->m20 * matrix->m33

           + matrix->m02 * ((
        matrix->m10 * matrix->m21 * matrix->m33
        + matrix->m11 * matrix->m23 * matrix->m30
        + matrix->m13 * matrix->m20 * matrix->m31
    )
    ) - matrix->m13 * matrix->m21 * matrix->m30
           - matrix->m10 * matrix->m23 * matrix->m31
           - matrix->m11 * matrix->m20 * matrix->m33

           - matrix->m03 * ((
        matrix->m10 * matrix->m21 * matrix->m32
        + matrix->m11 * matrix->m22 * matrix->m30
        + matrix->m12 * matrix->m20 * matrix->m31
    )
    ) - matrix->m12 * matrix->m21 * matrix->m30
           - matrix->m10 * matrix->m22 * matrix->m31
           - matrix->m11 * matrix->m20 * matrix->m32;
}

void
mat4_scale_self(t_mat4 *const matrix, const t_vec3 *const scale)
{
    matrix->m00 *= scale->x;
    matrix->m01 *= scale->x;
    matrix->m02 *= scale->x;
    matrix->m03 *= scale->x;

    matrix->m10 *= scale->y;
    matrix->m11 *= scale->y;
    matrix->m12 *= scale->y;
    matrix->m13 *= scale->y;

    matrix->m20 *= scale->z;
    matrix->m21 *= scale->z;
    matrix->m22 *= scale->z;
    matrix->m23 *= scale->z;
}

void
mat4_rotate_self(t_mat4 *const matrix, const t_vec3 *const euler_axis, t_float angle)
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

    t_float m00 = matrix->m00 * d00 + matrix->m10 * d01 + matrix->m20 * d02;
    t_float m01 = matrix->m01 * d00 + matrix->m11 * d01 + matrix->m21 * d02;
    t_float m02 = matrix->m02 * d00 + matrix->m12 * d01 + matrix->m22 * d02;
    t_float m03 = matrix->m03 * d00 + matrix->m13 * d01 + matrix->m23 * d02;
    t_float m10 = matrix->m00 * d10 + matrix->m10 * d11 + matrix->m20 * d12;
    t_float m11 = matrix->m01 * d10 + matrix->m11 * d11 + matrix->m21 * d12;
    t_float m12 = matrix->m02 * d10 + matrix->m12 * d11 + matrix->m22 * d12;
    t_float m13 = matrix->m03 * d10 + matrix->m13 * d11 + matrix->m23 * d12;
    matrix->m20 = matrix->m00 * d20 + matrix->m10 * d21 + matrix->m20 * d22;
    matrix->m21 = matrix->m01 * d20 + matrix->m11 * d21 + matrix->m21 * d22;
    matrix->m22 = matrix->m02 * d20 + matrix->m12 * d21 + matrix->m22 * d22;
    matrix->m23 = matrix->m03 * d20 + matrix->m13 * d21 + matrix->m23 * d22;
    matrix->m00 = m00;
    matrix->m01 = m01;
    matrix->m02 = m02;
    matrix->m03 = m03;
    matrix->m10 = m10;
    matrix->m11 = m11;
    matrix->m12 = m12;
    matrix->m13 = m13;
}

void
mat4_translate_self(t_mat4 *const matrix, const t_vec3 *const translation)
{
    matrix->m30 += matrix->m00 * translation->x + matrix->m10 * translation->y + matrix->m20 * translation->z;
    matrix->m31 += matrix->m01 * translation->x + matrix->m11 * translation->y + matrix->m21 * translation->z;
    matrix->m32 += matrix->m02 * translation->x + matrix->m12 * translation->y + matrix->m22 * translation->z;
    matrix->m33 += matrix->m03 * translation->x + matrix->m13 * translation->y + matrix->m23 * translation->z;
}