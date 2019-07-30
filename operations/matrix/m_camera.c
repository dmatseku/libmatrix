#include <operations_matrix.h>
#include <vector_var.h>
#include <matrix.h>

t_matrix*	m_camera(const t_vector pos, const t_vector target, const t_vector up)
{
	const t_vector				camdir = vector_var_normal
											(vector_var_sub(pos, target));
	const t_vector				cright = vector_var_normal
											(vector_var_vmult(up, camdir));
	const t_vector				cup = vector_var_vmult(camdir, cright);
	t_matrix *const restrict	matrix_1 = matrix_create(4, 4);
	t_matrix *const restrict	matrix_2 = matrix_create(4, 4);
	t_matrix*					res;

	if (!matrix_1 || !matrix_2)
		return (0);
	matrix_1->mat[0][0] = cright.x;
	matrix_1->mat[0][1] = cright.y;
	matrix_1->mat[0][2] = cright.z;
	matrix_1->mat[1][0] = cup.x;
	matrix_1->mat[1][1] = cup.y;
	matrix_1->mat[1][2] = cup.z;
	matrix_1->mat[2][0] = camdir.x;
	matrix_1->mat[2][1] = camdir.y;
	matrix_1->mat[2][2] = camdir.z;
	matrix_2->mat[0][3] = -pos.x;
	matrix_2->mat[1][3] = -pos.y;
	matrix_2->mat[2][3] = -pos.z;
	res = matrix_mult(matrix_1, matrix_2);
	matrix_free(matrix_1);
	matrix_free(matrix_2);
	return (res);
}
