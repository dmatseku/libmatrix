#include <operations_matrix_vector.h>
#include <vector.h>

static inline float	mult(const size_t i, t_matrix const *const restrict m,
										t_vector const *const restrict v)
{
	return ((m->mat[i * m->j] * v->x) + (m->mat[i * m->j + 1] * v->y)
		+ (m->mat[i * m->j + 2] * v->z) + (m->mat[i * m->j + 3] * v->w));
}

t_vector*			mv_mult_new(t_vector const *const restrict vector,
								t_matrix const *const restrict matrix)
{
	return (vector_create(mult(0, matrix, vector), mult(1, matrix, vector),
						  mult(2, matrix, vector), mult(3, matrix, vector)));
}