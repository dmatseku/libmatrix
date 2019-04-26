#include <libmatrix.h>

int		vector_divscalar(t_vector *v, float scalar)
{
	if (!v)
		return (0);
	v->x /= scalar;
	v->y /= scalar;
	v->z /= scalar;
	return (1);
}
