#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct	s_vector3d
{
	double	x;
	double	y;
	double	z;
}	t_vector3d;

typedef struct	s_vector3f
{
	float	x;
	float	y;
	float	z;
}	t_vector3f;


typedef struct	s_vector3d	Vector3D;
typedef struct	s_vector3f	Vector3F;

void		vector_normalize(Vector3D* v);
double		vector_dot(Vector3D* v1, Vector3D* v2);
Vector3D*	vector_copy(Vector3D* v);
Vector3D*	vector_sub(Vector3D* v1, Vector3D* v2);

#endif
