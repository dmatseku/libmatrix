#include <libmatrix.h>

t_vector	*quat_reverse(t_vector *quaternion)
{
	t_vector	*res;

	CHECK((res = quat_conjugate_new(quaternion, 0)));
	vector_divscalar(res, quat_norm_nosqrt(quaternion));
	return (res);
}
