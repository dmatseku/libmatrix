#include <libmatrix.h>

int 	vector_sub(t_vector *v1, t_vector *v2)
{
	if (!v1 || !v2)
		return (0);
	v1->x -= v2->x;
	v1->y -= v2->y;
	v1->z -= v2->z;
	return (1);
}