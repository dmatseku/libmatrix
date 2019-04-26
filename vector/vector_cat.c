#include <libmatrix.h>

int		vector_cat(t_vector *v1, t_vector *v2)
{
	if (!v1 || !v2)
		return (0);
	memcpy(v1, v2, sizeof(t_vector));
	return (1);
}
