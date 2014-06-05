#ifndef __LIB_H__
#define __LIB_H__

#ifndef NULL
#define NULL		(void*)0
#endif

#ifndef BUFF_SIZE
#define BUFF_SIZE	1024
#endif

#include "point.h"
#include "matrice.h"
#include "macro.h"
#include "error.h"
#include "buffer.h"

int	id_atoi(char* str);
int	id_error(char* str);
int	id_perror(char* str);
int	id_strlen(char* str);
int	id_strcmp(char* s1, char* s2);
int	id_printstr(char* str, int fd);
int	id_atoi_move(char* str, int* i);
int	send_fct(t_buffer* buffer, int fd);
int	fill_dup_buf(char** buf, char* str);
int	is_in_charset(char c, char* charset);
int	char_is_in(char* str, char* charset);
int	id_printnstr(char* str, int fd, int w);
int	id_strncmp(char* s1, char* s2, int len);
int	replace_value(char** str, char* new_str);
int	id_strlen_charset(char* str, char* charset);
int	id_str_sep_str(char** str1, char* str2, char* sep);
void	id_printnbr(int n);
void	id_printchar(char c);
void	id_wordtabfree(char** val);
void	id_printnbr_fd(int n, int fd);
void	id_print(const char* str, ...);
void	skip_charset(char** str, char* charset);
void	get_mat_translation(MATRICE* mat, t_point* p);
void	mat_mult(MATRICE* mat, t_point* p, t_point* dest);
void	div_vector(t_vector* v, t_vector* dest, double n);
void	mult_vector(t_vector* v, t_vector* dest, double n);
void	add_vector(t_vector* u, t_vector* v, t_vector* dest);
void	sub_vector(t_vector* u, t_vector* v, t_vector* dest);
void	sum_matrix(t_matrice* m1, t_matrice* m2, t_matrice* dest);
void	sud_matrix(t_matrice* m1, t_matrice* m2, t_matrice* dest);
void	get_mat_rotation(MATRICE* mat, t_point* a, t_point* b, t_point* c);
void*	id_memset(void* s, int c, unsigned int n);
void*	id_memcpy(void* dest, const void* src, unsigned int n);
char*	id_itoa(int i);
char*	id_getline(int fd);
char*	id_ltoa(long int i);
char*	id_strdup(char* str);
char*	id_strcat(char* s1, char* s2);
char*	id_strcpy(char* s1, char* s2);
char*	id_strndup(char* s1, unsigned int i);
char*	id_strncat(char* s1, char* s2, int n);
char*	id_strncpy(char* s1, char* s2, int n);
char*	str_sep_str(char* path, char* file_name, char* sep);
char**	id_strwordtab(char* str, char* charset, int* nbword);
double	id_pow(double x, int y);
void	m4_pointmult(double* res, double point[4], double mat[4][4]);
void	copy_vector(t_vector* ret, t_vector* v);

#endif
