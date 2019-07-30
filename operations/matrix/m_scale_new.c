#include <operations_matrix.h>
#include <matrix.h>

t_matrix*	m_scale_new(const t_vector scale)
{
	t_matrix *const restrict	res = matrix_create(4, 4);

	if (!res)
		return (0);
	res->mat[0][0] = scale.x;
	res->mat[1][1] = scale.y;
	res->mat[2][2] = scale.z;
	return (res);
}
