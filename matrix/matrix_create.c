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
	matrix_set_unit(res);
	return (res);
}