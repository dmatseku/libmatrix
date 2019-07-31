#include <vector.h>

t_vector*	vector_create(const float x, const float y, const float z, const float w)
{
	t_vector *const restrict	res = (t_vector*)malloc(sizeof(t_vector));

	if (!res)
		return (0);
	res->x = x;
	res->y = y;
	res->z = z;
	res->w = w;
	return (res);
}