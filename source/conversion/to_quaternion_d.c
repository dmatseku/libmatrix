#include <conversion.h>

void
quaternion_from_axis_d(const t_vec3 *const axis, const t_float angle, t_quaternion *const dest)
{
    t_mat4          rotation = mat4;

    mat4_rotate_self(&rotation, axis, angle);
    *dest = quaternion_from_matrix(&rotation);
    quaternion_normalize_self(dest);
}

void
quaternion_from_matrix_d(const t_mat4 *const matrix, t_quaternion *const dest)
{
    t_float sqr;
    t_float tr = matrix->m00 + matrix->m11 + matrix->m22;
    t_float max;

    if (tr >= 0.0)
    {
        sqr = sqrt(tr + 1.0);
        dest->w = sqr / 2;

        sqr = 0.5 / sqr;
        dest->x = (matrix->m21 - matrix->m12) * sqr;
        dest->y = (matrix->m02 - matrix->m20) * sqr;
        dest->z = (matrix->m10 - matrix->m01) * sqr;
    }
    else
    {
        max = fmax(fmax(matrix->m00, matrix->m11), matrix->m22);

        if (max == matrix->m00)
        {
            sqr = sqrt(matrix->m00 - (matrix->m11 + matrix->m22) + 1.0);
            dest->x = sqr / 2;

            sqr = 0.5 / sqr;
            dest->y = (matrix->m01 + matrix->m10) * sqr;
            dest->z = (matrix->m20 + matrix->m02) * sqr;
            dest->w = (matrix->m21 - matrix->m12) * sqr;
        }
        else if (max == matrix->m11)
        {
            sqr = sqrt(matrix->m11 - (matrix->m22 + matrix->m00) + 1.0);
            dest->y = sqr / 2;

            sqr = 0.5 / sqr;
            dest->z = (matrix->m12 + matrix->m21) * sqr;
            dest->x = (matrix->m01 + matrix->m10) * sqr;
            dest->w = (matrix->m02 - matrix->m20) * sqr;
        }
        else
        {
            sqr = sqrt(matrix->m22 - (matrix->m00 + matrix->m11) + 1.0);
            dest->z = sqr / 2;

            sqr = 0.5 / sqr;
            dest->x = (matrix->m20 + matrix->m02) * sqr;
            dest->y = (matrix->m12 + matrix->m21) * sqr;
            dest->w = (matrix->m10 - matrix->m01) * sqr;
        }
    }
}

void
quaternion_from_euler_d(const t_vec3 *const euler, t_quaternion *const dest)
{
    t_float cy = cos(euler->yaw * 0.5);
    t_float sy = sin(euler->yaw * 0.5);
    t_float cp = cos(euler->pitch * 0.5);
    t_float sp = sin(euler->pitch * 0.5);
    t_float cr = cos(euler->roll * 0.5);
    t_float sr = sin(euler->roll * 0.5);

    dest->x = sr * cp * cy - cr * sp * sy;
    dest->y = cr * sp * cy + sr * cp * sy;
    dest->z = cr * cp * sy - sr * sp * cy;
    dest->w = cr * cp * cy + sr * sp * sy;
}
