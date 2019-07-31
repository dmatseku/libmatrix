#include <quaternion_var.h>
#include <vector_var.h>

t_vector	quat_var_conjugate(const t_vector quaternion)
{
	return (vector_var_create(-quaternion.x, -quaternion.y, -quaternion.z, quaternion.w));
}