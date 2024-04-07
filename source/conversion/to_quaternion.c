#include <conversion.h>

t_quaternion
quaternion_from_axis(const t_vec3 *const axis, const t_float angle)
{
    t_mat4          rotation = mat4;
    t_quaternion    result;

    mat4_rotate_self(&rotation, axis, angle);
    result = quaternion_from_matrix(&rotation);
    quaternion_normalize_self(&result);

    return result;
}

t_quaternion
quaternion_from_euler(const t_vec3 *const euler)
{
    t_float cy = cos(euler->yaw * 0.5);
    t_float sy = sin(euler->yaw * 0.5);
    t_float cp = cos(euler->pitch * 0.5);
    t_float sp = sin(euler->pitch * 0.5);
    t_float cr = cos(euler->roll * 0.5);
    t_float sr = sin(euler->roll * 0.5);

    return (t_quaternion)
    {
        sr * cp * cy - cr * sp * sy,
        cr * sp * cy + sr * cp * sy,
        cr * cp * sy - sr * sp * cy,
        cr * cp * cy + sr * sp * sy
    };
}

t_quaternion
quaternion_from_matrix(const t_mat4 *const matrix)
{
    t_quaternion    result;
    t_float         sqr;
    t_float         tr = matrix->m00 + matrix->m11 + matrix->m22;
    t_float         max;

    if (tr >= 0.0)
    {
        sqr = sqrt(tr + 1.0);
        result.w = sqr / 2;

        sqr = 0.5 / sqr;
        result.x = (matrix->m21 - matrix->m12) * sqr;
        result.y = (matrix->m02 - matrix->m20) * sqr;
        result.z = (matrix->m10 - matrix->m01) * sqr;
    }
    else
    {
        max = fmax(fmax(matrix->m00, matrix->m11), matrix->m22);

        if (max == matrix->m00)
        {
            sqr = sqrt(matrix->m00 - (matrix->m11 + matrix->m22) + 1.0);
            result.x = sqr / 2;

            sqr = 0.5 / sqr;
            result.y = (matrix->m01 + matrix->m10) * sqr;
            result.z = (matrix->m20 + matrix->m02) * sqr;
            result.w = (matrix->m21 - matrix->m12) * sqr;
        }
        else if (max == matrix->m11)
        {
            sqr = sqrt(matrix->m11 - (matrix->m22 + matrix->m00) + 1.0);
            result.y = sqr / 2;

            sqr = 0.5 / sqr;
            result.z = (matrix->m12 + matrix->m21) * sqr;
            result.x = (matrix->m01 + matrix->m10) * sqr;
            result.w = (matrix->m02 - matrix->m20) * sqr;
        }
        else
        {
            sqr = sqrt(matrix->m22 - (matrix->m00 + matrix->m11) + 1.0);
            result.z = sqr / 2;

            sqr = 0.5 / sqr;
            result.x = (matrix->m20 + matrix->m02) * sqr;
            result.y = (matrix->m12 + matrix->m21) * sqr;
            result.w = (matrix->m10 - matrix->m01) * sqr;
        }
    }

    return result;
}