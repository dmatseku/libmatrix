#include <matrix.h>

void
mat3_add_d(const t_mat3 *const matrix_left, const t_mat3 *const matrix_right, t_mat3 *const dest)
{
    dest->m00 = matrix_left->m00 + matrix_right->m00;
    dest->m01 = matrix_left->m01 + matrix_right->m01;
    dest->m02 = matrix_left->m02 + matrix_right->m02;

    dest->m10 = matrix_left->m10 + matrix_right->m10;
    dest->m11 = matrix_left->m11 + matrix_right->m11;
    dest->m12 = matrix_left->m12 + matrix_right->m12;

    dest->m20 = matrix_left->m20 + matrix_right->m20;
    dest->m21 = matrix_left->m21 + matrix_right->m21;
    dest->m22 = matrix_left->m22 + matrix_right->m22;
}

void
mat3_sub_d(const t_mat3 *const matrix_left, const t_mat3 *const matrix_right, t_mat3 *const dest)
{
    dest->m00 = matrix_left->m00 - matrix_right->m00;
    dest->m01 = matrix_left->m01 - matrix_right->m01;
    dest->m02 = matrix_left->m02 - matrix_right->m02;

    dest->m10 = matrix_left->m10 - matrix_right->m10;
    dest->m11 = matrix_left->m11 - matrix_right->m11;
    dest->m12 = matrix_left->m12 - matrix_right->m12;

    dest->m20 = matrix_left->m20 - matrix_right->m20;
    dest->m21 = matrix_left->m21 - matrix_right->m21;
    dest->m22 = matrix_left->m22 - matrix_right->m22;
}

void
mat3_mult_d(const t_mat3 *const matrix_left, const t_mat3 *const matrix_right, t_mat3 *const restrict dest)
{
    dest->m00 = matrix_left->m00 * matrix_right->m00 +
                matrix_left->m10 * matrix_right->m01 +
                matrix_left->m20 * matrix_right->m02;
    dest->m01 = matrix_left->m01 * matrix_right->m00 +
                matrix_left->m11 * matrix_right->m01 +
                matrix_left->m21 * matrix_right->m02;
    dest->m02 = matrix_left->m02 * matrix_right->m00 +
                matrix_left->m12 * matrix_right->m01 +
                matrix_left->m22 * matrix_right->m02;

    dest->m10 = matrix_left->m00 * matrix_right->m10 +
                matrix_left->m10 * matrix_right->m11 +
                matrix_left->m20 * matrix_right->m12;
    dest->m11 = matrix_left->m01 * matrix_right->m10 +
                matrix_left->m11 * matrix_right->m11 +
                matrix_left->m21 * matrix_right->m12;
    dest->m12 = matrix_left->m02 * matrix_right->m10 +
                matrix_left->m12 * matrix_right->m11 +
                matrix_left->m22 * matrix_right->m12;

    dest->m20 = matrix_left->m00 * matrix_right->m20 +
                matrix_left->m10 * matrix_right->m21 +
                matrix_left->m20 * matrix_right->m22;
    dest->m21 = matrix_left->m01 * matrix_right->m20 +
                matrix_left->m11 * matrix_right->m21 +
                matrix_left->m21 * matrix_right->m22;
    dest->m22 = matrix_left->m02 * matrix_right->m20 +
                matrix_left->m12 * matrix_right->m21 +
                matrix_left->m22 * matrix_right->m22;
}

void
mat3_trans_d(const t_mat3 *const matrix, const t_vec3 *const restrict vector, t_vec3 *const restrict dest)
{
    dest->x =   matrix->m00 * vector->x +
                matrix->m10 * vector->y +
                matrix->m20 * vector->z;
    dest->y =   matrix->m01 * vector->x +
                matrix->m11 * vector->y +
                matrix->m21 * vector->z;
    dest->z =   matrix->m02 * vector->x +
                matrix->m12 * vector->y +
                matrix->m22 * vector->z;
}

void
mat3_transpose_d(const t_mat3 *const restrict matrix, t_mat3 *const restrict dest)
{
    dest->m00 = matrix->m00;
    dest->m01 = matrix->m10;
    dest->m02 = matrix->m20;

    dest->m10 = matrix->m01;
    dest->m11 = matrix->m11;
    dest->m12 = matrix->m21;

    dest->m20 = matrix->m02;
    dest->m21 = matrix->m12;
    dest->m22 = matrix->m22;
}

void
mat3_negate_d(const t_mat3 *const matrix, t_mat3 *const dest)
{
    dest->m00 = -matrix->m00;
    dest->m01 = -matrix->m01;
    dest->m02 = -matrix->m02;

    dest->m10 = -matrix->m10;
    dest->m11 = -matrix->m11;
    dest->m12 = -matrix->m12;

    dest->m20 = -matrix->m20;
    dest->m21 = -matrix->m21;
    dest->m22 = -matrix->m22;
}

void
mat3_invert_d(const t_mat3 *const restrict matrix, t_mat3 *const restrict dest)
{
    t_float det = mat3_det(matrix);

    if (det != 0)
    {
        t_float det_invert = 1.0 / det;

        dest->m00 = (matrix->m11 * matrix->m22 - matrix->m12 * matrix->m21) * det_invert;
        dest->m01 = (-matrix->m01 * matrix->m22 + matrix->m02 * matrix->m21) * det_invert;
        dest->m02 = (matrix->m01 * matrix->m12 - matrix->m02 * matrix->m11) * det_invert;

        dest->m10 = (-matrix->m10 * matrix->m22 + matrix->m12 * matrix->m20) * det_invert;
        dest->m11 = (matrix->m00 * matrix->m22 - matrix->m02 * matrix->m20) * det_invert;
        dest->m12 = (-matrix->m00 * matrix->m12 + matrix->m02 * matrix->m10) * det_invert;

        dest->m20 = (matrix->m10 * matrix->m21 - matrix->m11 * matrix->m20) * det_invert;
        dest->m21 = (-matrix->m00 * matrix->m21 + matrix->m01 * matrix->m20) * det_invert;
        dest->m22 = (matrix->m00 * matrix->m11 - matrix->m01 * matrix->m10) * det_invert;
    }
    else
    {
        *dest = *matrix;
    }
}