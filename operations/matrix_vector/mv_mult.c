#include <operations_matrix_vector.h>

static inline float	mult(const size_t i, t_matrix *const restrict m,
										t_vector const *const restrict v)
{
	return ((m->mat[i * m->j] * v->x) + (m->mat[i * m->j + 1] * v->y)
		+ (m->mat[i * m->j + 2] * v->z) + (m->mat[i * m->j + 3] * v->w));
}

void			mv_mult(t_vector *const restrict vector,
											t_matrix *const restrict matrix)
{
	const t_vector	dtmp = *vector;

	vector->x = mult(0, matrix, &dtmp);
	vector->y = mult(1, matrix, &dtmp);
	vector->z = mult(2, matrix, &dtmp);
	vector->w = mult(3, matrix, &dtmp);
}
