#include <libmatrix_structs.h>

t_vec3	vec3_vector_mult(const t_vec3 vector_1, const t_vec3 vector_2)
{
	return ((t_vec3)
			{
				.x = vector_1.y * vector_2.z - vector_1.z * vector_2.y,
				.y = vector_1.z * vector_2.x - vector_1.x * vector_2.z,
				.z = vector_1.x * vector_2.y - vector_1.y * vector_2.x,
			});
}
