#include <matrix.h>

void	matrix_set_unit(t_matrix const *const restrict matrix)
{
	size_t			i;
	const size_t	size = matrix->i * matrix->j;

	i = 0;
	while (i < size)
	{
		matrix->mat[i] = (i / matrix->j == i % matrix->j ? 1 : 0);
		i++;
	}
}