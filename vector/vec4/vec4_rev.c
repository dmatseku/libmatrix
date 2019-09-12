#include <libmatrix_structs.h>

t_vec4	vec4_rev(const t_vec4 vector)
{
	return ((t_vec4){.x = -vector.x, .y = -vector.y,
					.z = -vector.z, .w = -vector.w});
}