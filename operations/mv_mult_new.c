#include <libmatrix.h>

static float	mult(size_t i, t_matrix *m, t_vector *v)
{
	float	res;

	res = (m->mat[i][0] * v->x) + (m->mat[i][1] * v->y)
		+ (m->mat[i][2] * v->z) + (m->mat[i][3] * v->w);
	return (res);
}

t_vector		*mv_mult_new(t_vector *v, t_matrix *m, int freev, int freem)
{
	t_vector	dtmp;
	t_vector	*res;

	if (!m || !v)
		return (0);
	dtmp.x = v->x;
	dtmp.y = v->y;
	dtmp.z = v->z;
	dtmp.w = v->w;
	CHECK((res = vector_create(mult(0, m, &dtmp), mult(1, m, &dtmp),
			mult(2, m, &dtmp), mult(3, m, &dtmp))));
	if (freev)
		free(v);
	if (freem)
		matrix_free(m);
	return (res);
}