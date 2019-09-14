#include <libmatrix_structs.h>

//0 4  8 12   0 4  8 12
//1 5  9 13   1 5  9 13
//2 6 10 14   2 6 10 14
//3 7 11 15   3 7 11 15

t_mat4			mat4_mult(const t_mat4 matrix_1, const t_mat4 matrix_2)
{
	return ((t_mat4)
	{
		.matrix =
		{
			//[0, 0]
			matrix_1.matrix[0] * matrix_2.matrix[0] +
			matrix_1.matrix[4] * matrix_2.matrix[1] +
			matrix_1.matrix[8] * matrix_2.matrix[2] +
			matrix_1.matrix[12] * matrix_2.matrix[3],

			//[1, 0]
			matrix_1.matrix[1] * matrix_2.matrix[0] +
			matrix_1.matrix[5] * matrix_2.matrix[1] +
			matrix_1.matrix[9] * matrix_2.matrix[2] +
			matrix_1.matrix[13] * matrix_2.matrix[3],

			//[2, 0]
			matrix_1.matrix[2] * matrix_2.matrix[0] +
			matrix_1.matrix[6] * matrix_2.matrix[1] +
			matrix_1.matrix[10] * matrix_2.matrix[2] +
			matrix_1.matrix[14] * matrix_2.matrix[3],

			//[3, 0]
			matrix_1.matrix[3] * matrix_2.matrix[0] +
			matrix_1.matrix[7] * matrix_2.matrix[1] +
			matrix_1.matrix[11] * matrix_2.matrix[2] +
			matrix_1.matrix[15] * matrix_2.matrix[3],


			//[0, 3]
			matrix_1.matrix[0] * matrix_2.matrix[4] +
			matrix_1.matrix[4] * matrix_2.matrix[5] +
			matrix_1.matrix[8] * matrix_2.matrix[6] +
			matrix_1.matrix[12] * matrix_2.matrix[7],

			//[1, 3]
			matrix_1.matrix[1] * matrix_2.matrix[4] +
			matrix_1.matrix[5] * matrix_2.matrix[5] +
			matrix_1.matrix[9] * matrix_2.matrix[6] +
			matrix_1.matrix[13] * matrix_2.matrix[7],

			//[2, 3]
			matrix_1.matrix[2] * matrix_2.matrix[4] +
			matrix_1.matrix[6] * matrix_2.matrix[5] +
			matrix_1.matrix[10] * matrix_2.matrix[6] +
			matrix_1.matrix[14] * matrix_2.matrix[7],

			//[3, 3]
			matrix_1.matrix[3] * matrix_2.matrix[4] +
			matrix_1.matrix[7] * matrix_2.matrix[5] +
			matrix_1.matrix[11] * matrix_2.matrix[6] +
			matrix_1.matrix[15] * matrix_2.matrix[7],


			//[0, 2]
			matrix_1.matrix[0] * matrix_2.matrix[8] +
			matrix_1.matrix[4] * matrix_2.matrix[9] +
			matrix_1.matrix[8] * matrix_2.matrix[10] +
			matrix_1.matrix[12] * matrix_2.matrix[11],

			//[1, 2]
			matrix_1.matrix[1] * matrix_2.matrix[8] +
			matrix_1.matrix[5] * matrix_2.matrix[9] +
			matrix_1.matrix[9] * matrix_2.matrix[10] +
			matrix_1.matrix[13] * matrix_2.matrix[11],

			//[2, 2]
			matrix_1.matrix[2] * matrix_2.matrix[8] +
			matrix_1.matrix[6] * matrix_2.matrix[9] +
			matrix_1.matrix[10] * matrix_2.matrix[10] +
			matrix_1.matrix[14] * matrix_2.matrix[11],

			//[3, 2]
			matrix_1.matrix[3] * matrix_2.matrix[8] +
			matrix_1.matrix[7] * matrix_2.matrix[9] +
			matrix_1.matrix[11] * matrix_2.matrix[10] +
			matrix_1.matrix[15] * matrix_2.matrix[11],


			//[0, 3]
			matrix_1.matrix[0] * matrix_2.matrix[12] +
			matrix_1.matrix[4] * matrix_2.matrix[13] +
			matrix_1.matrix[8] * matrix_2.matrix[14] +
			matrix_1.matrix[12] * matrix_2.matrix[15],

			//[1, 3]
			matrix_1.matrix[1] * matrix_2.matrix[12] +
			matrix_1.matrix[5] * matrix_2.matrix[13] +
			matrix_1.matrix[9] * matrix_2.matrix[14] +
			matrix_1.matrix[13] * matrix_2.matrix[15],

			//[2, 3]
			matrix_1.matrix[2] * matrix_2.matrix[12] +
			matrix_1.matrix[6] * matrix_2.matrix[13] +
			matrix_1.matrix[10] * matrix_2.matrix[14] +
			matrix_1.matrix[14] * matrix_2.matrix[15],

			//[3, 3]
			matrix_1.matrix[3] * matrix_2.matrix[12] +
			matrix_1.matrix[7] * matrix_2.matrix[13] +
			matrix_1.matrix[11] * matrix_2.matrix[14] +
			matrix_1.matrix[15] * matrix_2.matrix[15]
		}
	});
}