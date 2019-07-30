#include <quaternion.h>
#include <math.h>

float	quat_norm(t_vector *const quaternion)
{
	return(sqrtf(quaternion->w * quaternion->w +
			quaternion->x * quaternion->x +
			quaternion->y * quaternion->y +
			quaternion->z * quaternion->z));
}