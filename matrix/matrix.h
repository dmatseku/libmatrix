#ifndef MATRIX_H
#define MATRIX_H

#include <libmatrix_structs.h>

t_mat4	mat4_init(char unit);

t_mat4	mat4_add(t_mat4 matrix_1, t_mat4 matrix_2);

t_mat4	mat4_add_scalar(t_mat4 matrix, float scalar);

t_mat4	mat4_mult(t_mat4 matrix_1, t_mat4 matrix_2);

t_mat4	mat4_mult_scalar(t_mat4 matrix, float scalar);

void	mat4_print(t_mat4 matrix);

t_mat4	mat4_sub(t_mat4 matrix_1, t_mat4 matrix_2);

t_mat4	mat4_sub_scalar(t_mat4 matrix, float scalar);

#endif
