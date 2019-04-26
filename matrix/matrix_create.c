#include <libmatrix.h>

t_matrix	*matrix_create(size_t i, size_t j)
{
	t_matrix *res;

	if (!i || !j)
		return (0);
	CHECK((res = (t_matrix*)malloc(sizeof(t_matrix))));
	res->i = i;
	res->j = j;
	res->mat = (float**)malloc(sizeof(float*) * i);
	i = 0;
	while (i < res->i)
	{
		res->mat[i] = (float*)malloc(sizeof(float) * j);
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