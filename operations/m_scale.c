#include <libmatrix.h>

t_matrix	*m_scale(t_matrix *m, t_vector scale)
{
	t_matrix *res;
	t_matrix *tmp;

	CHECK((res = matrix_create(4, 4)));
	res->mat[0][0] = scale.x;
	res->mat[1][1] = scale.y;
	res->mat[2][2] = scale.z;
	tmp = matrix_mult(m, res);
	matrix_free(res);
	matrix_free(m);
	return (tmp);
}

