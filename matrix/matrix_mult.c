#include <libmatrix.h>

static float	mult(size_t i, size_t j, t_matrix *m1, t_matrix *m2)
{
	size_t	tmp1;
	float		res;

	tmp1 = 0;
	res = 0;
	while (tmp1 < m2->j)
	{
		res += (m1->mat[i][tmp1] * m2->mat[tmp1][j]);
		tmp1++;
	}
	return (res);
}

t_matrix		*matrix_mult(t_matrix *m1, t_matrix *m2)
{
	size_t		i;
	size_t		j;
	t_matrix	*res;

	if (!m1 || !m2 || m1->j != m2->i)
		return (0);
	CHECK((res = matrix_create(m1->i, m2->j)));
	i = 0;
	while (i < res->i)
	{
		j = 0;
		while (j < res->j)
		{
			res->mat[i][j] = mult(i, j, m1, m2);
			j++;
		}
		i++;
	}
	return (res);
}