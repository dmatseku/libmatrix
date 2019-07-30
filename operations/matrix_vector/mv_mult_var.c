#include <operations_matrix_vector.h>
#include <vector_var.h>

static inline float	mult(const size_t i, t_matrix *const restrict m, const t_vector v)
{
	return ((m->mat[i][0] * v.x) + (m->mat[i][1] * v.y)
			+ (m->mat[i][2] * v.z) + (m->mat[i][3] * v.w));
}

t_vector			mv_mult_var(const t_vector vector, t_matrix *const restrict matrix)
{
	return (vector_var_create(mult(0, matrix, vector), mult(1, matrix, vector),
						  mult(2, matrix, vector), mult(3, matrix, vector)));
}