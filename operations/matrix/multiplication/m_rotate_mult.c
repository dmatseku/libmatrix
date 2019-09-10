#include <operations_matrix.h>
#include <math.h>
#include <matrix.h>

t_matrix*	m_rotate_mult(t_matrix *const restrict matrix,
					  const float degree, const t_vector rotate)
{
	t_matrix *restrict			res;
	t_matrix *const restrict	tmp = matrix_create(4, 4);
	const float					dsin = sinf(degree);
	const float					dcos = cosf(degree);

	if (!tmp)
		return (0);
	tmp->mat[15] = 1.0;
	tmp->mat[0] = dcos + (rotate.x * rotate.x) * (1 - dcos);
	tmp->mat[1] = rotate.x * rotate.y * (1 - dcos) - rotate.z * dsin;
	tmp->mat[2] = rotate.x * rotate.z * (1 - dcos) + rotate.y * dsin;
	tmp->mat[4] = rotate.y * rotate.x * (1 - dcos) + rotate.z * dsin;
	tmp->mat[5] = dcos + (rotate.y * rotate.y) * (1 - dcos);
	tmp->mat[6] = rotate.y * rotate.z * (1 - dcos) - rotate.x * dsin;
	tmp->mat[8] = rotate.z * rotate.x * (1 - dcos) - rotate.y * dsin;
	tmp->mat[9] = rotate.z * rotate.y * (1 - dcos) + rotate.x * dsin;
	tmp->mat[10] = dcos + (rotate.z * rotate.z) * (1 - dcos);
	res = matrix_mult(matrix, tmp);
	matrix_free(tmp);
	matrix_free(matrix);
	return (res);
}