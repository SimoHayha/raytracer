NAME	=	id_rt

OBJS	=	$(SRCS:.c=.o)
SRCS	=	main.c		\
		init.c		\
		setpixel.c	\
		run.c		\
		vector.c	\
		object.c	\
		camera.c	\
		sphere.c	\
		input.c

LDFLAGS	=	-L./libid/ -lid -lm -pthread `sdl-config --libs`
CFLAGS	=	-W -Wall -Werror -Wextra `sdl-config --cflags`

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
