#include <libmatrix_structs.h>
#include <math.h>

t_vec2	vec2_normal(const t_vec2 vector)
{
	const float m = sqrtf(vector.x * vector.x + vector.y * vector.y);

	return ((t_vec2){.x = vector.x / m, .y = vector.y / m});
}
