#include <libmatrix_structs.h>

t_vec2	vec2_add_scalar(const t_vec2 vector, const float scalar)
{
	return ((t_vec2){.x = vector.x + scalar, .y = vector.y + scalar});
}