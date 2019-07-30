#include <matrix.h>

void	matrix_print(t_matrix *const matrix)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < matrix->i)
	{
		j = 0;
		while (j < matrix->j)
		{
			printf("%f   ", matrix->mat[i][j]);
			j++;
		}
		putchar('\n');
		i++;
	}
}