#include "libgraph.h"

static void	st_rotx(double angle, double (*matrix)[3][3]);
static void	st_roty(double angle, double (*matrix)[3][3]);
static void	st_rotz(double angle, double (*matrix)[3][3]);

double	(*mtx_rotate(char axis, double angle))[3][3]
{
	double			omega;
	static double	matrix[3][3];

	omega = (angle * (M_PI / 180));
	if (axis == 'x')
		st_rotx(angle, &matrix);
	else if (axis == 'y')
		st_roty(angle, &matrix);
	else if (axis == 'z')
		st_rotz(angle, &matrix);
	else
		st_rotx(0, &matrix);
	return (&matrix);
}

static void	st_rotx(double angle, double (*matrix)[3][3])
{
	matrix[0][0][0] = 1;
	matrix[0][1][0] = 0;
	matrix[0][2][0] = 0;
	matrix[0][0][1] = 0;
	matrix[0][0][2] = 0;
	matrix[0][1][1] = cos(angle * (M_PI / 180));
	matrix[0][1][2] = -sin(angle * (M_PI / 180));
	matrix[0][2][1] = sin(angle * (M_PI / 180));
	matrix[0][2][2] = cos(angle * (M_PI / 180));
}

static void	st_roty(double angle, double (*matrix)[3][3])
{
	matrix[0][0][0] = cos(angle * (M_PI / 180));
	matrix[0][1][0] = 0;
	matrix[0][2][0] = -sin(angle * (M_PI / 180));
	matrix[0][0][1] = 0;
	matrix[0][0][2] = sin(angle * (M_PI / 180));
	matrix[0][1][1] = 1;
	matrix[0][1][2] = 0;
	matrix[0][2][1] = 0;
	matrix[0][2][2] = cos(angle * (M_PI / 180));
}

static void	st_rotz(double angle, double (*matrix)[3][3])
{
	matrix[0][0][0] = cos(angle * (M_PI / 180));
	matrix[0][1][0] = sin(angle * (M_PI / 180));
	matrix[0][2][0] = 0;
	matrix[0][0][1] = -sin(angle * (M_PI / 180));
	matrix[0][0][2] = 0;
	matrix[0][1][1] = cos(angle * (M_PI / 180));
	matrix[0][1][2] = 0;
	matrix[0][2][1] = 0;
	matrix[0][2][2] = 1;
}
