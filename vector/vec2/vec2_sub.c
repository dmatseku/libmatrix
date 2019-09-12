#include <libmatrix_structs.h>

t_vec2	vec2_sub(const t_vec2 vector_1, const t_vec2 vector_2)
{
	return ((t_vec2){.x = vector_1.x - vector_2.x, .y = vector_1.y - vector_2.y});
}