#include <libmatrix_structs.h>
#include <matrix.h>
#include <math.h>
#include <vector.h>

//0 4  8 12
//1 5  9 13
//2 6 10 14
//3 7 11 15
t_mat4	mat4_yawpitchroll(const float yaw, const float pitch, const float roll)
{
	t_mat4			res;
	const float		ycos = cosf(yaw * 0.5f);
	const float		ysin = sinf(yaw * 0.5f);
	const float		pcos = cosf(pitch * 0.5f);
	const float		psin = sinf(pitch * 0.5f);
	const float		rcos = cosf(roll * 0.5f);
	const float		rsin = sinf(roll * 0.5f);
	const t_vec4	vector = vec4(
			ycos * pcos * rsin - ysin * psin * rcos,
			ysin * pcos * rsin + ycos * psin * rcos,
			ysin * pcos * rcos - ycos * psin * rsin,
			ycos * pcos * rcos + ysin * psin * rsin
	);

	res = mat4_init();
	res.matrix[0] = 1 - 2 * (vector.y * vector.y + vector.z * vector.z);
	res.matrix[4] = 2 * (vector.x * vector.y - vector.w * vector.z);
	res.matrix[8] = 2 * (vector.w * vector.y + vector.x * vector.z);
	res.matrix[1] = 2 * (vector.x * vector.y + vector.w * vector.z);
	res.matrix[5] = 1 - 2 * (vector.x * vector.x + vector.z * vector.z);
	res.matrix[9] = 2 * (vector.y * vector.z - vector.w * vector.x);
	res.matrix[2] = 2 * (vector.x * vector.z - vector.w * vector.y);
	res.matrix[6] = 2 * (vector.w * vector.x + vector.y * vector.z);
	res.matrix[10] = 1 - 2 * (vector.x * vector.x + vector.y * vector.y);
	return (res);
}