#include <libmatrix.h>

t_matrix	*m_yawpitchroll(t_matrix *m, float yaw, float pitch, float roll)
{
	t_vector	*res;
	t_matrix	*tmp;
	t_ypr		yrp;
	t_matrix	*matrix;

	yrp.ycos = cosf(yaw * 0.5f);
	yrp.ysin = sinf(yaw * 0.5f);
	yrp.pcos = cosf(pitch * 0.5f);
	yrp.psin = sinf(pitch * 0.5f);
	yrp.rcos = cosf(roll * 0.5f);
	yrp.rsin = sinf(roll * 0.5f);
	CHECK((res = vector_create(
			yrp.ycos * yrp.pcos * yrp.rsin - yrp.ysin * yrp.psin * yrp.rcos,
			yrp.ysin * yrp.pcos * yrp.rsin + yrp.ycos * yrp.psin * yrp.rcos,
			yrp.ysin * yrp.pcos * yrp.rcos - yrp.ycos * yrp.psin * yrp.rsin,
			yrp.ycos * yrp.pcos * yrp.rcos + yrp.ysin * yrp.psin * yrp.rsin
	)));
	CHECK((matrix = matrix_create(4, 4)));
	matrix->mat[0][0] = 1 - 2 * (res->y * res->y + res->z * res->z);
	matrix->mat[0][1] = 2 * (res->x * res->y - res->w * res->z);
	matrix->mat[0][2] = 2 * (res->w * res->y + res->x * res->z);
	matrix->mat[1][0] = 2 * (res->x * res->y + res->w * res->z);
	matrix->mat[1][1] = 1 - 2 * (res->x * res->x + res->z * res->z);
	matrix->mat[1][2] = 2 * (res->y * res->z - res->w * res->x);
	matrix->mat[2][0] = 2 * (res->x * res->z - res->w * res->y);
	matrix->mat[2][1] = 2 * (res->w * res->x + res->y * res->z);
	matrix->mat[2][2] = 1 - 2 * (res->x * res->x + res->y * res->y);
	tmp = matrix_mult(m, matrix);
	matrix_free(matrix);
	matrix_free(m);
	FREE(res);
	return (tmp);
}
