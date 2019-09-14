#include <libmatrix_structs.h>
#include <math.h>
#include <matrix.h>

//0 4  8 12
//1 5  9 13
//2 6 10 14
//3 7 11 15
t_mat4	mat4_rotate(const float degree, const t_vec3 rotate)
{
	t_mat4		res;
	const float	dsin = sinf(degree);
	const float	dcos = cosf(degree);

	res = mat4_init();
	res.matrix[0] = dcos + (rotate.x * rotate.x) * (1 - dcos);
	res.matrix[4] = rotate.x * rotate.y * (1 - dcos) - rotate.z * dsin;
	res.matrix[8] = rotate.x * rotate.z * (1 - dcos) + rotate.y * dsin;
	res.matrix[1] = rotate.y * rotate.x * (1 - dcos) + rotate.z * dsin;
	res.matrix[5] = dcos + (rotate.y * rotate.y) * (1 - dcos);
	res.matrix[9] = rotate.y * rotate.z * (1 - dcos) - rotate.x * dsin;
	res.matrix[2] = rotate.z * rotate.x * (1 - dcos) - rotate.y * dsin;
	res.matrix[6] = rotate.z * rotate.y * (1 - dcos) + rotate.x * dsin;
	res.matrix[10] = dcos + (rotate.z * rotate.z) * (1 - dcos);
	return (res);
}
