#include <quaternion.h>
#include <vector.h>

void	quat_reverse(t_vector *const restrict quaternion)
{
	vector_divscalar(quaternion, quat_norm_nosqrt(quaternion));
}
