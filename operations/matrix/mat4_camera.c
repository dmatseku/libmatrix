#include <libmatrix_structs.h>
#include <vector.h>
#include <matrix.h>

//0 4  8 12
//1 5  9 13
//2 6 10 14
//3 7 11 15
t_mat4	mat4_camera(const t_vec3 pos, const t_vec3 target, const t_vec3 up)
{
	const t_vec3	camdir = vec3_normal
					(vec3_sub(pos, target));
	const t_vec3	cright = vec3_normal
					(vec3_vector_mult(up, camdir));
	const t_vec3	cup = vec3_vector_mult(camdir, cright);
	t_mat4			matrix;

	matrix = mat4_init();

	matrix.matrix[0] = cright.x;
	matrix.matrix[4] = cright.y;
	matrix.matrix[8] = cright.z;
	matrix.matrix[1] = cup.x;
	matrix.matrix[5] = cup.y;
	matrix.matrix[9] = cup.z;
	matrix.matrix[2] = camdir.x;
	matrix.matrix[6] = camdir.y;
	matrix.matrix[10] = camdir.z;

	matrix.matrix[12] = -pos.x * cright.x + -pos.y * cright.y + -pos.z * cright.z;
	matrix.matrix[13] = -pos.x * cup.x + -pos.y * cup.y + -pos.z * cup.z;
	matrix.matrix[14] = -pos.x * camdir.x + -pos.y * camdir.y + -pos.z * camdir.z;

	return (matrix);
}