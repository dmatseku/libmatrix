#include <vector_var.h>

t_vector	vector_var_vmult(const t_vector vector_1, const t_vector vector_2)
{
	return ((t_vector)
		{
			.x = vector_1.y * vector_2.z - vector_1.z * vector_2.y,
			.y = vector_1.z * vector_2.x - vector_1.x * vector_2.z,
			.z = vector_1.x * vector_2.y - vector_1.y * vector_2.x,
			.w = 1.0f
		});
}