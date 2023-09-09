#ifndef MATRIX_H
# define MATRIX_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	int	color;
}	t_vector;

typedef struct s_matrix
{
	int	col;
	int	row;
	int	size;
	double	**elem;
}	t_matrix;


t_matrix	mtx_new(int col, int row);
t_matrix	mtx_identity(int size);
t_matrix	mtx_fromv(t_vector v, int col);
t_matrix	mtx_rotate(char axes, double angle);

t_matrix	mtx_multiply(const t_matrix a, const t_matrix b);
void		mtx_fill(t_matrix *m, char *content);
void		mtx_print(t_matrix m);

void		mtx_free(t_matrix m);
t_matrix	mtx_null(void);

#endif
