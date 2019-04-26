#include <libmatrix.h>

float	quat_norm(t_vector *quaternion)
{
	return(sqrtf(quaternion->w * quaternion->w +
			quaternion->x * quaternion->x +
			quaternion->y * quaternion->y +
			quaternion->z * quaternion->z));
}