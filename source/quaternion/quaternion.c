#include <quaternion.h>
#include <math.h>

t_float
quaternion_length(const t_quaternion *const quaternion)
{
    return sqrt(quaternion->x * quaternion->x + quaternion->y * quaternion->y +
                quaternion->z * quaternion->z + quaternion->w * quaternion->w);
}

t_quaternion
quaternion_mult(const t_quaternion *const quaternion_left, const t_quaternion *const quaternion_right)
{
    return quaternion
    (
        quaternion_left->x * quaternion_right->w + quaternion_left->w * quaternion_right->x +
        quaternion_left->y * quaternion_right->z - quaternion_left->z * quaternion_right->y,

        quaternion_left->y * quaternion_right->w + quaternion_left->w * quaternion_right->y +
        quaternion_left->z * quaternion_right->x - quaternion_left->x * quaternion_right->z,

        quaternion_left->z * quaternion_right->w + quaternion_left->w * quaternion_right->z +
        quaternion_left->x * quaternion_right->y - quaternion_left->y * quaternion_right->x,

        quaternion_left->w * quaternion_right->w - quaternion_left->x * quaternion_right->x -
        quaternion_left->y * quaternion_right->y - quaternion_left->z * quaternion_right->z
    );
}

t_vec3
quaternion_vec3_mult(const t_quaternion *quaternion, const t_vec3 *vector)
{
    t_mat4 trans = quaternion_to_matrix(quaternion);
    t_vec4 vector4 = vec4(vector->x, vector->y, vector->z, 0);
    t_vec4 result = mat4_trans(&trans, &vector4);

    return vec3(result.x, result.y, result.z);
}

t_vec4
quaternion_vec4_mult(const t_quaternion *const quaternion, const t_vec4 *const vector)
{
    t_mat4 trans = quaternion_to_matrix(quaternion);

    return mat4_trans(&trans, vector);
}

t_quaternion
quaternion_from_axis(const t_vec3 *const axis, t_float angle)
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

t_mat4
quaternion_to_matrix(const t_quaternion *const quaternion)
{
    t_float xy = quaternion->x * quaternion->y;
    t_float xz = quaternion->x * quaternion->z;
    t_float xw = quaternion->x * quaternion->w;
    t_float yz = quaternion->y * quaternion->z;
    t_float yw = quaternion->y * quaternion->w;
    t_float zw = quaternion->z * quaternion->w;
    t_float sq_x = quaternion->x * quaternion->x;
    t_float sq_y = quaternion->y * quaternion->y;
    t_float sq_z = quaternion->z * quaternion->z;

    return (t_mat4)
    {
        .m00 = 1 - 2 * (sq_y + sq_z),
        .m01 = 2 * (xy - zw),
        .m02 = 2 * (xz + yw),
        .m03 = 0,
        .m10 = 2 * (xy + zw),
        .m11 = 1 - 2 * (sq_x + sq_z),
        .m12 = 2 * (yz - xw),
        .m13 = 0,
        .m20 = 2 * (xz - yw),
        .m21 = 2 * (yz + zw),
        .m22 = 1 - 2 * (sq_x + sq_y),
        .m23 = 0,
        .m30 = 0,
        .m31 = 0,
        .m32 = 0,
        .m33 = 1
    };
}

t_quaternion
quaternion_slerp(const t_quaternion *const quaternion_left, const t_quaternion *const quaternion_right, t_float blend)
{
    t_quaternion    result;
    t_float         dot = quaternion_left->w * quaternion_right->w + quaternion_left->x * quaternion_right->x + quaternion_left->y * quaternion_right->y + quaternion_left->z * quaternion_right->z;
    t_float         oneminusblend = 1.0 - blend;

    if (dot < 0)
    {
        result = quaternion
        (
            oneminusblend * quaternion_left->x + oneminusblend * -quaternion_right->x,
            oneminusblend * quaternion_left->y + oneminusblend * -quaternion_right->y,
            oneminusblend * quaternion_left->z + oneminusblend * -quaternion_right->z,
            oneminusblend * quaternion_left->w + oneminusblend * -quaternion_right->w
        );
    }
    else
    {
        result = quaternion
        (
            oneminusblend * quaternion_left->x + oneminusblend * quaternion_right->x,
            oneminusblend * quaternion_left->y + oneminusblend * quaternion_right->y,
            oneminusblend * quaternion_left->z + oneminusblend * quaternion_right->z,
            oneminusblend * quaternion_left->w + oneminusblend * quaternion_right->w
        );
    }

    quaternion_normalize_self(&result);
    return result;
}

