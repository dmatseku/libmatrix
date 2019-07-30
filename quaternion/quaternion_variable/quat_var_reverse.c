#include <quaternion_var.h>
#include <vector_var.h>

t_vector	quat_var_reverse(const t_vector quaternion)
{
	return (vector_var_divscalar(quat_var_conjugate(quaternion),
									quat_var_norm_nosqrt(quaternion)));
}

