#include <operations_matrix.h>
#include <matrix.h>
#include <math.h>
#include <vector_var.h>

void	m_yawpitchroll_modify(t_matrix *const restrict matrix, const float yaw,
								 const float pitch, const float roll)
{
	const float					ycos = cosf(yaw * 0.5f);
	const float					ysin = sinf(yaw * 0.5f);
	const float					pcos = cosf(pitch * 0.5f);
	const float					psin = sinf(pitch * 0.5f);
	const float					rcos = cosf(roll * 0.5f);
	const float					rsin = sinf(roll * 0.5f);
	const t_vector				vector = vec4(
			ycos * pcos * rsin - ysin * psin * rcos,
			ysin * pcos * rsin + ycos * psin * rcos,
			ysin * pcos * rcos - ycos * psin * rsin,
			ycos * pcos * rcos + ysin * psin * rsin
	);

	matrix_set_unit(matrix);
	matrix->mat[0] = 1 - 2 * (vector.y * vector.y + vector.z * vector.z);
	matrix->mat[4] = 2 * (vector.x * vector.y - vector.w * vector.z);
	matrix->mat[8] = 2 * (vector.w * vector.y + vector.x * vector.z);
	matrix->mat[1] = 2 * (vector.x * vector.y + vector.w * vector.z);
	matrix->mat[5] = 1 - 2 * (vector.x * vector.x + vector.z * vector.z);
	matrix->mat[9] = 2 * (vector.y * vector.z - vector.w * vector.x);
	matrix->mat[2] = 2 * (vector.x * vector.z - vector.w * vector.y);
	matrix->mat[6] = 2 * (vector.w * vector.x + vector.y * vector.z);
	matrix->mat[10] = 1 - 2 * (vector.x * vector.x + vector.y * vector.y);
}