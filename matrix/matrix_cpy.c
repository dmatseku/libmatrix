#include <matrix.h>

t_matrix*	matrix_cpy(t_matrix *const restrict matrix)
{
	t_matrix *const restrict	res = matrix_create(matrix->i, matrix->j);
	size_t						i;
	size_t						j;

	if (!res)
		return (0);
	i = 0;
	while (i < matrix->i)
	{
		j = 0;
		while (j < matrix->j)
		{
			res->mat[i][j] = matrix->mat[i][j];
			j++;
		}
		i++;
	}
	return (res);
}