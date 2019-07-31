#include <matrix.h>

void		matrix_cat(t_matrix *const restrict matrix_1, t_matrix *const restrict matrix_2)
{
	size_t i;
	size_t j;

	i = 0;
    while (i < matrix_1->i)
    {
    	j = 0;
    	while (j < matrix_1->j)
		{
    		matrix_1->mat[i][j] = matrix_2->mat[i][j];
    		j++;
		}
    	i++;
    }
}
