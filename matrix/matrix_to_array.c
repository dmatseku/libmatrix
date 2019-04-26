#include <libmatrix.h>

float	*matrix_to_array(t_matrix *m)
{
	float *res;
	size_t i;
	size_t j;

	CHECK((res = (float*)malloc(sizeof(float) * m->i * m->j)));
	i = 0;
	while (i < m->i)
	{
		j = 0;
		while (j < m->j)
		{
			res[i * m->i + j] = m->mat[i][j];
			j++;
		}
		i++;
	}
	return (res);
}