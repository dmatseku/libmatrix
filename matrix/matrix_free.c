#include <matrix.h>
#include <stdlib.h>

void	matrix_free(t_matrix *const restrict matrix)
{
	free(matrix->mat);
	free(matrix);
}
