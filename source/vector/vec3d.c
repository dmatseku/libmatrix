#include <vector.h>

void
vec3_add_d(const t_vec3 *const vector_left, const t_vec3 *const vector_right, t_vec3 *const dest)
{
    dest->x = vector_left->x + vector_right->x;
    dest->y = vector_left->y + vector_right->y;
    dest->z = vector_left->z + vector_right->z;
}

void
vec3_sub_d(const t_vec3 *const vector_left, const t_vec3 *const vector_right, t_vec3 *const dest)
{
    dest->x = vector_left->x - vector_right->x;
    dest->y = vector_left->y - vector_right->y;
    dest->z = vector_left->z - vector_right->z;
}

void
vec3_mult_d(const t_vec3 *const vector_left, const t_vec3 *const vector_right, t_vec3 *const dest)
{
    dest->x = vector_left->x * vector_right->x;
    dest->y = vector_left->y * vector_right->y;
    dest->z = vector_left->z * vector_right->z;
}

void
vec3_cross_d(const t_vec3 *const vector_left, const t_vec3 *const vector_right, t_vec3 *const restrict dest)
{
    dest->x = vector_left->y * vector_right->z - vector_left->z * vector_right->y;
    dest->y = vector_left->z * vector_right->x - vector_left->x * vector_right->z;
    dest->z = vector_left->x * vector_right->y - vector_left->y * vector_right->x;
}

void
vec3_lerp_d(const t_vec3 *const vector1, const t_vec3 *const vector2, t_float t, t_vec3 *const dest)
{
    dest->x = vector1->x + (vector2->x - vector1->x) * t;
    dest->y = vector1->y + (vector2->y - vector1->y) * t;
    dest->z = vector1->z + (vector2->z - vector1->z) * t;
}

void
vec3_normalize_d(const t_vec3 *const vector, t_vec3 *const dest)
{
    t_float mag = vec3_length(vector);

    if (mag != 0)
    {
        dest->x = vector->x / mag;
        dest->y = vector->y / mag;
        dest->z = vector->z / mag;
    }
    else
    {
        *dest = *vector;
    }
}

void
vec3_scale_d(const t_vec3 *const vector, t_float s, t_vec3 *const dest)
{
    dest->x = vector->x * s;
    dest->y = vector->y * s;
    dest->z = vector->z * s;
}