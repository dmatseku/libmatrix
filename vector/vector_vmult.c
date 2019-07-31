#include <vector.h>

t_vector*	vector_vmult(t_vector *const restrict vector_1, t_vector *const restrict vector_2)
{
	return (vector_create(
			vector_1->y * vector_2->z - vector_1->z * vector_2->y,
			vector_1->z * vector_2->x - vector_1->x * vector_2->z,
			vector_1->x * vector_2->y - vector_1->y * vector_2->x,
			1));
}
