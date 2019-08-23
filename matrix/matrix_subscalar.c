#include <matrix.h>

void		matrix_subscalar(t_matrix *const restrict matrix, const float scalar)
{
	size_t			i;
	const size_t	size = matrix->j * matrix->i;

	i = 0;
	while (i < size)
	{
		matrix->mat[i] -= scalar;
		i++;
	}
}

