NAME	=	id_rt

OBJS	=	$(SRCS:.c=.o)
SRCS	=	run.c			\
		main.c			\
		init.c			\
		color.c			\
		clean.c			\
		plane.c			\
		light.c			\
		pixel.c			\
		queue.c			\
		scene.c			\
		vector.c		\
		sphere.c		\
		camera.c		\
		thread.c		\
		matrix.c		\
		object.c		\
		rotation.c		\
		cylinder.c		\
		raytracer.c		\
		plane_utils.c		\
		translation.c		\
		antialiasing.c		\
		math_function.c		\
		calculate_ray.c		\
		cylinder_utils.c	\
		raytracer_utils.c	\

LDFLAGS	=	-L./libid/ -lid -lm -lidX -pthread
CFLAGS	=	-W -Wall -Werror -Wextra

CC	=	gcc
LIBID	=	libid/libid.a

all:	$(NAME)

$(NAME): $(OBJS) $(LIBID)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(LIBID):
	make -C libid/

clean:
	rm -rf $(OBJS)
	make -s -C libid/ clean

distclean:	clean
	rm -rf $(NAME)
	make -s -C libid/ distclean

rebuild:	distclean all

debug:	CFLAGS += -g3
debug:	rebuild

.PHONY: all $(NAME) clean distclean rebuild debug
