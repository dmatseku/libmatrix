#ifndef LIBMATRIX_LIBMATRIX_H

# define LIBMATRIX_LIBMATRIX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <math.h>
# include <string.h>

# define CHECK(x) if (!x) return (0)

# define FREE(x) if (x) free(x)

# define CHECKM(x) if (x < 0) return (-1)

# define CHECKMN(x) if (!x) return (-1)

# define VCHECK(x) if (!x) return ;

typedef	struct	s_matrix
{
	size_t		i;
	size_t		j;
	float 		**mat;
}				t_matrix;

t_matrix	*matrix_create(size_t i, size_t j);

int			matrix_add(t_matrix *m1, t_matrix *m2);

t_matrix	*matrix_add_new(t_matrix *m1, t_matrix *m2, int freem);

int			matrix_sub(t_matrix *m1, t_matrix *m2);

t_matrix	*matrix_sub_new(t_matrix *m1, t_matrix *m2, int freem);

t_matrix	*matrix_mult(t_matrix *m1, t_matrix *m2);

int			matrix_addscalar(t_matrix *m, float scalar);

int			matrix_subscalar(t_matrix *m, float scalar);

int			matrix_multscalar(t_matrix *m, float scalar);

t_matrix	*matrix_cpy(t_matrix *m);

int			matrix_cat(t_matrix *m1, t_matrix *m2);

void		matrix_free(t_matrix *m);

typedef struct	s_vector
{
	float 		x;
	float		y;
	float		z;
	float		w;
}				t_vector;

t_vector	*vector_create(float x, float y, float z, float w);

int 		vector_rev(t_vector *v);

int			vector_cat(t_vector *v1, t_vector *v2);

t_vector	*vector_cpy(t_vector *v1);

t_vector	*vector_normal(t_vector *v, int freev);

int			vector_addscalar(t_vector *v, float scalar);

int			vector_subscalar(t_vector *v, float scalar);

int			vector_multscalar(t_vector *v, float scalar);

int			vector_divscalar(t_vector *v, float scalar);

int 		vector_add(t_vector *v1, t_vector *v2);

t_vector 	*vector_add_new(t_vector *v1, t_vector *v2, int freev);

int 		vector_sub(t_vector *v1, t_vector *v2);

t_vector 	*vector_sub_new(t_vector *v1, t_vector *v2, int freev);

float		vector_smult(t_vector *v1, t_vector *v2);

t_vector	*vector_vmult(t_vector *v1, t_vector *v2);

float		*vector_to_array(t_vector *vector);

int			mv_mult(t_vector *v, t_matrix *m, int freem);

t_vector	*mv_mult_new(t_vector *v, t_matrix *m, int freev, int freem);

t_matrix	*m_rotate(t_matrix *m, float degree, t_vector rotate);

t_matrix	*m_translate(t_matrix *m, t_vector translate);

t_matrix	*m_scale(t_matrix *m, t_vector scale);

t_matrix	*m_orthographic(float left, float right, float bottom, float top, float near, float far);

typedef struct	s_perspective
{
	float		top;
	float 		bottom;
	float 		left;
	float 		right;
}				t_perspective;


typedef struct	s_camera
{
	t_vector	*camdir;
	t_vector	*cright;
	t_vector	*cup;
}				t_camera;

t_matrix	*m_perspective(float fov, float ar, float near, float far);

t_matrix	*m_camera(t_vector pos, t_vector target, t_vector up);

t_matrix	*m_yawpitchroll_new(float yaw, float pitch, float roll);

t_matrix	*m_yawpitchroll(t_matrix *m, float yaw, float pitch, float roll);

float		*matrix_to_array(t_matrix *m);

float		*matrix_to_arrayf(t_matrix *m);

void		matrix_print(t_matrix *m);

typedef struct	s_ypr
{
	float		ycos;
	float		ysin;
	float		pcos;
	float		psin;
	float		rcos;
	float		rsin;
}				t_ypr;

void		quat_conjugate(t_vector *quaternion);

t_vector	*quat_conjugate_new(t_vector *quaternion, int freeq);

float		quat_norm(t_vector *quaternion);

float		quat_norm_nosqrt(t_vector *quaternion);

t_vector	*quat_reverse(t_vector *quaternion);

#endif
