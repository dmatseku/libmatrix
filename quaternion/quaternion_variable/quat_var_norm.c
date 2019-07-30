#include <quaternion_var.h>
#include <math.h>

float	quat_var_norm(const t_vector quaternion)
{
	return(sqrtf(quaternion.w * quaternion.w +
				 quaternion.x * quaternion.x +
				 quaternion.y * quaternion.y +
				 quaternion.z * quaternion.z));
}