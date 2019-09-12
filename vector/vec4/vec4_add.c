#include <libmatrix_structs.h>

t_vec4	vec4_add(const t_vec4 vector_1, const t_vec4 vector_2)
{
	return ((t_vec4){.x = vector_1.x + vector_2.x, .y = vector_1.y + vector_2.y,
					.z = vector_1.z + vector_2.z, .w = vector_1.w + vector_2.w});
}
