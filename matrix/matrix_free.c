#include <matrix.h>
#include <stdlib.h>

void	matrix_free(t_matrix *const restrict matrix)
{
	while (matrix->i--)
		free(matrix->mat[matrix->i]);
	free(matrix->mat);
	free(matrix);
}