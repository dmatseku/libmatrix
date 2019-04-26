#include <libmatrix.h>

t_vector	*vector_create(float x, float y, float z, float w)
{
	t_vector	*res;

	CHECK((res = (t_vector*)malloc(sizeof(t_vector))));
	res->x = x;
	res->y = y;
	res->z = z;
	res->w = w;
	return (res);
}