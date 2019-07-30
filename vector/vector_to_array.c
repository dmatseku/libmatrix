#include <vector.h>

float*	vector_to_array(t_vector *const vector)
{
	float *const res = (float*)malloc(sizeof(float) * 4);

	if (!res)
		return (0);
	res[0] = vector->x;
	res[1] = vector->y;
	res[2] = vector->z;
	res[3] = vector->w;
	return (res);
}
