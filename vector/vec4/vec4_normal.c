#include <libmatrix_structs.h>
#include <math.h>

t_vec4	vec4_normal(const t_vec4 vector)
{
	const float m = sqrtf(vector.x * vector.x + vector.y * vector.y
						  + vector.z * vector.z + vector.w * vector.w);

	return ((t_vec4){.x = vector.x / m, .y = vector.y / m,
					.z = vector.z / m, .w = vector.w / m});
}
