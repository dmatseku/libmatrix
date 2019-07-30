#include <operations_matrix.h>
#include <math.h>
#include <matrix.h>

t_matrix*	m_rotate_new(const float degree, const t_vector rotate)
{
	t_matrix *const restrict	res = matrix_create(4, 4);
	const float					dsin = sinf(degree);
	const float					dcos = cosf(degree);

	if (!res)
		return (0);
	res->mat[3][3] = 1.0;
	res->mat[0][0] = dcos + (rotate.x * rotate.x) * (1 - dcos);
	res->mat[0][1] = rotate.x * rotate.y * (1 - dcos) - rotate.z * dsin;
	res->mat[0][2] = rotate.x * rotate.z * (1 - dcos) + rotate.y * dsin;
	res->mat[1][0] = rotate.y * rotate.x * (1 - dcos) + rotate.z * dsin;
	res->mat[1][1] = dcos + (rotate.y * rotate.y) * (1 - dcos);
	res->mat[1][2] = rotate.y * rotate.z * (1 - dcos) - rotate.x * dsin;
	res->mat[2][0] = rotate.z * rotate.x * (1 - dcos) - rotate.y * dsin;
	res->mat[2][1] = rotate.z * rotate.y * (1 - dcos) + rotate.x * dsin;
	res->mat[2][2] = dcos + (rotate.z * rotate.z) * (1 - dcos);
	return (res);
}