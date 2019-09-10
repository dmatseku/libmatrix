#include <operations_matrix.h>
#include <matrix.h>

void	m_translate_modify(t_matrix *const restrict matrix, const t_vector translate)
{
	matrix_set_unit(matrix);
	matrix->mat[12] = translate.x;
	matrix->mat[13] = translate.y;
	matrix->mat[14] = translate.z;
}