#include <matrix.h>

t_matrix*	matrix_sub_new(t_matrix *const matrix_1, t_matrix *const matrix_2)
{
	size_t			i;
	size_t			j;
	t_matrix *const	res = matrix_create(matrix_1->i, matrix_1->j);

	i = 0;
	while (i < matrix_1->i)
	{
		j = 0;
		while (j < matrix_1->j)
		{
			res->mat[i][j] = matrix_1->mat[i][j] - matrix_2->mat[i][j];
			j++;
		}
		i++;
	}
	return (res);
}