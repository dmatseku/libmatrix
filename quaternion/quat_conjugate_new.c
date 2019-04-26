#include <libmatrix.h>

t_vector	*quat_conjugate_new(t_vector *quaternion, int freeq)
{
	t_vector	*res;

	if (!quaternion)
		return (0);
	CHECK((res = vector_create(-quaternion->x, -quaternion->y, -quaternion->z, quaternion->w)));
	if (freeq)
	{
		FREE(quaternion);
	}
	return (res);
}