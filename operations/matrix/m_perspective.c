#include <operations_matrix.h>
#include <matrix.h>
#include <math.h>

t_matrix*	m_perspective(const float fov, const float ar,
							const float near, const float far)
{
	const float					top = near * tanf(fov / 2);
	const float					bottom = -top;
	const float					left = bottom * ar;
	const float					right = top	* ar;
	t_matrix *const restrict	res = matrix_create(4, 4);

	if (!res)
		return (0);
	res->mat[0] = 2.0f * near / (right - left);
	res->mat[5] = 2.0f * near / (top - bottom);
	res->mat[10] = (-(far + near)) / (far - near);
	res->mat[2] = (right + left) / (right - left);
	res->mat[6] = (top + bottom) / (top - bottom);
	res->mat[1] = -2.0f * far * near / (far - near);
	res->mat[15] = 0.0f;
	res->mat[14] = -1.0f;
	return (res);
}
