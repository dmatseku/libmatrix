#include <vector.h>

t_vector*	vector_cpy(t_vector const *const restrict vector)
{
	return (vector_create(vector->x, vector->y, vector->z, vector->w));
}
