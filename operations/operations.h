#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <libmatrix_structs.h>

t_vec4	mat_vec_4_mult(t_mat4 matrix, t_vec4 vector);

t_mat4	mat4_camera(t_vec3 pos, t_vec3 target, t_vec3 up);

t_mat4	mat4_orthographic(float left, float right, float bottom,
							float top, float near, float far);

t_mat4	mat4_perspective(float fov, float ar, float near, float far);

t_mat4	mat4_rotate(float degree, t_vec3 rotate);

t_mat4	mat4_scale(t_vec3 scale);

t_mat4	mat4_translate(t_vec3 translate);

t_mat4	mat4_yawpitchroll(float yaw, float pitch, float roll);

#endif