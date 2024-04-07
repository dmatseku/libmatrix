#include <quaternion.h>
#include <conversion.h>
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
    t_mat4 trans;
    t_vec4 vector4;
    t_vec4 result;

    matrix_from_quaternion_d(quaternion, &trans);
    vector4 = vec4(vector->x, vector->y, vector->z, 0);
    result = mat4_trans(&trans, &vector4);

    dest->x = result.x;
    dest->y = result.y;
    dest->z = result.z;
}

void
quaternion_vec4_mult_d(const t_quaternion *const quaternion, const t_vec4 *const vector, t_vec4 *const restrict dest)
{
    t_mat4 trans;

    matrix_from_quaternion_d(quaternion, &trans);

    mat4_trans_d(&trans, vector, dest);
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