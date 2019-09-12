#include <matrix.h>

//0 4  8 12  x
//1 5  9 13  y
//2 6 10 14  z
//3 7 11 15  w
t_mat4	mat4_orthographic(const float left, const float right, const float bottom,
							const float top, const float near, const float far)
{
	t_mat4	res;

	res = mat4_init(1);
	res.matrix[0] = 2.0f / (right - left);
	res.matrix[5] =  2.0f / (top - bottom);
	res.matrix[10] = -2.0f / (far - near);
	res.matrix[12] = -((right + left) / (right - left));
	res.matrix[13] = -((top + bottom) / (top - bottom));
	res.matrix[14] = -((far + near) / (far - near));
	return (res);
}