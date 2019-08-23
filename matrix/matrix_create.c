#include <matrix.h>
#include <stdlib.h>

//i == y, j == x
t_matrix*	matrix_create(size_t i, size_t j)
{
	t_matrix *const restrict	res = (t_matrix*)malloc(sizeof(t_matrix));
	const size_t				size = i * j;

	if (!res || !(res->mat = (float*)malloc(sizeof(float) * size)))
		return (0);
	res->i = i;
	res->j = j;
	i = 0;
	while (i < size)
	{
		res->mat[i] = (i / j == i % j ? 1 : 0);
		i++;
	}
	return (res);
}