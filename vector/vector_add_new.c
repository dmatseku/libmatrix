#include <libmatrix.h>

t_vector 	*vector_add_new(t_vector *v1, t_vector *v2, int freev)
{
	t_vector	*res;

	if (!v1 || !v2)
		return (0);
	CHECK((res = vector_create(v1->x, v1->y, v1->z, v1->w)));
	res->x += v2->x;
	res->y += v2->y;
	res->z += v2->z;
	if (freev)
	{
		free(v1);
		free(v2);
	}
	return (res);
}