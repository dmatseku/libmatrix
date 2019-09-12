#include <libmatrix_structs.h>

t_vec3	vec3_rev(const t_vec3 vector)
{
	return ((t_vec3){.x = -vector.x, .y = -vector.y,
					.z = -vector.z});
}