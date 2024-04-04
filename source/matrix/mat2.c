#include <matrix.h>

t_mat2
mat2_add(const t_mat2 *const matrix_left, const t_mat2 *const matrix_right)
{
    return (t_mat2)
    {
        .m00 = matrix_left->m00 + matrix_right->m00,
        .m01 = matrix_left->m01 + matrix_right->m01,

        .m10 = matrix_left->m10 + matrix_right->m10,
        .m11 = matrix_left->m11 + matrix_right->m11
    };
}

t_mat2
mat2_sub(const t_mat2 *const matrix_left, const t_mat2 *const matrix_right)
{
    return (t_mat2)
    {
        .m00 = matrix_left->m00 - matrix_right->m00,
        .m01 = matrix_left->m01 - matrix_right->m01,

        .m10 = matrix_left->m10 - matrix_right->m10,
        .m11 = matrix_left->m11 - matrix_right->m11
    };
}

t_mat2
mat2_mult(const t_mat2 *const matrix_left, const t_mat2 *const matrix_right)
{
    return (t_mat2)
    {
        .m00 = matrix_left->m00 * matrix_right->m00 + matrix_left->m10 * matrix_right->m01,
        .m01 = matrix_left->m01 * matrix_right->m00 + matrix_left->m11 * matrix_right->m01,

        .m10 = matrix_left->m00 * matrix_right->m10 + matrix_left->m10 * matrix_right->m11,
        .m11 = matrix_left->m01 * matrix_right->m10 + matrix_left->m11 * matrix_right->m11
    };
}

t_vec2
mat2_trans(const t_mat2 *const matrix, const t_vec2 *const vector)
{
    return vec2
    (
        matrix->m00 * vector->x + matrix->m10 * vector->y,
        matrix->m01 * vector->x + matrix->m11 * vector->y
    );
}

t_mat2
mat2_transpose(const t_mat2 *const matrix)
{
    return (t_mat2)
    {
        .m00 = matrix->m00,
        .m01 = matrix->m10,

        .m10 = matrix->m01,
        .m11 = matrix->m11
    };
}

void
mat2_set_identity(t_mat2 *const matrix)
{
    matrix->m00 = 1.0;
    matrix->m01 = 0;

    matrix->m10 = 0;
    matrix->m11 = 1.0;
}

void
mat2_set_zero(t_mat2 *const matrix)
{
    matrix->m00 = 0;
    matrix->m01 = 0;

    matrix->m10 = 0;
    matrix->m11 = 0;
}

t_mat2
mat2_negate(const t_mat2 *const matrix)
{
    return (t_mat2)
    {
        .m00 = -matrix->m00,
        .m01 = -matrix->m01,

        .m10 = -matrix->m10,
        .m11 = -matrix->m11
    };
}

void
mat2_negate_self(t_mat2 *const matrix)
{
    matrix->m00 = -matrix->m00;
    matrix->m01 = -matrix->m01;

    matrix->m10 = -matrix->m10;
    matrix->m11 = -matrix->m11;
}

t_mat2
mat2_invert(const t_mat2 *const matrix)
{
    t_float det = mat2_det(matrix);

    if (det != 0)
    {
        t_float det_invert = 1.0 / det;

        return (t_mat2)
        {
            .m00 = matrix->m11 * det_invert,
            .m01 = -matrix->m01 * det_invert,

            .m10 = -matrix->m10 * det_invert,
            .m11 = matrix->m00 * det_invert
        };
    }
    return *matrix;
}

void
mat2_invert_self(t_mat2 *const matrix)
{
    t_float det = mat2_det(matrix);

    if (det != 0)
    {
        t_float det_invert = 1.0 / det;
        t_float m00 = matrix->m11 * det_invert;

        matrix->m01 = -matrix->m01 * det_invert;
        matrix->m11 = matrix->m00 * det_invert;

        matrix->m10 = -matrix->m10 * det_invert;
        matrix->m00 = m00;
    }
}

t_float
mat2_det(const t_mat2 *const matrix)
{
    return matrix->m00 * matrix->m01 - matrix->m01 * matrix->m10;
}