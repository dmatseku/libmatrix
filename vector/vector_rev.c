#include <vector.h>

void	vector_rev(t_vector *const vector)
{
	vector->x = -vector->x;
	vector->y = -vector->y;
	vector->z = -vector->z;
}
