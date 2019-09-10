#include <operations_matrix.h>
#include <matrix.h>

t_matrix*	m_orthographic(const float left, const float right, const float bottom,
							const float top, const float near, const float far)
{
	t_matrix *const restrict res = matrix_create(4, 4);

	if (!res)
		return (0);
	res->mat[0] = 2.0f / (right - left);
	res->mat[5] = 2.0f / (top - bottom);
	res->mat[10] = -2.0f / (far - near);
	res->mat[3] = -((right + left) / (right - left));
	res->mat[7] = -((top + bottom) / (top - bottom));
	res->mat[11] = -((far + near) / (far - near));
	return (res);
}