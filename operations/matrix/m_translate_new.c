#include <operations_matrix.h>
#include <matrix.h>

t_matrix*	m_translate_new(const t_vector translate)
{
	t_matrix *const restrict	res = matrix_create(4, 4);

	if (!res)
		return (0);
	res->mat[3][0] = translate.x;
	res->mat[3][1] = translate.y;
	res->mat[3][2] = translate.z;
	return (res);
}

