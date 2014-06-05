#ifndef __MATRIX_H__
#define __MATRIX_H__

typedef struct	s_transformation
{
	double	move[16];
	double	rotation_x[16];
	double	rotation_y[16];
	double	rotation_z[16];
	double	rotation_all[16];
	double	rotation_align_z[16];
	char	is_move;
	char	is_rotation_x;
	char	is_rotation_y;
	char	is_rotation_z;
	char	is_rotation_all;
	char	is_rotation_align_z;
}	t_transformation;

typedef struct	s_point	t_vector;

void	align_z(t_transformation* t, t_vector* v);
void	matrix_mult(double* m1, t_vector* v, t_vector* r, char is_vec);
void	get_rotation_all_matrix(t_transformation* t, t_vector* u, t_vector* v);
void	get_translation_matrix(t_transformation* t, t_vector* o, t_vector* w);

#endif
