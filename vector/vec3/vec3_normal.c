#include <libmatrix_structs.h>
#include <math.h>

t_vec3	vec3_normal(const t_vec3 vector)
{
	const float m = sqrtf(vector.x * vector.x + vector.y * vector.y
						  + vector.z * vector.z);

	return ((t_vec3){.x = vector.x / m, .y = vector.y / m,
					.z = vector.z / m});
}
