#include <vector.h>

void
vec4_add_d(const t_vec4 *const vector_left, const t_vec4 *const vector_right, t_vec4 *const dest)
{
    dest->x = vector_left->x + vector_right->x;
    dest->y = vector_left->y + vector_right->y;
    dest->z = vector_left->z + vector_right->z;
    dest->w = vector_left->w + vector_right->w;
}

void
vec4_sub_d(const t_vec4 *const vector_left, const t_vec4 *const vector_right, t_vec4 *const dest)
{
    dest->x = vector_left->x - vector_right->x;
    dest->y = vector_left->y - vector_right->y;
    dest->z = vector_left->z - vector_right->z;
    dest->w = vector_left->w - vector_right->w;
}

void
vec4_mult_d(const t_vec4 *const vector_left, const t_vec4 *const vector_right, t_vec4 *const dest)
{
    dest->x = vector_left->x * vector_right->x;
    dest->y = vector_left->y * vector_right->y;
    dest->z = vector_left->z * vector_right->z;
    dest->w = vector_left->w * vector_right->w;
}

void
vec4_lerp_d(const t_vec4 *const vector1, const t_vec4 *const vector2, t_float t, t_vec4 *const dest)
{
    dest->x = vector1->x + (vector2->x - vector1->x) * t;
    dest->y = vector1->y + (vector2->y - vector1->y) * t;
    dest->z = vector1->z + (vector2->z - vector1->z) * t;
    dest->w = vector1->w + (vector2->w - vector1->w) * t;
}

void
vec4_normalize_d(const t_vec4 *const vector, t_vec4 *const dest)
{
    t_float mag = vec4_length(vector);

    if (mag != 0)
    {
        dest->x = vector->x / mag;
        dest->y = vector->y / mag;
        dest->z = vector->z / mag;
        dest->w = vector->w / mag;
    }
    else
    {
        *dest = *vector;
    }
}

void
vec4_scale_d(const t_vec4 *const vector, t_float s, t_vec4 *const dest)
{
    dest->x = vector->x * s;
    dest->y = vector->y * s;
    dest->z = vector->z * s;
    dest->w = vector->w * s;
}