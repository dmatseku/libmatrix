#include<libmatrix.h>

t_matrix	*m_orthographic(float left, float right, float bottom, float top, float near, float far)
{
	t_matrix *res;

	CHECK((res = matrix_create(4, 4)));
	res->mat[0][0] = 2.0f / (right - left);
	res->mat[1][1] = 2.0f / (top - bottom);
	res->mat[2][2] = -2.0f / (far - near);
	res->mat[0][3] = -((right + left) / (right - left));
	res->mat[1][3] = -((top + bottom) / (top - bottom));
	res->mat[2][3] = -((far + near) / (far - near));
	return (res);
}