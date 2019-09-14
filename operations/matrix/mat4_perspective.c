#include <libmatrix_structs.h>
#include <matrix.h>
#include <math.h>

//0 4  8 12
//1 5  9 13
//2 6 10 14
//3 7 11 15
t_mat4	mat4_perspective(const float fov, const float ar,
							const float near, const float far)
{
	const float	top = near * tanf(fov / 2);
	const float	bottom = -top;
	const float	left = bottom * ar;
	const float	right = top	* ar;
	t_mat4		res;

	res = mat4_init();
	res.matrix[0] = 2.0f * near / (right - left);
	res.matrix[5] = 2.0f * near / (top - bottom);
	res.matrix[8] = (right + left) / (right - left);
	res.matrix[9] = (top + bottom) / (top - bottom);
	res.matrix[10] = (-(far + near)) / (far - near);
	res.matrix[11] = -1.0f;
	res.matrix[14] = -2.0f * far * near / (far - near);
	res.matrix[15] = 0.0f;
	return (res);
}