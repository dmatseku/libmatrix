#ifndef MATRIX_VECTOR_H
# define MATRIX_VECTOR_H

# include <libmatrix_structs.h>


void		mv_mult(t_vector* vector, t_matrix const * matrix);

t_vector*	mv_mult_new(t_vector const * vector, t_matrix const * matrix);

t_vector	mv_mult_var(t_vector vector, t_matrix const * matrix);

#endif