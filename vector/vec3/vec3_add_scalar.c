#include <libmatrix_structs.h>

t_vec3	vec3_add_scalar(const t_vec3 vector, const float scalar)
{
	return ((t_vec3){.x = vector.x + scalar, .y = vector.y + scalar,
					.z = vector.z + scalar});
}