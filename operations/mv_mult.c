#include <libmatrix.h>

static float	mult(size_t i, t_matrix *m, t_vector *v)
{
	float	res;

	res = (m->mat[i][0] * v->x) + (m->mat[i][1] * v->y)
		+ (m->mat[i][2] * v->z) + (m->mat[i][3] * v->w);
	return (res);
}

int				mv_mult(t_vector *v, t_matrix *m, int freem)
{
	t_vector	dtmp;

	if (!m || !v)
		return (0);
	dtmp.x = v->x;
	dtmp.y = v->y;
	dtmp.z = v->z;
	dtmp.w = v->w;
	v->x = mult(0, m, &dtmp);
	v->y = mult(1, m, &dtmp);
	v->z = mult(2, m, &dtmp);
	v->w = mult(3, m, &dtmp);
	if (freem)
		matrix_free(m);
	return (1);
}
