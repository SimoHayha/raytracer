#include "libid/lib.h"
#include "vector.h"
#include "matrix.h"
#include "object.h"

#include <stdio.h>

void	make_object_translation(t_object* object)
{
	t_vector	v_0;

	id_memset(&v_0, 0, sizeof(v_0));
	get_translation_matrix(&object->transform, &object->pos, &v_0);
}

void	get_transformed_point(t_transformation* t, t_vector* o, t_vector* r)
{
	if (!t || !o || !r)
		return ;
	if (t->is_move)
		matrix_mult(t->move, o, r, 0);
}

void	get_translation_vect(t_transformation* t, t_vector* o, t_vector* r)
{
	if (!t || !o || !r)
		return ;
	if (t->is_rotation_x)
		matrix_mult(t->rotation_x, o, r, 1);
	if (t->is_rotation_y)
		matrix_mult(t->rotation_y, o, r, 1);
	if (t->is_rotation_z)
		matrix_mult(t->rotation_z, o, r, 1);
	if (t->is_rotation_all)
		matrix_mult(t->rotation_all, o, r, 1);
}
