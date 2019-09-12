#include <operations_matrix.h>
#include <vector_var.h>
#include <matrix.h>

//0 4  8 12
//1 5  9 13
//2 6 10 14
//3 7 11 15
t_matrix*	m_camera(const t_vector pos, const t_vector target, const t_vector up)
{
	const t_vector				camdir = vector_var_normal
											(vector_var_sub(pos, target));
	const t_vector				cright = vector_var_normal
											(vector_var_vmult(up, camdir));
	const t_vector				cup = vector_var_vmult(camdir, cright);
	t_matrix *const restrict	matrix_1 = matrix_create(4, 4);
	t_matrix *const restrict	matrix_2 = matrix_create(4, 4);
	t_matrix *restrict			res;

	if (!matrix_1 || !matrix_2)
		return (0);
	matrix_1->mat[0] = cright.x;
	matrix_1->mat[4] = cright.y;
	matrix_1->mat[8] = cright.z;
	matrix_1->mat[1] = cup.x;
	matrix_1->mat[5] = cup.y;
	matrix_1->mat[9] = cup.z;
	matrix_1->mat[2] = camdir.x;
	matrix_1->mat[6] = camdir.y;
	matrix_1->mat[10] = camdir.z;
	matrix_2->mat[12] = -pos.x;
	matrix_2->mat[13] = -pos.y;
	matrix_2->mat[14] = -pos.z;
	res = matrix_mult(matrix_1, matrix_2);
	matrix_free(matrix_1);
	matrix_free(matrix_2);
	return (res);
}
