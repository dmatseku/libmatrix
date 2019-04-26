#include <libmatrix.h>

int		matrix_cat(t_matrix *m1, t_matrix *m2)
{
	size_t i;


	if (!m1 || !m2 || m1->i != m2->i || m1->j != m2->j)
		return (0);
	i = 0;
    while (i < m1->i)
    {
        memcpy(m1->mat[i], m2->mat[i], sizeof(float) * m1->j);
    }
	return (1);
}
