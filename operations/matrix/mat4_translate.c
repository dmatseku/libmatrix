#include <libmatrix_structs.h>
#include <matrix.h>

t_mat4	mat4_translate(const t_vec3 translate)
{
	t_mat4	res;

	res = mat4_init(1);
	res.matrix[12] = translate.x;
	res.matrix[13] = translate.y;
	res.matrix[14] = translate.z;
	return (res);
}