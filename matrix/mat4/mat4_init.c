#include <libmatrix_structs.h>

//0 4  8 12
//1 5  9 13
//2 6 10 14
//3 7 11 15
t_mat4	mat4_init(const char unit)
{
	t_mat4		matrix;
	float		f_unit;

	f_unit = 0.0f;
	if (unit)
		f_unit = 1.0f;
	matrix.matrix[0] = f_unit;
	matrix.matrix[1] = 0.0f;
	matrix.matrix[2] = 0.0f;
	matrix.matrix[3] = 0.0f;
	matrix.matrix[4] = 0.0f;
	matrix.matrix[5] = f_unit;
	matrix.matrix[6] = 0.0f;
	matrix.matrix[7] = 0.0f;
	matrix.matrix[8] = 0.0f;
	matrix.matrix[9] = 0.0f;
	matrix.matrix[10] = f_unit;
	matrix.matrix[11] = 0.0f;
	matrix.matrix[12] = 0.0f;
	matrix.matrix[13] = 0.0f;
	matrix.matrix[14] = 0.0f;
	matrix.matrix[15] = f_unit;
	return (matrix);
}