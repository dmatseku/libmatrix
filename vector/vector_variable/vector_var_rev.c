#include <vector_var.h>

t_vector	vector_var_rev(const t_vector vector)
{
	return ((t_vector){.x = -vector.x, .y = -vector.y,
							.z = -vector.z, .w = vector.w});
}

