#include <libmatrix_structs.h>

//0 4  8 12  x
//1 5  9 13  y
//2 6 10 14  z
//3 7 11 15  w
t_vec4	mat_vec_4_mult(const t_mat4 matrix, const t_vec4 vector)
{
	return ((t_vec4)
	{
		matrix.matrix[0] * vector.x + matrix.matrix[4] * vector.y +
		matrix.matrix[8] * vector.z + matrix.matrix[12] * vector.w,

		matrix.matrix[1] * vector.x + matrix.matrix[5] * vector.y +
		matrix.matrix[9] * vector.z + matrix.matrix[13] * vector.w,

		matrix.matrix[2] * vector.x + matrix.matrix[6] * vector.y +
		matrix.matrix[10] * vector.z + matrix.matrix[14] * vector.w,

		matrix.matrix[3] * vector.x + matrix.matrix[7] * vector.y +
		matrix.matrix[11] * vector.z + matrix.matrix[15] * vector.w,
	});
}