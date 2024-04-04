#include <matrix.h>

t_mat3
mat3_add(const t_mat3 *const matrix_left, const t_mat3 *const matrix_right)
{
    return (t_mat3)
    {
        .m00 = matrix_left->m00 + matrix_right->m00,
        .m01 = matrix_left->m01 + matrix_right->m01,
        .m02 = matrix_left->m02 + matrix_right->m02,

        .m10 = matrix_left->m10 + matrix_right->m10,
        .m11 = matrix_left->m11 + matrix_right->m11,
        .m12 = matrix_left->m12 + matrix_right->m12,

        .m20 = matrix_left->m20 + matrix_right->m20,
        .m21 = matrix_left->m21 + matrix_right->m21,
        .m22 = matrix_left->m22 + matrix_right->m22
    };
}

t_mat3
mat3_sub(const t_mat3 *const matrix_left, const t_mat3 *const matrix_right)
{
    return (t_mat3)
    {
        .m00 = matrix_left->m00 - matrix_right->m00,
        .m01 = matrix_left->m01 - matrix_right->m01,
        .m02 = matrix_left->m02 - matrix_right->m02,

        .m10 = matrix_left->m10 - matrix_right->m10,
        .m11 = matrix_left->m11 - matrix_right->m11,
        .m12 = matrix_left->m12 - matrix_right->m12,

        .m20 = matrix_left->m20 - matrix_right->m20,
        .m21 = matrix_left->m21 - matrix_right->m21,
        .m22 = matrix_left->m22 - matrix_right->m22
    };
}

t_mat3
mat3_mult(const t_mat3 *const matrix_left, const t_mat3 *const matrix_right)
{
    return (t_mat3)
    {
        .m00 =  matrix_left->m00 * matrix_right->m00 +
                matrix_left->m10 * matrix_right->m01 +
                matrix_left->m20 * matrix_right->m02,
        .m01 =  matrix_left->m01 * matrix_right->m00 +
                matrix_left->m11 * matrix_right->m01 +
                matrix_left->m21 * matrix_right->m02,
        .m02 =  matrix_left->m02 * matrix_right->m00 +
                matrix_left->m12 * matrix_right->m01 +
                matrix_left->m22 * matrix_right->m02,

        .m10 =  matrix_left->m00 * matrix_right->m10 +
                matrix_left->m10 * matrix_right->m11 +
                matrix_left->m20 * matrix_right->m12,
        .m11 =  matrix_left->m01 * matrix_right->m10 +
                matrix_left->m11 * matrix_right->m11 +
                matrix_left->m21 * matrix_right->m12,
        .m12 =  matrix_left->m02 * matrix_right->m10 +
                matrix_left->m12 * matrix_right->m11 +
                matrix_left->m22 * matrix_right->m12,

        .m20 =  matrix_left->m00 * matrix_right->m20 +
                matrix_left->m10 * matrix_right->m21 +
                matrix_left->m20 * matrix_right->m22,
        .m21 =  matrix_left->m01 * matrix_right->m20 +
                matrix_left->m11 * matrix_right->m21 +
                matrix_left->m21 * matrix_right->m22,
        .m22 =  matrix_left->m02 * matrix_right->m20 +
                matrix_left->m12 * matrix_right->m21 +
                matrix_left->m22 * matrix_right->m22
    };
}

t_vec3
mat3_trans(const t_mat3 *const matrix, const t_vec3 *const vector)
{
    return vec3
    (
        matrix->m00 * vector->x + matrix->m10 * vector->y + matrix->m20 * vector->z,
        matrix->m01 * vector->x + matrix->m11 * vector->y + matrix->m21 * vector->z,
        matrix->m02 * vector->x + matrix->m12 * vector->y + matrix->m22 * vector->z
    );
}

t_mat3
mat3_transpose(const t_mat3 *const matrix)
{
    return (t_mat3)
    {
        .m00 = matrix->m00,
        .m01 = matrix->m10,
        .m02 = matrix->m20,

        .m10 = matrix->m01,
        .m11 = matrix->m11,
        .m12 = matrix->m21,

        .m20 = matrix->m02,
        .m21 = matrix->m12,
        .m22 = matrix->m22
    };
}

void
mat3_set_identity(t_mat3 *const matrix)
{
    matrix->m00 = 1.0;
    matrix->m01 = 0;
    matrix->m02 = 0;

    matrix->m10 = 0;
    matrix->m11 = 1.0;
    matrix->m12 = 0;

    matrix->m20 = 0;
    matrix->m21 = 0;
    matrix->m22 = 1.0;
}

