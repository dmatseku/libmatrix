#include <libmatrix.h>

t_matrix	*matrix_cpy(t_matrix *m)
{
	t_matrix	*res;
	size_t i;


	if (!m)
		return (0);
	CHECK((res = matrix_create(m->i, m->j)));
	i = 0;
	while (i < m->i)
	{
	    memcpy(res->mat[i], m->mat[i], sizeof(float) * m->j);
	}
	return (res);
}