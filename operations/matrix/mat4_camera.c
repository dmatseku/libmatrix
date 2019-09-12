#include <libmatrix_structs.h>
#include <vector.h>
#include <matrix.h>

t_mat4	mat4_camera(const t_vec3 pos, const t_vec3 target, const t_vec3 up)
{
	const t_vec3	camdir = vec3_normal
					(vec3_sub(pos, target));
	const t_vec3	cright = vec3_normal
					(vec3_vector_mult(up, camdir));
	const t_vec3	cup = vec3_vector_mult(camdir, cright);
	t_mat4			matrix_1;
	t_mat4			matrix_2;
	t_mat4			res;

	matrix_1 = mat4_init(1);
	matrix_2 = mat4_init(1);
	matrix_1.matrix[0] = cright.x;
	matrix_1.matrix[4] = cright.y;
	matrix_1.matrix[8] = cright.z;
	matrix_1.matrix[1] = cup.x;
	matrix_1.matrix[5] = cup.y;
	matrix_1.matrix[9] = cup.z;
	matrix_1.matrix[2] = camdir.x;
	matrix_1.matrix[6] = camdir.y;
	matrix_1.matrix[10] = camdir.z;
	matrix_2.matrix[12] = -pos.x;
	matrix_2.matrix[13] = -pos.y;
	matrix_2.matrix[14] = -pos.z;
	res = mat4_mult(matrix_1, matrix_2);
	return (res);
}