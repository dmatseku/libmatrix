#include <quaternion.h>
#include <math.h>

void
quaternion_mult_d(const t_quaternion *const quaternion_left, const t_quaternion *const quaternion_right, t_quaternion *const restrict dest)
{
    dest->x = quaternion_left->x * quaternion_right->w + quaternion_left->w * quaternion_right->x +
              quaternion_left->y * quaternion_right->z - quaternion_left->z * quaternion_right->y;
    dest->y = quaternion_left->y * quaternion_right->w + quaternion_left->w * quaternion_right->y +
              quaternion_left->z * quaternion_right->x - quaternion_left->x * quaternion_right->z;
    dest->z = quaternion_left->z * quaternion_right->w + quaternion_left->w * quaternion_right->z +
              quaternion_left->x * quaternion_right->y - quaternion_left->y * quaternion_right->x;
    dest->w = quaternion_left->w * quaternion_right->w - quaternion_left->x * quaternion_right->x -
              quaternion_left->y * quaternion_right->y - quaternion_left->z * quaternion_right->z;
}

void
quaternion_vec3_mult_d(const t_quaternion *const quaternion, const t_vec3 *const vector, t_vec3 *const restrict dest)
{
    t_mat4 trans = quaternion_to_matrix(quaternion);
    t_vec4 vector4 = vec4(vector->x, vector->y, vector->z, 0);
    t_vec4 result = mat4_trans(&trans, &vector4);

    dest->x = result.x;
    dest->y = result.y;
    dest->z = result.z;
}

void
quaternion_vec4_mult_d(const t_quaternion *const quaternion, const t_vec4 *const vector, t_vec4 *const restrict dest)
{
    t_mat4 trans = quaternion_to_matrix(quaternion);

    mat4_trans_d(&trans, vector, dest);
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

void
quaternion_to_matrix_d(const t_quaternion *const quaternion, t_mat4 *const dest)
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

    dest->m00 = 1 - 2 * (sq_y + sq_z);
    dest->m01 = 2 * (xy - zw);
    dest->m02 = 2 * (xz + yw);
    dest->m03 = 0;
    dest->m10 = 2 * (xy + zw);
    dest->m11 = 1 - 2 * (sq_x + sq_z);
    dest->m12 = 2 * (yz - xw);
    dest->m13 = 0;
    dest->m20 = 2 * (xz - yw);
    dest->m21 = 2 * (yz + zw);
    dest->m22 = 1 - 2 * (sq_x + sq_y);
    dest->m23 = 0;
    dest->m30 = 0;
    dest->m31 = 0;
    dest->m32 = 0;
    dest->m33 = 1;
}

void
quaternion_slerp_d(const t_quaternion *const quaternion_left, const t_quaternion *const quaternion_right, t_float blend, t_quaternion *const dest)
{
    t_float dot = quaternion_left->w * quaternion_right->w + quaternion_left->x * quaternion_right->x + quaternion_left->y * quaternion_right->y + quaternion_left->z * quaternion_right->z;
    t_float oneminusblend = 1.0 - blend;

    if (dot < 0)
    {
        dest->x = oneminusblend * quaternion_left->x + oneminusblend * -quaternion_right->x;
        dest->y = oneminusblend * quaternion_left->y + oneminusblend * -quaternion_right->y;
        dest->z = oneminusblend * quaternion_left->z + oneminusblend * -quaternion_right->z;
        dest->w = oneminusblend * quaternion_left->w + oneminusblend * -quaternion_right->w;
    }
    else
    {
        dest->x = oneminusblend * quaternion_left->x + oneminusblend * quaternion_right->x;
        dest->y = oneminusblend * quaternion_left->y + oneminusblend * quaternion_right->y;
        dest->z = oneminusblend * quaternion_left->z + oneminusblend * quaternion_right->z;
        dest->w = oneminusblend * quaternion_left->w + oneminusblend * quaternion_right->w;
    }

    quaternion_negate_self(dest);
}

void
quaternion_look_rotation_d(const t_vec3 *forward, const t_vec3 *up, t_quaternion *dest)
{
    t_vec3  forward_normalized = vec3_normalize(forward);
    t_vec3  up_normalized = vec3_normalize(up);
    t_vec3  right;
    t_mat4  rotation = mat4;

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

    quaternion_from_matrix_d(&rotation, dest);
    quaternion_negate_self(dest);
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

void
quaternion_rotate_hamilton_d(const t_quaternion *const quaternion, const t_vec4 *const vector, t_vec4 *const dest)
{
    t_quaternion conjugated = quaternion
    (
        -quaternion->x,
        -quaternion->y,
        -quaternion->z,
        quaternion->w
    );

    *dest = quaternion_hamilton_product_qv(quaternion, vector);
    *dest = quaternion_hamilton_product_vq(dest, &conjugated);
}