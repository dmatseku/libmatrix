#include <vector.h>

t_vector*	vector_normal(t_vector *const restrict vector)
{
	const float		m = sqrtf(vector->x * vector->x +
								vector->y * vector->y +
								vector->z * vector->z);
	return ((m ? vector_create(vector->x / m, vector->y / m,
						  vector->z / m, vector->w) :
				 vector_create(vector->x, vector->y,
						   vector->z, vector->w)));
}