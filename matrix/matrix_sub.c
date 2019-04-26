#include <libmatrix.h>

int			matrix_sub(t_matrix *m1, t_matrix *m2)
{
	size_t i;
	size_t j;

	if (!m1 || !m2 || m1->i != m2->i || m1->j != m2->j)
		return (0);
	i = 0;
	while (i < m1->i)
	{
		j = 0;
		while (j < m1->j)
		{
			m1->mat[i][j] -= m2->mat[i][j];
			j++;
		}
		i++;
	}
	return (1);
}