t_quaternion
quaternion_look_rotation(const t_vec3 *const forward, const t_vec3 *const up)
{
    t_vec3          forward_normalized = vec3_normalize(forward);
    t_vec3          up_normalized = vec3_normalize(up);
    t_vec3          right;
    t_mat4          rotation = mat4;
    t_quaternion    result;

    vec3_cross_d(&forward_normalized, &up_normalized, &right);

    rotation.m00 = right.x;
    rotation.m10 = right.y;
    rotation.m20 = right.z;

    rotation.m01 = up_normalized.x;
    rotation.m11 = up_normalized.y;
    rotation.m21 = up_normalized.z;

    rotation.m02 = forward_normalized.x;
    rotation.m12 = forward_normalized.y;
    rotation.m22 = forward_normalized.z;

    result = quaternion_from_matrix(&rotation);
    quaternion_normalize_self(&result);
    return result;
}

void
quaternion_set_identity(t_quaternion *const dest_quaternion)
{
    dest_quaternion->x = 0;
    dest_quaternion->y = 0;
    dest_quaternion->z = 0;
    dest_quaternion->w = 1;
}

void
quaternion_normalize_self(t_quaternion *const quaternion)
{
    t_float mag = quaternion_length(quaternion);

    if (mag != 0)
    {
        quaternion->x /= mag;
        quaternion->y /= mag;
        quaternion->z /= mag;
        quaternion->w /= mag;
    }
}

void
quaternion_negate_self(t_quaternion *const quaternion)
{
    quaternion->x *= -1;
    quaternion->y *= -1;
    quaternion->z *= -1;
    quaternion->w *= -1;
}

inline static t_vec4
quaternion_hamilton_product_qv(const t_quaternion *const quaternion, const t_vec4 *const vector)
{
    return vec4
    (
        vector->w * quaternion->x + vector->x * quaternion->w + vector->y * quaternion->z - vector->z * quaternion->y,
        vector->w * quaternion->y - vector->x * quaternion->z + vector->y * quaternion->w + vector->z * quaternion->x,
        vector->w * quaternion->z + vector->x * quaternion->y - vector->y * quaternion->x + vector->z * quaternion->w,
        vector->w * quaternion->w - vector->x * quaternion->x - vector->y * quaternion->y - vector->z * quaternion->z
    );
}

inline static t_vec4
quaternion_hamilton_product_vq(const t_vec4 *const vector, const t_quaternion *const quaternion)
{
    return vec4
    (
        quaternion->w * vector->x + quaternion->x * vector->w + quaternion->y * vector->z - quaternion->z * vector->y,
        quaternion->w * vector->y - quaternion->x * vector->z + quaternion->y * vector->w + quaternion->z * vector->x,
        quaternion->w * vector->z + quaternion->x * vector->y - quaternion->y * vector->x + quaternion->z * vector->w,
        quaternion->w * vector->w - quaternion->x * vector->x - quaternion->y * vector->y - quaternion->z * vector->z
    );
}

t_vec4
quaternion_rotate_hamilton(const t_quaternion *const quaternion, const t_vec4 *const vector)
{
    t_quaternion conjugated = quaternion
    (
        -quaternion->x,
        -quaternion->y,
        -quaternion->z,
        quaternion->w
    );
    t_vec4 qv = quaternion_hamilton_product_qv(quaternion, vector);

    return quaternion_hamilton_product_vq(&qv, &conjugated);
}