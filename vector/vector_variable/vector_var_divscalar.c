#include <vector_var.h>

t_vector 	vector_var_divscalar(const t_vector vector, const float scalar)
{
	return ((t_vector){.x = vector.x / scalar, .y = vector.y / scalar,
			.z = vector.z / scalar, .w = vector.w});
}
