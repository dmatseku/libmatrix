#include <vector.h>
#include <math.h>

t_vec3
vec3_add(const t_vec3 *const vector_left, const t_vec3 *const vector_right)
{
    return vec3
    (
        vector_left->x + vector_right->x,
        vector_left->y + vector_right->y,
        vector_left->z + vector_right->z
    );
}

t_vec3
vec3_sub(const t_vec3 *const vector_left, const t_vec3 *const vector_right)
{
    return vec3
    (
        vector_left->x - vector_right->x,
        vector_left->y - vector_right->y,
        vector_left->z - vector_right->z
    );
}

t_vec3
vec3_mult(const t_vec3 *const vector_left, const t_vec3 *const vector_right)
{
    return vec3
    (
        vector_left->x * vector_right->x,
        vector_left->y * vector_right->y,
        vector_left->z * vector_right->z
    );
}

t_vec3
vec3_cross(const t_vec3 *const vector_left, const t_vec3 *const vector_right)
{
    return vec3
    (
        vector_left->y * vector_right->z - vector_left->z * vector_right->y,
        vector_left->z * vector_right->x - vector_left->x * vector_right->z,
        vector_left->x * vector_right->y - vector_left->y * vector_right->x
    );
}

t_vec3
vec3_lerp(const t_vec3 *const vector1, const t_vec3 *const vector2, t_float t)
{
    return vec3
    (
        vector1->x + (vector2->x - vector1->x) * t,
        vector1->y + (vector2->y - vector1->y) * t,
        vector1->z + (vector2->z - vector1->z) * t
    );
}

t_vec3
vec3_normalize(const t_vec3 *const vector)
{
    t_float mag = vec3_length(vector);

    if (mag != 0)
    {
        return vec3(vector->x / mag, vector->y / mag, vector->z / mag);
    }

    return *vector;
}

t_vec3
vec3_scale(const t_vec3 *const vector, t_float s)
{
    return vec3(vector->x * s, vector->y * s, vector->z * s);
}

void
vec3_normalize_self(t_vec3 *const vector)
{
    t_float mag = vec3_length(vector);

    if (mag != 0)
    {
        vector->x /= mag;
        vector->y /= mag;
        vector->z /= mag;
    }
}

void
vec3_scale_self(t_vec3 *const vector, t_float s)
{
    vector->x *= s;
    vector->y *= s;
    vector->z *= s;
}

t_float
vec3_length(const t_vec3 *const vector)
{
    return sqrt(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z);
}

t_float
vec3_dot(const t_vec3 *const vector1, const t_vec3 *const vector2)
{
    return vector1->x * vector2->x + vector1->y * vector2->y + vector1->z * vector2->z;
}

t_float
vec3_distance(const t_vec3 *const vector1, const t_vec3 *const vector2)
{
    t_vec3 diff = vec3_sub(vector1, vector2);

    return vec3_length(&diff);
}

t_float
vec3_angle(const t_vec3 *const vector1, const t_vec3 *const vector2)
{
    t_float dot, left_length, right_length;

    dot = vec3_dot(vector1, vector2);
    left_length = vec3_length(vector1);
    right_length = vec3_length(vector2);

    return acos(dot / (left_length * right_length));
}