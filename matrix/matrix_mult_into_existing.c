#include <matrix.h>

#include <matrix.h>

static inline float	mult(const size_t i, t_matrix const *const restrict matrix_1,
							t_matrix const *const restrict matrix_2)
{
	size_t	tmp1;
	float	res;

	tmp1 = 0;
	res = 0;
	while (tmp1 < matrix_2->j)
	{
		res += (matrix_2->mat[matrix_2->j * (i / matrix_2->j) + tmp1]
				* matrix_1->mat[tmp1 * matrix_2->j + i % matrix_2->j]);
		tmp1++;
	}
	return (res);
}

void		matrix_mult_into_existing(t_matrix *const restrict res_matrix,
					t_matrix const *const restrict matrix_1,
	 				t_matrix const *const restrict matrix_2)
{
	size_t						i;
	const size_t				size = matrix_2->j * matrix_1->i;

	i = 0;
	while (i < size)
	{
		res_matrix->mat[i] = mult(i, matrix_1, matrix_2);
		i++;
	}
}