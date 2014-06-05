#ifndef __ROTATION_H__
#define __ROTATION_H__

enum
{
	ROTATE_X,
	ROTATE_Y,
	ROTATE_Z
};

typedef struct	s_matrix		t_matrix;
typedef struct	s_point			t_vector;
typedef struct	s_transformation	t_transformation;

void	get_rotation_matrix(t_transformation* t, double angle, char rotation);
void	rotation_to_z(t_transformation* t, t_vector* v);

#endif
