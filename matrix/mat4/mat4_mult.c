#include <libmatrix_structs.h>

//0 4  8 12
//1 5  9 13
//2 6 10 14
//3 7 11 15

static float	mult(short int line, short int column,
		float const *const restrict m_1, float const *const restrict m_2)
{
	const float res =
				m_1[0 + line] * m_2[0 + column * 4] +
				m_1[4 + line] * m_2[1 + column * 4] +
				m_1[8 + line] * m_2[2 + column * 4] +
				m_1[12 + line] * m_2[3 + column * 4];

	return (res);
}

t_mat4			mat4_mult(const t_mat4 matrix_1, const t_mat4 matrix_2)
{
	t_mat4 res;

	res.matrix[0] = mult(0, 0, matrix_1.matrix, matrix_2.matrix);
	res.matrix[1] = mult(1, 0, matrix_1.matrix, matrix_2.matrix);
	res.matrix[2] = mult(2, 0, matrix_1.matrix, matrix_2.matrix);
	res.matrix[3] = mult(3, 0, matrix_1.matrix, matrix_2.matrix);

	res.matrix[4] = mult(0, 1, matrix_1.matrix, matrix_2.matrix);
	res.matrix[5] = mult(1, 1, matrix_1.matrix, matrix_2.matrix);
	res.matrix[6] = mult(2, 1, matrix_1.matrix, matrix_2.matrix);
	res.matrix[7] = mult(3, 1, matrix_1.matrix, matrix_2.matrix);

	res.matrix[8] = mult(0, 2, matrix_1.matrix, matrix_2.matrix);
	res.matrix[9] = mult(1, 2, matrix_1.matrix, matrix_2.matrix);
	res.matrix[10] = mult(2, 2, matrix_1.matrix, matrix_2.matrix);
	res.matrix[11] = mult(3, 2, matrix_1.matrix, matrix_2.matrix);

	res.matrix[12] = mult(0, 3, matrix_1.matrix, matrix_2.matrix);
	res.matrix[13] = mult(1, 3, matrix_1.matrix, matrix_2.matrix);
	res.matrix[14] = mult(2, 3, matrix_1.matrix, matrix_2.matrix);
	res.matrix[15] = mult(3, 3, matrix_1.matrix, matrix_2.matrix);
	return (res);
}