#ifndef QUATERNION_VAR_H
# define QUATERNION_VAR_H

# include <libmatrix_structs.h>

t_vector	quat_var_conjugate(t_vector quaternion);

float		quat_var_norm(t_vector quaternion);

float		quat_var_norm_nosqrt(t_vector quaternion);

t_vector	quat_var_reverse(t_vector quaternion);

#endif
