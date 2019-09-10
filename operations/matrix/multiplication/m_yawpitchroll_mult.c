#include <operations_matrix.h>
#include <matrix.h>
#include <math.h>
#include <vector_var.h>

t_matrix*	m_yawpitchroll_mult(t_matrix *const restrict matrix, const float yaw,
							const float pitch, const float roll)
{
	t_matrix *const restrict	tmp = matrix_create(4, 4);
	t_matrix *restrict			res;
	const float					ycos = cosf(yaw * 0.5f);
	const float					ysin = sinf(yaw * 0.5f);
	const float					pcos = cosf(pitch * 0.5f);
	const float					psin = sinf(pitch * 0.5f);
	const float					rcos = cosf(roll * 0.5f);
	const float					rsin = sinf(roll * 0.5f);
	const t_vector				vector = vector_var_create(
			ycos * pcos * rsin - ysin * psin * rcos,
			ysin * pcos * rsin + ycos * psin * rcos,
			ysin * pcos * rcos - ycos * psin * rsin,
			ycos * pcos * rcos + ysin * psin * rsin
	);

	if (!tmp)
		return (0);
	tmp->mat[0] = 1 - 2 * (vector.y * vector.y + vector.z * vector.z);
	tmp->mat[1] = 2 * (vector.x * vector.y - vector.w * vector.z);
	tmp->mat[2] = 2 * (vector.w * vector.y + vector.x * vector.z);
	tmp->mat[4] = 2 * (vector.x * vector.y + vector.w * vector.z);
	tmp->mat[5] = 1 - 2 * (vector.x * vector.x + vector.z * vector.z);
	tmp->mat[6] = 2 * (vector.y * vector.z - vector.w * vector.x);
	tmp->mat[8] = 2 * (vector.x * vector.z - vector.w * vector.y);
	tmp->mat[9] = 2 * (vector.w * vector.x + vector.y * vector.z);
	tmp->mat[10] = 1 - 2 * (vector.x * vector.x + vector.y * vector.y);
	res = matrix_mult(matrix, tmp);
	matrix_free(tmp);
	matrix_free(matrix);
	return (res);
}