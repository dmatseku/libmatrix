#include <vector_var.h>

float		vector_var_smult(const t_vector vector_1, const t_vector vector_2)
{
	return (vector_1.x * vector_2.x + vector_1.y * vector_2.y + vector_1.z * vector_2.z);
}

