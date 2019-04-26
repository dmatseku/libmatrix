#include <libmatrix.h>

t_vector	*vector_vmult(t_vector *v1, t_vector *v2)
{
	t_vector *res;

	if (!v1 || !v2)
		return (0);
	CHECK((res = vector_create(0, 0, 0, 1)));
	res->x = v1->y * v2->z - v1->z * v2->y;
	res->y = v1->z * v2->x - v1->x * v2->z;
	res->z = v1->x * v2->y - v1->y * v2->x;
	return (res);
}
