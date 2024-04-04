#include <matrix.h>

void    mat2_add_d(const t_mat2 *const matrix_left, const t_mat2 *const matrix_right, t_mat2 *const dest)
{
    dest->m00 = matrix_left->m00 + matrix_right->m00;
    dest->m01 = matrix_left->m01 + matrix_right->m01;

    dest->m10 = matrix_left->m10 + matrix_right->m10;
    dest->m11 = matrix_left->m11 + matrix_right->m11;
}

void    mat2_sub_d(const t_mat2 *const matrix_left, const t_mat2 *const matrix_right, t_mat2 *const dest)
{
    dest->m00 = matrix_left->m00 - matrix_right->m00;
    dest->m01 = matrix_left->m01 - matrix_right->m01;

    dest->m10 = matrix_left->m10 - matrix_right->m10;
    dest->m11 = matrix_left->m11 - matrix_right->m11;
}

void    mat2_mult_d(const t_mat2 *const matrix_left, const t_mat2 *const matrix_right, t_mat2 *const restrict dest)
{
    dest->m00 =  matrix_left->m00 * matrix_right->m00 + matrix_left->m10 * matrix_right->m01;
    dest->m01 =  matrix_left->m01 * matrix_right->m00 + matrix_left->m11 * matrix_right->m01;

    dest->m10 =  matrix_left->m00 * matrix_right->m10 + matrix_left->m10 * matrix_right->m11;
    dest->m11 =  matrix_left->m01 * matrix_right->m10 + matrix_left->m11 * matrix_right->m11;
}

void    mat2_trans_d(const t_mat2 *const matrix, const t_vec2 *const restrict vector, t_vec2 *const restrict dest)
{
    dest->x = matrix->m00 * vector->x + matrix->m10 * vector->y;
    dest->y = matrix->m01 * vector->x + matrix->m11 * vector->y;
}

void    mat2_transpose_d(const t_mat2 *const restrict matrix, t_mat2 *const restrict dest)
{
    dest->m00 = matrix->m00;
    dest->m01 = matrix->m10;

    dest->m10 = matrix->m01;
    dest->m11 = matrix->m11;
}

void    mat2_negate_d(const t_mat2 *const matrix, t_mat2 *const dest)
{
    dest->m00 = -matrix->m00;
    dest->m01 = -matrix->m01;

    dest->m10 = -matrix->m10;
    dest->m11 = -matrix->m11;
}

void    mat2_invert_d(const t_mat2 *const restrict matrix, t_mat2 *const restrict dest)
{
    t_float det = mat2_det(matrix);

    if (det != 0)
    {
        t_float det_invert = 1.0 / det;

        dest->m00 = matrix->m11 * det_invert;
        dest->m01 = -matrix->m01 * det_invert;

        dest->m10 = -matrix->m10 * det_invert;
        dest->m11 = matrix->m00 * det_invert;
    }
    else
    {
        *dest = *matrix;
    }
}