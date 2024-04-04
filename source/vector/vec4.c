#include <vector.h>
#include <math.h>

t_vec4
vec4_add(const t_vec4 *const vector_left, const t_vec4 *const vector_right)
{
    return vec4
    (
        vector_left->x + vector_right->x,
        vector_left->y + vector_right->y,
        vector_left->z + vector_right->z,
        vector_left->w + vector_right->w
    );
}

t_vec4
vec4_sub(const t_vec4 *const vector_left, const t_vec4 *const vector_right)
{
    return vec4
    (
        vector_left->x - vector_right->x,
        vector_left->y - vector_right->y,
        vector_left->z - vector_right->z,
        vector_left->w - vector_right->w
    );
}

t_vec4
vec4_mult(const t_vec4 *const vector_left, const t_vec4 *const vector_right)
{
    return vec4
    (
        vector_left->x * vector_right->x,
        vector_left->y * vector_right->y,
        vector_left->z * vector_right->z,
        vector_left->w * vector_right->w
    );
}

t_vec4
vec4_lerp(const t_vec4 *const vector1, const t_vec4 *const vector2, t_float t)
{
    return vec4
    (
        vector1->x + (vector2->x - vector1->x) * t,
        vector1->y + (vector2->y - vector1->y) * t,
        vector1->z + (vector2->z - vector1->z) * t,
        vector1->w + (vector2->w - vector1->w) * t
    );
}

t_vec4
vec4_normalize(const t_vec4 *const vector)
{
    t_float mag = vec4_length(vector);

    if (mag != 0)
    {
        return vec4(vector->x / mag, vector->y / mag, vector->z / mag, vector->w / mag);
    }

    return *vector;
}

t_vec4
vec4_scale(const t_vec4 *const vector, t_float s)
{
    return vec4(vector->x * s, vector->y * s, vector->z * s, vector->w * s);
}

void
vec4_normalize_self(t_vec4 *const vector)
{
    t_float mag = vec4_length(vector);

    if (mag != 0)
    {
        vector->x /= mag;
        vector->y /= mag;
        vector->z /= mag;
        vector->w /= mag;
    }
}

void
vec4_scale_self(t_vec4 *const vector, t_float s)
{
    vector->x *= s;
    vector->y *= s;
    vector->z *= s;
    vector->w *= s;
}

t_float
vec4_length(const t_vec4 *const vector)
{
    return sqrt(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z + vector->w * vector->w);
}

t_float
vec4_dot(const t_vec4 *const vector1, const t_vec4 *const vector2)
{
    return vector1->x * vector2->x + vector1->y * vector2->y
    + vector1->z * vector2->z + vector1->w * vector2->w;
}

t_float
vec4_distance(const t_vec4 *const vector1, const t_vec4 *const vector2)
{
    t_vec4 diff = vec4_sub(vector1, vector2);

    return vec4_length(&diff);
}

t_float
vec4_angle(const t_vec4 *const vector1, const t_vec4 *const vector2)
{
    return acos(vec4_dot(vector1, vector2) / (vec4_length(vector1) * vec4_length(vector2)));
}