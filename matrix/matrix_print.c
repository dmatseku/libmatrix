#include <libmatrix.h>

void	matrix_print(t_matrix *m)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < m->i)
	{
		j = 0;
		while (j < m->j)
		{
			printf("%f   ", m->mat[i][j]);
			j++;
		}
		putchar('\n');
		i++;
	}
}