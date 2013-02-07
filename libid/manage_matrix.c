#include "lib.h"
#include "matrice.h"

void	sum_matrix(t_matrice* m1, t_matrice* m2, t_matrice* dest)
{
	dest->a.x = m1->a.x + m2->a.x;
	dest->a.y = m1->a.y + m2->a.y;
	dest->a.z = m1->a.z + m2->a.z;
	dest->a.homogeneous = m1->a.homogeneous + m2->a.homogeneous;
	dest->b.x = m1->b.x + m2->b.x;
	dest->b.y = m1->b.y + m2->b.y;
	dest->b.z = m1->b.z + m2->b.z;
	dest->b.homogeneous = m1->b.homogeneous + m2->b.homogeneous;
	dest->c.x = m1->c.x + m2->c.x;
	dest->c.y = m1->c.y + m2->c.y;
	dest->c.z = m1->c.z + m2->c.z;
	dest->c.homogeneous = m1->c.homogeneous + m2->c.homogeneous;
	dest->p.x = m1->p.x + m2->p.x;
	dest->p.y = m1->p.y + m2->p.y;
	dest->p.z = m1->p.z + m2->p.z;
	dest->p.homogeneous = m1->p.homogeneous + m2->p.homogeneous;
}

void	sud_matrix(t_matrice* m1, t_matrice* m2, t_matrice* dest)
{
	dest->a.x = m1->a.x - m2->a.x;
	dest->a.y = m1->a.y - m2->a.y;
	dest->a.z = m1->a.z - m2->a.z;
	dest->a.homogeneous = m1->a.homogeneous - m2->a.homogeneous;
	dest->b.x = m1->b.x - m2->b.x;
	dest->b.y = m1->b.y - m2->b.y;
	dest->b.z = m1->b.z - m2->b.z;
	dest->b.homogeneous = m1->b.homogeneous - m2->b.homogeneous;
	dest->c.x = m1->c.x - m2->c.x;
	dest->c.y = m1->c.y - m2->c.y;
	dest->c.z = m1->c.z - m2->c.z;
	dest->c.homogeneous = m1->c.homogeneous - m2->c.homogeneous;
	dest->p.x = m1->p.x - m2->p.x;
	dest->p.y = m1->p.y - m2->p.y;
	dest->p.z = m1->p.z - m2->p.z;
	dest->p.homogeneous = m1->p.homogeneous - m2->p.homogeneous;
}

void	mat_mult(MATRICE* mat, t_point* p, t_point* dest)
{
	dest->x = (mat->a.x * p->x) +
		  (mat->b.x * p->y) +
		  (mat->c.x * p->z) +
		  (mat->p.x * p->homogeneous);
	dest->y = (mat->a.y * p->x) +
		  (mat->b.y * p->y) +
		  (mat->c.y * p->z) +
		  (mat->p.y * p->homogeneous);
	dest->z = (mat->a.z * p->x) +
		  (mat->b.z * p->y) +
		  (mat->c.z * p->z) +
		  (mat->p.z * p->homogeneous);
	dest->homogeneous = (mat->a.homogeneous * p->x) +
			    (mat->b.homogeneous * p->y) +
			    (mat->c.homogeneous * p->z) +
			    (mat->p.homogeneous * p->homogeneous);
}

void	get_mat_translation(MATRICE* mat, t_point* p)
{
	id_memset(mat, 0, sizeof(*mat));
	mat->a.x = 1;
	mat->b.y = 1;
	mat->c.z = 1;
	mat->p.x = p->x;
	mat->p.y = p->y;
	mat->p.z = p->z;
	mat->p.homogeneous = p->homogeneous;
}

void	get_mat_rotation(MATRICE* mat, t_point* a, t_point* b, t_point* c)
{
	id_memset(mat, 0, sizeof(*mat));
	mat->a.x = a->x;
	mat->a.y = a->y;
	mat->a.z = a->z;
	mat->b.x = b->x;
	mat->b.y = b->y;
	mat->b.z = b->z;
	mat->c.x = c->x;
	mat->c.y = c->y;
	mat->c.z = c->z;
}
