#include <vector.h>

t_vector*	vector_normal(t_vector *const restrict vector)
{
	const float		m = sqrtf(vector->x * vector->x +
								vector->y * vector->y +
								vector->z * vector->z);
	return (vector_create(vector->x / m, vector->y / m,
						  vector->z / m, vector->w));
}