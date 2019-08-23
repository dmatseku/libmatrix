#include <operations_matrix.h>
#include <matrix.h>

t_matrix*	m_scale_new(const t_vector scale)
{
	t_matrix *const restrict	res = matrix_create(4, 4);

	if (!res)
		return (0);
	res->mat[0] = scale.x;
	res->mat[5] = scale.y;
	res->mat[10] = scale.z;
	return (res);
}
