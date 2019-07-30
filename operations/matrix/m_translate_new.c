#include <operations_matrix.h>
#include <matrix.h>

t_matrix*	m_translate_new(const t_vector translate)
{
	t_matrix *const restrict	res = matrix_create(4, 4);

	if (!res)
		return (0);
	res->mat[0][3] = translate.x;
	res->mat[1][3] = translate.y;
	res->mat[2][3] = translate.z;
	return (res);
}

