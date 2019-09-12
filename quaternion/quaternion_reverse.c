#include <libmatrix_structs.h>
#include <quaternion.h>
#include <vector.h>

t_vec4	quaternion_reverse(const t_vec4 quaternion)
{
	return (vec4_div_scalar(quaternion_conjugate(quaternion),
							quaternion_norm_nosqrt(quaternion)));
}