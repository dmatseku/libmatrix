#include <vector_var.h>

t_vector	vector_var_normal(const t_vector vector)
{
	const float m = sqrtf(vector.x * vector.x + vector.y * vector.y
								+ vector.z * vector.z);

	return ((m ? (t_vector){.x = vector.x / m, .y = vector.y / m,
									.z = vector.z / m, .w = vector.w} : vector));
}