#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <libmatrix_structs.h>


void		vector_add(t_vector* vector_1, t_vector const * vector_2);

t_vector*	vector_add_new(t_vector const * vector_1, t_vector const * vector_2);

void		vector_addscalar(t_vector* vector, float scalar);

void		vector_cat(t_vector* vector_1, t_vector const * vector_2);

t_vector*	vector_cpy(t_vector const * vector);

t_vector*	vector_create(float x, float y, float z, float w);

void		vector_divscalar(t_vector* vector, float scalar);

void		vector_multscalar(t_vector* vector, float scalar);

t_vector*	vector_normal(t_vector const * vector);

void		vector_rev(t_vector* vector);

float		vector_smult(t_vector const * vector_1, t_vector const * vector_2);

void		vector_sub(t_vector* vector_1, t_vector const * vector_2);

t_vector*	vector_sub_new(t_vector const * vector_1, t_vector const * vector_2);

void		vector_subscalar(t_vector* vector, float scalar);

float*		vector_to_array(t_vector const * vector);

t_vector*	vector_vmult(t_vector const * vector_1, t_vector const * vector_2);

#endif
