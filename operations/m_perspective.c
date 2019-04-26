#include<libmatrix.h>

t_matrix	*m_perspective(float fov, float ar, float near, float far)
{
	t_matrix *res;
	t_perspective p;

	p.top = near * tanf(fov / 2);
	p.bottom = -p.top;
	p.right = p.top	* ar;
	p.left = p.bottom * ar;
	CHECK((res = matrix_create(4, 4)));
	res->mat[0][0] = 2.0f * near / (p.right - p.left);
	res->mat[1][1] = 2.0f * near / (p.top - p.bottom);
	res->mat[2][2] = (-(far + near)) / (far - near);
	res->mat[0][2] = (p.right + p.left) / (p.right - p.left);
	res->mat[1][2] = (p.top + p.bottom) / (p.top - p.bottom);
	res->mat[2][3] = -2.0f * far * near / (far - near);
	res->mat[3][3] = 0.0f;
	res->mat[3][2] = -1.0f;
	return (res);
}
