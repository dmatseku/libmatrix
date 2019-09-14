#include <libmatrix_structs.h>

//0 4  8 12
//1 5  9 13
//2 6 10 14
//3 7 11 15
t_mat4	mat4_init_null(void)
{
	return ((t_mat4)
	{
		.matrix =
		{
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f
		}
	});
}