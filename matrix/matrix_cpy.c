#include <matrix.h>

t_matrix*	matrix_cpy(t_matrix const *const restrict matrix)
{
	t_matrix *const restrict	res = matrix_create(matrix->i, matrix->j);
	size_t						i;
	const size_t				size = matrix->j * matrix->i;

	if (!res)
		return (0);
	i = 0;
	while (i < size)
	{
		res->mat[i] = matrix->mat[i];
		i++;
	}
	return (res);
}