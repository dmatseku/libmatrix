#include <operations_matrix.h>
#include <matrix.h>

t_matrix*	m_orthographic(const float left, const float right, const float bottom,
							const float top, const float near, const float far)
{
	t_matrix *const restrict res = matrix_create(4, 4);

	if (!res)
		return (0);
	res->mat[0][0] = 2.0f / (right - left);
	res->mat[1][1] = 2.0f / (top - bottom);
	res->mat[2][2] = -2.0f / (far - near);
	res->mat[0][3] = -((right + left) / (right - left));
	res->mat[1][3] = -((top + bottom) / (top - bottom));
	res->mat[2][3] = -((far + near) / (far - near));
	return (res);
}