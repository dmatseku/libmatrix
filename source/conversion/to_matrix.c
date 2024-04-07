#include <conversion.h>

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