void
mat3_set_zero(t_mat3 *const matrix)
{
    matrix->m00 = 0;
    matrix->m01 = 0;
    matrix->m02 = 0;

    matrix->m10 = 0;
    matrix->m11 = 0;
    matrix->m12 = 0;

    matrix->m20 = 0;
    matrix->m21 = 0;
    matrix->m22 = 0;
}

t_mat3
mat3_negate(const t_mat3 *const matrix)
{
    return (t_mat3)
    {
        .m00 = -matrix->m00,
        .m01 = -matrix->m01,
        .m02 = -matrix->m02,

        .m10 = -matrix->m10,
        .m11 = -matrix->m11,
        .m12 = -matrix->m12,

        .m20 = -matrix->m20,
        .m21 = -matrix->m21,
        .m22 = -matrix->m22
    };
}

void
mat3_negate_self(t_mat3 *const matrix)
{
    matrix->m00 = -matrix->m00;
    matrix->m01 = -matrix->m01;
    matrix->m02 = -matrix->m02;

    matrix->m10 = -matrix->m10;
    matrix->m11 = -matrix->m11;
    matrix->m12 = -matrix->m12;

    matrix->m20 = -matrix->m20;
    matrix->m21 = -matrix->m21;
    matrix->m22 = -matrix->m22;
}

t_mat3
mat3_invert(const t_mat3 *const matrix)
{
    t_float det = mat3_det(matrix);

    if (det != 0)
    {
        t_float det_invert = 1.0 / det;

        return (t_mat3)
        {
            .m00 = (matrix->m11 * matrix->m22 - matrix->m12 * matrix->m21) * det_invert,
            .m01 = (-matrix->m01 * matrix->m22 + matrix->m02 * matrix->m21) * det_invert,
            .m02 = (matrix->m01 * matrix->m12 - matrix->m02 * matrix->m11) * det_invert,

            .m10 = (-matrix->m10 * matrix->m22 + matrix->m12 * matrix->m20) * det_invert,
            .m11 = (matrix->m00 * matrix->m22 - matrix->m02 * matrix->m20) * det_invert,
            .m12 = (-matrix->m00 * matrix->m12 + matrix->m02 * matrix->m10) * det_invert,

            .m20 = (matrix->m10 * matrix->m21 - matrix->m11 * matrix->m20) * det_invert,
            .m21 = (-matrix->m00 * matrix->m21 + matrix->m01 * matrix->m20) * det_invert,
            .m22 = (matrix->m00 * matrix->m11 - matrix->m01 * matrix->m10) * det_invert
        };
    }
    return *matrix;
}

void
mat3_invert_self(t_mat3 *const matrix)
{
    t_float det = mat3_det(matrix);

    if (det != 0)
    {
        t_float det_invert = 1.0 / det;

        *matrix = (t_mat3)
        {
            .m00 = (matrix->m11 * matrix->m22 - matrix->m12 * matrix->m21) * det_invert,
            .m01 = (-matrix->m01 * matrix->m22 + matrix->m02 * matrix->m21) * det_invert,
            .m02 = (matrix->m01 * matrix->m12 - matrix->m02 * matrix->m11) * det_invert,

            .m10 = (-matrix->m10 * matrix->m22 + matrix->m12 * matrix->m20) * det_invert,
            .m11 = (matrix->m00 * matrix->m22 - matrix->m02 * matrix->m20) * det_invert,
            .m12 = (-matrix->m00 * matrix->m12 + matrix->m02 * matrix->m10) * det_invert,

            .m20 = (matrix->m10 * matrix->m21 - matrix->m11 * matrix->m20) * det_invert,
            .m21 = (-matrix->m00 * matrix->m21 + matrix->m01 * matrix->m20) * det_invert,
            .m22 = (matrix->m00 * matrix->m11 - matrix->m01 * matrix->m10) * det_invert
        };
    }
}

t_float
mat3_det(const t_mat3 *const matrix)
{
    return matrix->m00 * (matrix->m11 * matrix->m22 - matrix->m12 * matrix->m21)
           + matrix->m01 * (matrix->m12 * matrix->m20 - matrix->m10 * matrix->m22)
           + matrix->m02 * (matrix->m10 * matrix->m21 - matrix->m11 * matrix->m20);
}