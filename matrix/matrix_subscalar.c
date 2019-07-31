#include <matrix.h>

void		matrix_subscalar(t_matrix *const restrict matrix, const float scalar)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < matrix->i)
	{
		j = 0;
		while (j < matrix->j)
		{
			matrix->mat[i][j] -= scalar;
			j++;
		}
		i++;
	}
}

