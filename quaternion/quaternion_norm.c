#include <libmatrix_structs.h>
#include <math.h>

float	quaternion_norm(const t_vec4 quaternion)
{
	return(sqrtf(quaternion.w * quaternion.w +
				 quaternion.x * quaternion.x +
				 quaternion.y * quaternion.y +
				 quaternion.z * quaternion.z));
}