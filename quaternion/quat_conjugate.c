#include <libmatrix.h>

void	quat_conjugate(t_vector *quaternion)
{
	if (quaternion)
	{
		quaternion->x = -quaternion->x;
		quaternion->y = -quaternion->y;
		quaternion->z = -quaternion->z;
	}
}

