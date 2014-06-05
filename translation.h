#ifndef __TRANSLATION_H__
#define __TRANSLATION_H__

typedef struct	s_point			t_vector;
typedef struct	s_object		t_object;
typedef struct	s_transformation	t_transformation;

void	make_object_translation(t_object* object);
void	get_transformed_point(t_transformation* t, t_vector* o, t_vector* r);
void	get_translation_vect(t_transformation* t, t_vector* o, t_vector* r);

#endif
