#include <libmatrix_structs.h>
#include <matrix.h>

t_mat4	mat4_scale(const t_vec3 scale)
{
	t_mat4	res;

	res = mat4_init();
	res.matrix[0] = scale.x;
	res.matrix[5] = scale.y;
	res.matrix[10] = scale.z;
	return (res);
}
