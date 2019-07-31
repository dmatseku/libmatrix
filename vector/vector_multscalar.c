#include <vector.h>

void		vector_multscalar(t_vector *const restrict vector, const float scalar)
{
	vector->x *= scalar;
	vector->y *= scalar;
	vector->z *= scalar;
}

