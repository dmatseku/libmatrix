#include <libmatrix_structs.h>

float	vec3_scalar_mult(const t_vec3 vector_1, const t_vec3 vector_2)
{
	return (vector_1.x * vector_2.x + vector_1.y * vector_2.y +
			vector_1.z * vector_2.z);
}