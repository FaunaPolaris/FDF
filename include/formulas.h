#ifndef FORMULAS_H
# define FORMULAS_H

#include <math.h>

# define BUTTERFLY_X(t) (100 *(sin(t) * ((exp(cos(t)) - (2 * cos(4 * t)) - (pow(sin(t / 12), 5))))))
# define BUTTERFLY_Y(t) (-100 *(cos(t) * ((exp(cos(t)) - (2 * cos(4 * t)) - (pow(sin(t / 12), 5))))))

#endif
