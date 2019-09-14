#include <libmatrix_structs.h>

t_mat4	mat4_sub_scalar(const t_mat4 matrix, const float scalar)
{
	return ((t_mat4)
	{
		.matrix =
		{
			matrix.matrix[0] - scalar,
			matrix.matrix[1] - scalar,
			matrix.matrix[2] - scalar,
			matrix.matrix[3] - scalar,
			matrix.matrix[4] - scalar,
			matrix.matrix[5] - scalar,
			matrix.matrix[6] - scalar,
			matrix.matrix[7] - scalar,
			matrix.matrix[8] - scalar,
			matrix.matrix[9] - scalar,
			matrix.matrix[10] - scalar,
			matrix.matrix[11] - scalar,
			matrix.matrix[12] - scalar,
			matrix.matrix[13] - scalar,
			matrix.matrix[14] - scalar,
			matrix.matrix[15] - scalar
		}
	});
}