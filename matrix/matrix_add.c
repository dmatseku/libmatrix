#include <matrix.h>

void	matrix_add(t_matrix *const matrix_1, t_matrix const *const matrix_2)
{
	size_t i;
	const size_t size = matrix_1->j * matrix_1->i;

	i = 0;
	while (i < size)
	{
		matrix_1->mat[i] += matrix_2->mat[i];
		i++;
	}
}