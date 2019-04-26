#include <libmatrix.h>

float		vector_smult(t_vector *v1, t_vector *v2)
{
	float res;

	if (!v1 || !v2)
		return (0);
	res = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	return (res);
}
