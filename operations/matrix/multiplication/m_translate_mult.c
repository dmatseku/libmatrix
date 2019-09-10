#include <operations_matrix.h>
#include <matrix.h>

t_matrix*	m_translate_mult(t_matrix *const restrict matrix, const t_vector translate)
{
	t_matrix *restrict			res;
	t_matrix *const restrict	tmp = matrix_create(4, 4);

	if (!tmp)
		return (0);
	tmp->mat[12] = translate.x;
	tmp->mat[13] = translate.y;
	tmp->mat[14] = translate.z;
	res = matrix_mult(matrix, tmp);
	matrix_free(tmp);
	matrix_free(matrix);
	return (res);
}