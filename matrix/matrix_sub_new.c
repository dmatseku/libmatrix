#include <libmatrix.h>

t_matrix	*matrix_sub_new(t_matrix *m1, t_matrix *m2, int freem)
{
	size_t i;
	size_t j;
	t_matrix *res;

	if (!m1 || !m2 || m1->i != m2->i || m1->j != m2->j)
		return (0);
	CHECK((res = matrix_create(m1->i, m1->j)));
	i = 0;
	while (i < m1->i)
	{
		j = 0;
		while (j < m1->j)
		{
			res->mat[i][j] = m1->mat[i][j] - m2->mat[i][j];
			j++;
		}
		i++;
	}
	if (freem)
	{
		matrix_free(m1);
		matrix_free(m2);
	}
	return (res);
}