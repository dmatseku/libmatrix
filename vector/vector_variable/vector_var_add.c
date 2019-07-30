#include <vector_var.h>

t_vector 	vector_var_add(const t_vector vector_1, const t_vector vector_2)
{
	return ((t_vector){.x = vector_1.x + vector_2.x, .y = vector_1.y + vector_2.y,
						.z = vector_1.z + vector_2.z, .w = vector_1.w});
}

