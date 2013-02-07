NAME	=	libid.a

SRCS	=	error.c			\
		point.c			\
		buffer.c		\
		id_atoi.c		\
		id_itoa.c		\
		id_error.c		\
		id_power.c		\
		send_fct.c		\
		id_strcmp.c		\
		id_memset.c		\
		id_strdup.c		\
		id_strcpy.c		\
		id_strcat.c		\
		id_strncpy.c		\
		id_getline.c		\
		print_fcts.c		\
		id_printnbr.c		\
		str_sep_str.c		\
		mini_printf.c		\
		id_strwordtab.c		\
		buff_handling.c		\
		is_in_charset.c		\
		manage_matrix.c		\
		id_print_tools.c	\
		id_wordtabfree.c	\
		m3_inverse.c		\
		m4_inverse.c		\
		m3_mult_matcol.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Werror

CC	=	gcc
AR	=	ar
RANLIB	=	ranlib

all:	$(NAME)

$(NAME):	$(OBJS)
	$(AR) r $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

clean:
	rm -f $(OBJS)

distclean:	clean
	rm -f $(NAME)

rebuild:	distclean all

.PHONY: all clean distclean rebuild
