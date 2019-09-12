#include <operations_matrix.h>
#include <matrix.h>
#include <math.h>
#include <vector_var.h>

//0 4  8 12
//1 5  9 13
//2 6 10 14
//3 7 11 15
t_matrix*	m_yawpitchroll_new(const float yaw, const float pitch, const float roll)
{
	t_matrix *const restrict	res = matrix_create(4, 4);
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

	if (!res)
		return (0);
	res->mat[0] = 1 - 2 * (vector.y * vector.y + vector.z * vector.z);
	res->mat[4] = 2 * (vector.x * vector.y - vector.w * vector.z);
	res->mat[8] = 2 * (vector.w * vector.y + vector.x * vector.z);
	res->mat[1] = 2 * (vector.x * vector.y + vector.w * vector.z);
	res->mat[5] = 1 - 2 * (vector.x * vector.x + vector.z * vector.z);
	res->mat[9] = 2 * (vector.y * vector.z - vector.w * vector.x);
	res->mat[2] = 2 * (vector.x * vector.z - vector.w * vector.y);
	res->mat[6] = 2 * (vector.w * vector.x + vector.y * vector.z);
	res->mat[10] = 1 - 2 * (vector.x * vector.x + vector.y * vector.y);
	return (res);
}