#include <libmatrix_structs.h>

t_vec4	quaternion_conjugate(const t_vec4 quaternion)
{
	return ((t_vec4){-quaternion.x, -quaternion.y, -quaternion.z, quaternion.w});
}