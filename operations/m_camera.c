#include <libmatrix.h>

t_matrix	*m_camera(t_vector pos, t_vector target, t_vector up)
{
	t_camera	camera;
	t_matrix	**ms;
	t_matrix	*res;

	camera.camdir = vector_normal(vector_sub_new(&pos, &target, 0), 1);
	camera.cright = vector_normal(vector_vmult(&up, camera.camdir), 1);
	camera.cup = vector_vmult(camera.camdir, camera.cright);
	CHECK((ms = (t_matrix**)malloc(sizeof(t_matrix*) * 2)));
	CHECK((ms[0] = matrix_create(4, 4)));
	CHECK((ms[1] = matrix_create(4, 4)));
	ms[0]->mat[0][0] = camera.cright->x;
	ms[0]->mat[0][1] = camera.cright->y;
	ms[0]->mat[0][2] = camera.cright->z;
	ms[0]->mat[1][0] = camera.cup->x;
	ms[0]->mat[1][1] = camera.cup->y;
	ms[0]->mat[1][2] = camera.cup->z;
	ms[0]->mat[2][0] = camera.camdir->x;
	ms[0]->mat[2][1] = camera.camdir->y;
	ms[0]->mat[2][2] = camera.camdir->z;
	ms[1]->mat[0][3] = -pos.x;
	ms[1]->mat[1][3] = -pos.y;
	ms[1]->mat[2][3] = -pos.z;
	res = matrix_mult(ms[0], ms[1]);
	matrix_free(ms[0]);
	matrix_free(ms[1]);
	FREE(ms);
	FREE(camera.camdir);
	FREE(camera.cright);
	FREE(camera.cup);
	return (res);
}
