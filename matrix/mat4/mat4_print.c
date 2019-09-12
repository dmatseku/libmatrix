#include <libmatrix_structs.h>

//0 4  8 12
//1 5  9 13
//2 6 10 14
//3 7 11 15
void	mat4_print(const t_mat4 matrix)
{
	printf("%-f %-f %-f %-f\n", matrix.matrix[0], matrix.matrix[4], matrix.matrix[8], matrix.matrix[12]);
	printf("%-f %-f %-f %-f\n", matrix.matrix[1], matrix.matrix[5], matrix.matrix[9], matrix.matrix[13]);
	printf("%-f %-f %-f %-f\n", matrix.matrix[2], matrix.matrix[6], matrix.matrix[10], matrix.matrix[14]);
	printf("%-f %-f %-f %-f\n", matrix.matrix[3], matrix.matrix[7], matrix.matrix[11], matrix.matrix[15]);
}