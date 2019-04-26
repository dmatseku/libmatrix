#include <libmatrix.h>

void	matrix_free(t_matrix *m)
{
	if (!m)
		return ;
	while (m->i--)
		FREE(m->mat[m->i]);
	FREE(m->mat);
	FREE(m);
}
