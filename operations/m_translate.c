#include <libmatrix.h>

t_matrix	*m_translate(t_matrix *m, t_vector translate)
{
	t_matrix *res;
	t_matrix *tmp;

	CHECK((res = matrix_create(4, 4)));
	res->mat[0][3] = translate.x;
	res->mat[1][3] = translate.y;
	res->mat[2][3] = translate.z;
	tmp = matrix_mult(m, res);
	matrix_free(res);
	matrix_free(m);
	return (tmp);
}