#include <vector.h>
#include <math.h>

t_vec2
vec2_add(const t_vec2 *const vector_left, const t_vec2 *const vector_right)
{
    return vec2
    (
        vector_left->x + vector_right->x,
        vector_left->y + vector_right->y
    );
}

t_vec2
vec2_sub(const t_vec2 *const vector_left, const t_vec2 *const vector_right)
{
    return vec2
    (
        vector_left->x - vector_right->x,
        vector_left->y - vector_right->y
    );
}

t_vec2
vec2_mult(const t_vec2 *const vector_left, const t_vec2 *const vector_right)
{
    return vec2
    (
        vector_left->x * vector_right->x,
        vector_left->y * vector_right->y
    );
}

t_vec2
vec2_lerp(const t_vec2 *const vector1, const t_vec2 *const vector2, t_float t)
{
    return vec2
    (
        vector1->x + (vector2->x - vector1->x) * t,
        vector1->y + (vector2->y - vector1->y) * t
    );
}

t_vec2
vec2_normalize(const t_vec2 *const vector)
{
    t_float mag = vec2_length(vector);

    if (mag != 0)
    {
        return vec2(vector->x / mag, vector->y / mag);
    }

    return *vector;
}

t_vec2
vec2_scale(const t_vec2 *const vector, t_float s)
{
    return vec2(vector->x * s, vector->y * s);
}

void
vec2_normalize_self(t_vec2 *const vector)
{
    t_float mag = vec2_length(vector);

    if (mag != 0)
    {
        vector->x /= mag;
        vector->y /= mag;
    }
}

void
vec2_scale_self(t_vec2 *const vector, t_float s)
{
    vector->x *= s;
    vector->y *= s;
}

t_float
vec2_length(const t_vec2 *const vector)
{
    return sqrt(vector->x * vector->x + vector->y * vector->y);
}

t_float
vec2_dot(const t_vec2 *const vector1, const t_vec2 *const vector2)
{
    return vector1->x * vector2->x + vector1->y * vector2->y;
}

t_float
vec2_distance(const t_vec2 *const vector1, const t_vec2 *const vector2)
{
    t_vec2 diff = vec2_sub(vector1, vector2);

    return vec2_length(&diff);
}

t_float
vec2_angle(const t_vec2 *const vector1, const t_vec2 *const vector2)
{
    t_float dot, left_length, right_length;

    dot = vec2_dot(vector1, vector2);
    left_length = vec2_length(vector1);
    right_length = vec2_length(vector2);

    return acos(dot / (left_length * right_length));
}