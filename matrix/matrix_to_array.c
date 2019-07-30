#include <matrix.h>
#include <stdlib.h>

float*	matrix_to_array(t_matrix *const matrix)
{
	float *const	res = (float*)malloc(sizeof(float) * matrix->i * matrix->j);
	size_t			i;
	size_t			j;

	if (!res)
		return (0);
	i = 0;
	while (i < matrix->i)
	{
		j = 0;
		while (j < matrix->j)
		{
			res[i * matrix->i + j] = matrix->mat[i][j];
			j++;
		}
		i++;
	}
	return (res);
}