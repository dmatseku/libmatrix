#include <matrix.h>
#include <stdlib.h>

t_matrix*	matrix_create(size_t i, size_t j)
{
	t_matrix *const res = (t_matrix*)malloc(sizeof(t_matrix));

	if (!res || !(res->mat = (float**)malloc(sizeof(float*) * i)))
		return (0);
	res->i = i;
	res->j = j;
	i = 0;
	while (i < res->i)
	{
		if (!(res->mat[i] = (float*)malloc(sizeof(float) * j)))
			return (0);
		j = 0;
		while (j < res->j)
		{
			res->mat[i][j] = (i == j ? 1 : 0);
			j++;
		}
		i++;
	}
	return (res);
}