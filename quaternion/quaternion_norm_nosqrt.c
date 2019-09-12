#include <libmatrix_structs.h>

float	quaternion_norm_nosqrt(const t_vec4 quaternion)
{
	return(quaternion.w * quaternion.w +
			quaternion.x * quaternion.x +
			quaternion.y * quaternion.y +
			quaternion.z * quaternion.z);
}