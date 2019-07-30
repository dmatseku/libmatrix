#include <matrix.h>

static float	mult(const size_t i, const size_t j,
				t_matrix *const matrix_1, t_matrix *const matrix_2)
{
	size_t	tmp1;
	float	res;

	tmp1 = 0;
	res = 0;
	while (tmp1 < matrix_2->j)
	{
		res += (matrix_1->mat[i][tmp1] * matrix_2->mat[tmp1][j]);
		tmp1++;
	}
	return (res);
}

t_matrix*		matrix_mult(t_matrix *const matrix_1, t_matrix *const matrix_2)
{
	size_t			i;
	size_t			j;
	t_matrix *const	res = matrix_create(matrix_1->i, matrix_2->j);

	if (!res)
		return (0);
	i = 0;
	while (i < res->i)
	{
		j = 0;
		while (j < res->j)
		{
			res->mat[i][j] = mult(i, j, matrix_1, matrix_2);
			j++;
		}
		i++;
	}
	return (res);
}