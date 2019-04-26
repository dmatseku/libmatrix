#include <libmatrix.h>

int		matrix_multscalar(t_matrix *m, float scalar)
{
	size_t i;
	size_t j;

	if (!m)
		return (0);
	i = 0;
	while (i < m->i)
	{
		j = 0;
		while (j < m->j)
		{
			m->mat[i][j] *= scalar;
			j++;
		}
		i++;
	}
	return (1);
}
