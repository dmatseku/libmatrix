#ifndef QUATERNION_H
# define QUATERNION_H


# include <libmatrix_structs.h>


void		quat_conjugate(t_vector* quaternion);

t_vector*	quat_conjugate_new(t_vector const * quaternion);

float		quat_norm(t_vector const * quaternion);

float		quat_norm_nosqrt(t_vector const * quaternion);

void		quat_reverse(t_vector* quaternion);

t_vector*	quat_reverse_new(t_vector const * quaternion);

#endif
