#include <operations_matrix.h>
#include <math.h>
#include <matrix.h>

void	m_rotate_modify(t_matrix *const restrict matrix,
						const float degree, const t_vector rotate)
{
	const float	dsin = sinf(degree);
	const float	dcos = cosf(degree);

	matrix_set_unit(matrix);
	matrix->mat[15] = 1.0;
	matrix->mat[0] = dcos + (rotate.x * rotate.x) * (1 - dcos);
	matrix->mat[1] = rotate.x * rotate.y * (1 - dcos) - rotate.z * dsin;
	matrix->mat[2] = rotate.x * rotate.z * (1 - dcos) + rotate.y * dsin;
	matrix->mat[4] = rotate.y * rotate.x * (1 - dcos) + rotate.z * dsin;
	matrix->mat[5] = dcos + (rotate.y * rotate.y) * (1 - dcos);
	matrix->mat[6] = rotate.y * rotate.z * (1 - dcos) - rotate.x * dsin;
	matrix->mat[8] = rotate.z * rotate.x * (1 - dcos) - rotate.y * dsin;
	matrix->mat[9] = rotate.z * rotate.y * (1 - dcos) + rotate.x * dsin;
	matrix->mat[10] = dcos + (rotate.z * rotate.z) * (1 - dcos);
}