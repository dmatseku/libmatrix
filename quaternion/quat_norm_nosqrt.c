#include <libmatrix.h>

float	quat_norm_nosqrt(t_vector *quaternion)
{
	return(quaternion->w * quaternion->w +
			quaternion->x * quaternion->x +
			quaternion->y * quaternion->y +
			quaternion->z * quaternion->z);
}