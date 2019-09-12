#include <libmatrix_structs.h>

float	vec2_scalar_mult(const t_vec2 vector_1, const t_vec2 vector_2)
{
	return (vector_1.x * vector_2.x + vector_1.y * vector_2.y);
}