#include <operations_matrix.h>
#include <matrix.h>

t_matrix*	m_scale(t_matrix *const restrict matrix, const t_vector scale)
{
	t_matrix *restrict			res;
	t_matrix *const restrict	tmp = matrix_create(4, 4);

	if (!tmp)
		return (0);
	tmp->mat[0] = scale.x;
	tmp->mat[5] = scale.y;
	tmp->mat[10] = scale.z;
	res = matrix_mult(matrix, tmp);
	matrix_free(tmp);
	matrix_free(matrix);
	return (res);
}

