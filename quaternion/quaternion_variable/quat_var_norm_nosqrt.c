#include <quaternion_var.h>

float	quat_var_norm_nosqrt(const t_vector quaternion)
{
	return(quaternion.w * quaternion.w +
		   quaternion.x * quaternion.x +
		   quaternion.y * quaternion.y +
		   quaternion.z * quaternion.z);
}