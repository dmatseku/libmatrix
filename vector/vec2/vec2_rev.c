#include <libmatrix_structs.h>

t_vec2	vec2_rev(const t_vec2 vector)
{
	return ((t_vec2){.x = -vector.x, .y = -vector.y});
}