#include <matrix.h>

t_matrix*	matrix_sub_new(t_matrix *const restrict matrix_1, t_matrix *const restrict matrix_2)
{
	t_matrix *const restrict	res = matrix_create(matrix_1->i, matrix_1->j);
	size_t						i;
	const size_t				size = matrix_1->j * matrix_1->i;

	i = 0;
	while (i < size)
	{
		res->mat[i] = matrix_1->mat[i] - matrix_2->mat[i];
		i++;
	}
	return (res);
}