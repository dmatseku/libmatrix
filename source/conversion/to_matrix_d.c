#include <conversion.h>

void
matrix_from_quaternion_d(const t_quaternion *const quaternion, t_mat4 *const dest)
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
