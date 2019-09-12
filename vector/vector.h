#ifndef VECTOR_H
#define VECTOR_H
#define vec4(x, y, z, w) (t_vec4){x, y, z, w}
#define vec3(x, y, z) (t_vec3){x, y, z}
#define vec2(x, y) (t_vec2){x, y}

#include <libmatrix_structs.h>

t_vec4	vec4_add(t_vec4 vector_1, t_vec4 vector_2);

t_vec4	vec4_add_scalar(t_vec4 vector, float scalar);

t_vec4	vec4_div_scalar(t_vec4 vector, float scalar);

t_vec4	vec4_mult_scalar(t_vec4 vector, float scalar);

t_vec4	vec4_normal(t_vec4 vector);

t_vec4	vec4_rev(t_vec4 vector);

float	vec4_scalar_mult(t_vec4 vector_1, t_vec4 vector_2);

t_vec4	vec4_sub(t_vec4 vector_1, t_vec4 vector_2);

t_vec4	vec4_sub_scalar(t_vec4 vector, float scalar);


t_vec3	vec3_add(t_vec3 vector_1, t_vec3 vector_2);

t_vec3	vec3_add_scalar(t_vec3 vector, float scalar);

t_vec3	vec3_div_scalar(t_vec3 vector, float scalar);

t_vec3	vec3_mult_scalar(t_vec3 vector, float scalar);

t_vec3	vec3_normal(t_vec3 vector);

t_vec3	vec3_rev(t_vec3 vector);

float	vec3_scalar_mult(t_vec3 vector_1, t_vec3 vector_2);

t_vec3	vec3_vector_mult(t_vec3 vector_1, t_vec3 vector_2);

t_vec3	vec3_sub(t_vec3 vector_1, t_vec3 vector_2);

t_vec3	vec3_sub_scalar(t_vec3 vector, float scalar);


t_vec2	vec2_add(t_vec2 vector_1, t_vec2 vector_2);

t_vec2	vec2_add_scalar(t_vec2 vector, float scalar);

t_vec2	vec2_div_scalar(t_vec2 vector, float scalar);

t_vec2	vec2_mult_scalar(t_vec2 vector, float scalar);

t_vec2	vec2_normal(t_vec2 vector);

t_vec2	vec2_rev(t_vec2 vector);

float	vec2_scalar_mult(t_vec2 vector_1, t_vec2 vector_2);

t_vec2	vec2_sub(t_vec2 vector_1, t_vec2 vector_2);

t_vec2	vec2_sub_scalar(t_vec2 vector, float scalar);

#endif
