#include "libgraph.h"

double	fp_lerp(double v1, double v2, double t)
{
	return ((1 - t) * v1 + t * v2);
}

int	fp_lerpcolor(int color1, int color2, double t)
{
	int	red[3];
	int	green[3];
	int	blue[3];

	red[0] = (color1 >> 16) & 0xFF;
	green[0] = (color1 >> 8) & 0xFF;
	blue[0] = color1 & 0xFF;
	red[1] = (color2 >> 16) & 0xFF;
	green[1] = (color2 >> 8) & 0xFF;
	blue[1] = color2 & 0xFF;
	red[2] = (int)fp_lerp(red[0], red[1], t);
	green[2] = (int)fp_lerp(green[0], green[1], t);
	blue[2] = (int)fp_lerp(blue[0], blue[1], t);
	return ((red[2] << 16) | (green[2] << 8) | blue[2]);
}
