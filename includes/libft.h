/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 08:40:39 by aulopez           #+#    #+#             */
/*   Updated: 2019/03/18 15:21:29 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

typedef struct		s_list
{
	void			*pv;
	size_t			zu;
	struct s_list	*next;
}					t_list;

/*
** --- Color Macro -------------------------------------------------------------
*/

# define FT_BLACK		"\033[30m"
# define FT_RED			"\033[31m"
# define FT_GREEN		"\033[32m"
# define FT_YELLOW		"\033[33m"
# define FT_BLUE		"\033[34m"
# define FT_PURPLE		"\033[35m"
# define FT_CYAN		"\033[36m"
# define FT_WHITE		"\033[37m"
# define FT_EOC			"\033[0m"
# define FT_BOLD		"\033[1m"
# define FT_ITALIC		"\033[3m"
# define FT_UNDER		"\033[4m"
# define FT_STRIKE		"\033[9m"

/*
** --- Put Functions -----------------------------------------------------------
** To write.
*/

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_nprintf(const char *format, ...);
char				*ft_sprintf(const char *format, ...);

/*
** --- Mem Functions -----------------------------------------------------------
** To use raw memory area
*/

int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);

/*
** --- List Functions ----------------------------------------------------------
** To deal with a single-link list.
**
**
** t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
** void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstinsert(t_list **alst, t_list *new);
void				ft_lstappend(t_list **alst, t_list *new);
void				ft_lstfree(void *content, size_t content_size);
size_t				ft_lstsize(t_list *lst);

/*
** --- Is Functions ------------------------------------------------------------
** boolean return.
**
**
** int					ft_isalpha(int c);
** int					ft_isdigit(int c);
** int					ft_isalnum(int c);
** int					ft_isascii(int c);
** int					ft_isprint(int c);
*/
int					ft_iswhitespace(char *s, int ignore_line_feed);

/*
** --- Math Functions ----------------------------------------------------------
**
**
** unsigned long		ft_rand(unsigned long long seed);
** double				ft_sqrt(unsigned int i);
** int					ft_pow(unsigned int i, int e);
*/

/*
** --- To Functions ------------------------------------------------------------
** Conversion functions.
**
**
** int					ft_toupper(int c);
** int					ft_tolower(int c);
*/
int					ft_atoi(const char *src);
char				*ft_itoa(int n);
size_t				ft_atozu(const char *src);

/*
** --- String Search Functions -------------------------------------------------
** To find information with strings.
**
**
** char				*ft_strnstr(const char *haystack,
** 						const char *needle, size_t len);
** size_t			ft_strcount(const char *s, int c);
** int				ft_strequ(char const *s1, char const *s2);
** int				ft_strnequ(char const *s1, char const *s2, size_t n);
*/
char				*ft_strchr(const char *s, int c);
char				*ft_strastr(const char *s1, const char *s2);
size_t				ft_strastri(const char *s1, const char *s2);
size_t				ft_strchri(const char *s, int c);
size_t				ft_strnchri(const char *s, int c, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_wstrlen(unsigned *str);
size_t				ft_wcharlen(unsigned wc);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strlcmp(const char *s1, const char *s2);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrstr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *s, int c);

/*
** --- String Set Functions ----------------------------------------------------
**
**
**
** size_t			ft_strlcat(char *s1, const char *s2, size_t n);
** char				*ft_strncpy(char *dst, const char *src, size_t len);
** void				ft_striter(char *s, void (*f)(char*));
** void				ft_striteri(char *s, void (*f)(unsigned int, char *));
** char				*ft_strmap(char const *s, char (*f)(char));
** char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
*/

void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_pathjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
char				**ft_strssplit(char const *s, char const *c);
void				ft_free_sarray(char ***s);
char				*ft_strtrim(char const *s);

/*
** --- Other Functions ---------------------------------------------------------
** Function with unique properties.
*/

int					ft_gnl(const int fd, char **line, int keep_n);
#endif
