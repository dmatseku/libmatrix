#include <vector_var.h>

t_vector	vector_var_create(const float x, const float y, const float z, const float w)
{
	return ((t_vector){.x = x, .y = y, .z = z, .w = w});
}

