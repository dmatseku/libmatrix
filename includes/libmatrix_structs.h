#ifndef LIBMATRIX_STRUCTS_H
#define LIBMATRIX_STRUCTS_H

# include <stdio.h>

typedef struct	s_vec4
{
	float 		x;
	float		y;
	float		z;
	float		w;
}				t_vec4;

typedef struct	s_vec3
{
	float 		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct	s_vec2
{
	float 		x;
	float		y;
}				t_vec2;

typedef struct	s_mat4
{
	float		matrix[16];
}				t_mat4;
#endif
