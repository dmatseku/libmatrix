#include <libmatrix_structs.h>

t_vec4	vec4_add_scalar(const t_vec4 vector, const float scalar)
{
	return ((t_vec4){.x = vector.x + scalar, .y = vector.y + scalar,
					.z = vector.z + scalar, .w = vector.w + scalar});
}