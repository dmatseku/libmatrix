#include <vector.h>

void		vector_addscalar(t_vector *const vector, const float scalar)
{
	vector->x += scalar;
	vector->y += scalar;
	vector->z += scalar;
}
