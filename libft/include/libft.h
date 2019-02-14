/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 18:15:16 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 12:29:57 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"

# define RED				"\033[0;31m"
# define BOLD_RED			"\033[1;31m"
# define GREEN 				"\033[0;32m"
# define BOLD_GREEN			"\033[1;32m"
# define YELLOW				"\033[0;33m"
# define BOLD_YELLOW		"\033[1;33m"
# define BLUE				"\033[0;34m"
# define BOLD_BLUE			"\033[1;34m"
# define MAGENTA			"\033[0;35m"
# define BOLD_MAGENTA		"\033[1;35m"
# define CYAN				"\033[0;36m"
# define BOLD_CYAN			"\033[1;36m"
# define YELLOW_HIGHT_BLACK	"\033[0;30;43m"
# define YELLOW_HIGHT_BLUE	"\033[0;34;43m"
# define BLUE_HIGHT_BLUE	"\033[0;34;46m"
# define RED_HIGHT_BLACK	"\033[0;30;41m"

void			ft_putchar(char c);
void			ft_putstr(char const *s);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnew(size_t size);
void			ft_strclr(char *s);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
int				ft_atoi(const char *nptr);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
char			*ft_strtrim(char const *s);
char			*ft_itoa(int n);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			**ft_strsplit(char const *s, char c);
int				*ft_sort_tab(int *tab, int size);
int				ft_isspace(char c);
void			ft_display_s2tab(char **tab, char c);
void			ft_free_2tab(void **tab);
char			*ft_strnjoin(char const *s1, char const *s2, size_t n);
void			*ft_realloc(void *ptr, size_t size);
void			ft_free_tab(void **tab, int n);
void			ft_error(char *str);
void			ft_putcolor(char *o_color, char *str);
int				ft_intlen(int nb);

#endif
