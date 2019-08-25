#include <quaternion.h>
#include <vector.h>

t_vector*	quat_reverse_new(t_vector const *const restrict quaternion)
{
	t_vector *const restrict	res = quat_conjugate_new(quaternion);

	if (!res)
		return (0);
	vector_divscalar(res, quat_norm_nosqrt(quaternion));
	return (res);
}
