#include <libmatrix.h>

t_vector	*vector_normal(t_vector *v, int freev)
{
	t_vector *res;
	float m;

	if (!v)
		return (0);
	m = sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
	CHECK((res = vector_create(v->x / m, v->y / m, v->z / m, v->w)));
	if (freev)
		FREE(v);
	return (res);
}
