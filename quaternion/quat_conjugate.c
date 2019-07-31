#include <quaternion.h>

void	quat_conjugate(t_vector *const restrict quaternion)
{
	quaternion->x = -quaternion->x;
	quaternion->y = -quaternion->y;
	quaternion->z = -quaternion->z;
}

