#include <libmatrix.h>

int 	vector_rev(t_vector *v)
{
	if (!v)
		return (0);
	v->x = -v->x;
	v->y = -v->y;
	v->z = -v->z;
	return (1);
}
