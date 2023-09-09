#include "libgraph.h"

static void	st_rotx(double angle, double (*matrix)[3][3]);
static void	st_roty(double angle, double (*matrix)[3][3]);
static void	st_rotz(double angle, double (*matrix)[3][3]);

t_matrix	mtx_rotate(char axes, double angle)
{
	double	radian;

	if (angle > 380)
		angle -= 380
	radian = angle * (M_PI / 180);
	if (axes == 'x')
		return (st_rotx(radian));
	if (axes == 'y')
		return (st_roty(radian));
	if (axes == 'z')
		return (st_rotz(radian));
	return (mtx_null)
}

static t_matrix	st_rotx(double radian)
{
	t_matrix	m;

	m = mtx_new(3, 3);
	m.elem[0][0] = 1;
	m.elem[0][1] = 0;
	m.elem[0][2] = 0;
	m.elem[1][0] = 0;
	m.elem[1][1] = cos(radian);
	m.elem[1][2] = -sin(radian);
	m.elem[2][0] = 0;
	m.elem[2][1] = sin(radian);
	m.elem[2][2] = cos(radian);
	return (m);
}

static t_matrix	st_roty(double radian)
{
	t_matrix	m;

	m = mtx_new(3, 3);
	m.elem[0][0] = cos(radian);
	m.elem[0][1] = 0;
	m.elem[0][2] = sin(radian);
	m.elem[1][0] = 0;
	m.elem[1][1] = 1;
	m.elem[1][2] = 0;
	m.elem[2][0] = -sin(radian);
	m.elem[2][1] = 0;
	m.elem[2][2] = cos(radian);
	return (m);
}

static t_matrix	st_rotz(double radian)
{
	t_matrix	m;

	m = mtx_new(3, 3);
	m.elem[0][0] = cos(radian);
	m.elem[0][1] = -sin(radian);
	m.elem[0][2] = 0;
	m.elem[1][0] = sin(radian);
	m.elem[1][1] = cos(radian);
	m.elem[1][2] = 0;
	m.elem[2][0] = 0;
	m.elem[2][1] = 0;
	m.elem[2][2] = 1;
	return (m);
}
