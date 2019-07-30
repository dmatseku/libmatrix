#include <matrix.h>

void		matrix_addscalar(t_matrix *const matrix, const float scalar)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < matrix->i)
	{
		j = 0;
		while (j < matrix->j)
		{
			matrix->mat[i][j] += scalar;
			j++;
		}
		i++;
	}
}