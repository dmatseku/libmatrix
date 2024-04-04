#include <vector.h>

void
vec2_add_d(const t_vec2 *const vector_left, const t_vec2 *const vector_right, t_vec2 *const dest)
{
    dest->x = vector_left->x + vector_right->x;
    dest->y = vector_left->y + vector_right->y;
}

void
vec2_sub_d(const t_vec2 *const vector_left, const t_vec2 *const vector_right, t_vec2 *const dest)
{
    dest->x = vector_left->x - vector_right->x;
    dest->y = vector_left->y - vector_right->y;
}

void
vec2_mult_d(const t_vec2 *const vector_left, const t_vec2 *const vector_right, t_vec2 *const dest)
{
    dest->x = vector_left->x * vector_right->x;
    dest->y = vector_left->y * vector_right->y;
}

void
vec2_lerp_d(const t_vec2 *const vector1, const t_vec2 *const vector2, t_float t, t_vec2 *const dest)
{
    dest->x = vector1->x + (vector2->x - vector1->x) * t;
    dest->y = vector1->y + (vector2->y - vector1->y) * t;
}

void
vec2_normalize_d(const t_vec2 *const vector, t_vec2 *const dest)
{
    t_float mag = vec2_length(vector);

    if (mag != 0)
    {
        dest->x = vector->x / mag;
        dest->y = vector->y / mag;
    }
    else
    {
        *dest = *vector;
    }
}

void
vec2_scale_d(const t_vec2 *const vector, t_float s, t_vec2 *const dest)
{
    dest->x = vector->x * s;
    dest->y = vector->y * s;
}