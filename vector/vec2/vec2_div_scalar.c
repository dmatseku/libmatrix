#include <libmatrix_structs.h>

t_vec2	vec2_div_scalar(const t_vec2 vector, const float scalar)
{
	return ((t_vec2){.x = vector.x / scalar, .y = vector.y / scalar});
}