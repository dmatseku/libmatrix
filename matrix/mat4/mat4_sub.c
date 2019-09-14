#include <libmatrix_structs.h>

t_mat4	mat4_sub(const t_mat4 matrix_1, const t_mat4 matrix_2)
{
	return ((t_mat4)
	{
		.matrix =
		{
			matrix_1.matrix[0] - matrix_2.matrix[0],
			matrix_1.matrix[1] - matrix_2.matrix[1],
			matrix_1.matrix[2] - matrix_2.matrix[2],
			matrix_1.matrix[3] - matrix_2.matrix[3],
			matrix_1.matrix[4] - matrix_2.matrix[4],
			matrix_1.matrix[5] - matrix_2.matrix[5],
			matrix_1.matrix[6] - matrix_2.matrix[6],
			matrix_1.matrix[7] - matrix_2.matrix[7],
			matrix_1.matrix[8] - matrix_2.matrix[8],
			matrix_1.matrix[9] - matrix_2.matrix[9],
			matrix_1.matrix[10] - matrix_2.matrix[10],
			matrix_1.matrix[11] - matrix_2.matrix[11],
			matrix_1.matrix[12] - matrix_2.matrix[12],
			matrix_1.matrix[13] - matrix_2.matrix[13],
			matrix_1.matrix[14] - matrix_2.matrix[14],
			matrix_1.matrix[15] - matrix_2.matrix[15]
		}
	});
}