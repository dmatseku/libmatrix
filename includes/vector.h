#ifndef MATRIX_VECTOR_H
#define MATRIX_VECTOR_H

#include <general.h>

typedef struct  s_vec4
{
    t_float     x;
    t_float     y;
    t_float     z;
    t_float     w;
}               t_vec4;

typedef struct  s_vec3
{
    t_float     x;
    t_float     y;
    t_float     z;
}               t_vec3;

typedef struct  s_vec2
{
    t_float     x;
    t_float     y;
}               t_vec2;


#define vec2(vx, vy) (t_vec2){ .x = vx, .y = vy }
#define vec3(vx, vy, vz) (t_vec3){ .x = vx, .y = vy, .z = vz }
#define vec4(vx, vy, vz, vw) (t_vec4){ .x = vx, .y = vy, .z = vz, .w = vw }

#define yaw x
#define pitch y
#define roll z

/* ----VECTOR 4---- */

t_vec4  vec4_add(const t_vec4 *vector_left, const t_vec4 *vector_right);

t_vec4  vec4_sub(const t_vec4 *vector_left, const t_vec4 *vector_right);

t_vec4  vec4_mult(const t_vec4 *vector_left, const t_vec4 *vector_right);

t_vec4  vec4_lerp(const t_vec4 *vector1, const t_vec4 *vector2, t_float t);

t_vec4  vec4_normalize(const t_vec4 *vector);

t_vec4  vec4_scale(const t_vec4 *vector, t_float s);

void    vec4_normalize_self(t_vec4 *vector);

void    vec4_scale_self(t_vec4 *vector, t_float s);

t_float vec4_length(const t_vec4 *vector);

t_float vec4_dot(const t_vec4 *vector1, const t_vec4 *vector2);

t_float vec4_distance(const t_vec4 *vector1, const t_vec4 *vector2);

t_float vec4_angle(const t_vec4 *vector1, const t_vec4 *vector2);

/* ----VECTOR 4 WITH DESTINATION---- */

void    vec4_add_d(const t_vec4 *vector_left, const t_vec4 *vector_right, t_vec4 *dest);

void    vec4_sub_d(const t_vec4 *vector_left, const t_vec4 *vector_right, t_vec4 *dest);

void    vec4_mult_d(const t_vec4 *vector_left, const t_vec4 *vector_right, t_vec4 *dest);

void    vec4_lerp_d(const t_vec4 *vector1, const t_vec4 *vector2, t_float t, t_vec4 *dest);

void    vec4_normalize_d(const t_vec4 *vector, t_vec4 *dest);

void    vec4_scale_d(const t_vec4 *vector, t_float s, t_vec4 *dest);

/* ----VECTOR 3---- */

t_vec3  vec3_add(const t_vec3 *vector_left, const t_vec3 *vector_right);

t_vec3  vec3_sub(const t_vec3 *vector_left, const t_vec3 *vector_right);

t_vec3  vec3_mult(const t_vec3 *vector_left, const t_vec3 *vector_right);

t_vec3  vec3_cross(const t_vec3 *vector_left, const t_vec3 *vector_right);

t_vec3  vec3_lerp(const t_vec3 *vector1, const t_vec3 *vector2, t_float t);

t_vec3  vec3_normalize(const t_vec3 *vector);

t_vec3  vec3_scale(const t_vec3 *vector, t_float s);

void    vec3_normalize_self(t_vec3 *vector);

void    vec3_scale_self(t_vec3 *vector, t_float s);

t_float vec3_length(const t_vec3 *vector);

t_float vec3_dot(const t_vec3 *vector1, const t_vec3 *vector2);

t_float vec3_distance(const t_vec3 *vector1, const t_vec3 *vector2);

t_float vec3_angle(const t_vec3 *vector1, const t_vec3 *vector2);

/* ----VECTOR 3 WITH DESTINATION---- */

void    vec3_add_d(const t_vec3 *vector_left, const t_vec3 *vector_right, t_vec3 *dest);

void    vec3_sub_d(const t_vec3 *vector_left, const t_vec3 *vector_right, t_vec3 *dest);

void    vec3_mult_d(const t_vec3 *vector_left, const t_vec3 *vector_right, t_vec3 *dest);

void    vec3_cross_d(const t_vec3 *vector_left, const t_vec3 *vector_right, t_vec3 *restrict dest);

void    vec3_lerp_d(const t_vec3 *vector1, const t_vec3 *vector2, t_float t, t_vec3 *dest);

void    vec3_normalize_d(const t_vec3 *vector, t_vec3 *dest);

void    vec3_scale_d(const t_vec3 *vector, t_float s, t_vec3 *dest);

/* ----VECTOR 2---- */

t_vec2  vec2_add(const t_vec2 *vector_left, const t_vec2 *vector_right);

t_vec2  vec2_sub(const t_vec2 *vector_left, const t_vec2 *vector_right);

t_vec2  vec2_mult(const t_vec2 *vector_left, const t_vec2 *vector_right);

t_vec2  vec2_lerp(const t_vec2 *vector1, const t_vec2 *vector2, t_float t);

t_vec2  vec2_normalize(const t_vec2 *vector);

t_vec2  vec2_scale(const t_vec2 *vector, t_float s);

void    vec2_normalize_self(t_vec2 *vector);

void    vec2_scale_self(t_vec2 *vector, t_float s);

t_float vec2_length(const t_vec2 *vector);

t_float vec2_dot(const t_vec2 *vector1, const t_vec2 *vector2);

t_float vec2_distance(const t_vec2 *vector1, const t_vec2 *vector2);

t_float vec2_angle(const t_vec2 *vector1, const t_vec2 *vector2);

/* ----VECTOR 2 WITH DESTINATION---- */

void    vec2_add_d(const t_vec2 *vector_left, const t_vec2 *vector_right, t_vec2 *dest);

void    vec2_sub_d(const t_vec2 *vector_left, const t_vec2 *vector_right, t_vec2 *dest);

void    vec2_mult_d(const t_vec2 *vector_left, const t_vec2 *vector_right, t_vec2 *dest);

void    vec2_lerp_d(const t_vec2 *vector1, const t_vec2 *vector2, t_float t, t_vec2 *dest);

void    vec2_normalize_d(const t_vec2 *vector, t_vec2 *dest);

void    vec2_scale_d(const t_vec2 *vector, t_float s, t_vec2 *dest);

#endif /*MATRIX_VECTOR_H*/
