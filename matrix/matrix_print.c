#include <matrix.h>

void	matrix_print(t_matrix *const restrict matrix)
{
	size_t			i;
	const size_t	size = matrix->j * matrix->i;

	i = 0;
	while (i < size)
	{
		if (i && !(i % matrix->j))
			putchar('\n');
		printf("%f   ", matrix->mat[i]);
		i++;
	}
}