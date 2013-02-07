#ifndef __SPECIFIFER_ENUM_H__
#define __SPECIFIFER_ENUM_H__

typedef enum	e_specifier
{
	E_NONE,
	E_CHAR,
	E_STR,
	E_INT,
	E_PTR,
	E_SIZE
}	t_specifier;

typedef void	(*function)(va_list* a_list);

#endif
