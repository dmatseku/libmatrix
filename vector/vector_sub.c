#include <vector.h>

void	vector_sub(t_vector *const vector_1, t_vector const *const vector_2)
{
	vector_1->x -= vector_2->x;
	vector_1->y -= vector_2->y;
	vector_1->z -= vector_2->z;
}