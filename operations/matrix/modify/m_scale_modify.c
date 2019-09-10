#include <operations_matrix.h>
#include <matrix.h>

void	m_scale_modify(t_matrix *const restrict matrix, const t_vector scale)
{
	matrix_set_unit(matrix);
	matrix->mat[0] = scale.x;
	matrix->mat[5] = scale.y;
	matrix->mat[10] = scale.z;
}