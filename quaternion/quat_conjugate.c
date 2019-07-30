#include <quaternion.h>

void	quat_conjugate(t_vector *const quaternion)
{
	quaternion->x = -quaternion->x;
	quaternion->y = -quaternion->y;
	quaternion->z = -quaternion->z;
}

