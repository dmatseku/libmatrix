#include <vector.h>

t_vector*	vector_cpy(t_vector *const vector)
{
	return (vector_create(vector->x, vector->y, vector->z, vector->w));
}
