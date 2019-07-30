#include <quaternion.h>
# include <vector.h>

t_vector*	quat_conjugate_new(t_vector *const quaternion)
{
	return (vector_create(-quaternion->x, -quaternion->y, -quaternion->z, quaternion->w));
}