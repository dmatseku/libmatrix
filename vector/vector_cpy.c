#include <libmatrix.h>

t_vector	*vector_cpy(t_vector *v1)
{
	t_vector *res;

	if (!v1)
		return (0);
	CHECK((res = vector_create(v1->x, v1->y, v1->z, v1->w)));
	return (res);
}
