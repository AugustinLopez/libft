/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:37:09 by aulopez           #+#    #+#             */
/*   Updated: 2019/09/04 17:28:12 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdint.h>
# include <sys/types.h>

typedef struct		s_list
{
	void			*pv;
	size_t			zu;
	struct s_list	*next;
}					t_list;

/*
** --- Color Macro -------------------------------------------------------------
*/

# define ONE_EACH_BYTE	0x0101010101010101L
# define REV_EACH_BYTE	0x8080808080808080L
# define LOG_UINT32_MAX	10
# define LOG_UINT_MAX	LOG_UINT32_MAX
# define LOG_UINT64_MAX	20
# define POW10_LOG_SIZE_MAX 10000000000000000000UL

# define FT_EOC			"\033[0m"
# define FT_BOLD		"\033[1m"
# define FT_DIM			"\033[2m"
# define FT_ITALIC		"\033[3m"
# define FT_UNDER		"\033[4m"
# define FT_REV			"\033[7m"
# define FT_HIDE		"\033[8m"
# define FT_STRIKE		"\033[9m"
# define FT_R_BOLD		"\033[21m"
# define FT_R_DIM		"\033[22m"
# define FT_R_ITALIC	"\033[23m"
# define FT_R_UNDER		"\033[24m"
# define FT_R_REV		"\033[27m"
# define FT_R_HIDE		"\033[28m"
# define FT_R_STRIKE	"\033[29m"

# define FT_R_COLOR		"\033[39m"
# define FT_BLACK		"\033[30m"
# define FT_RED			"\033[31m"
# define FT_GREEN		"\033[32m"
# define FT_YELLOW		"\033[33m"
# define FT_BLUE		"\033[34m"
# define FT_PURPLE		"\033[35m"
# define FT_CYAN		"\033[36m"
# define FT_GRAY		"\033[90m"
# define FT_WHITE		"\033[97m"
# define FT_LGRAY		"\033[37m"
# define FT_LRED		"\033[91m"
# define FT_LGREEN		"\033[92m"
# define FT_LYELLOW		"\033[93m"
# define FT_LBLUE		"\033[94m"
# define FT_LPURPLE		"\033[95m"
# define FT_LCYAN		"\033[96m"

# define FT_R_BCOLOR	"\033[49m"
# define FT_BBLACK		"\033[40m"
# define FT_BRED		"\033[41m"
# define FT_BGREEN		"\033[42m"
# define FT_BYELLOW		"\033[43m"
# define FT_BBLUE		"\033[44m"
# define FT_BPURPLE		"\033[45m"
# define FT_BCYAN		"\033[46m"
# define FT_BGRAY		"\033[100m"
# define FT_BWHITE		"\033[107m"
# define FT_BLGRAY		"\033[47m"
# define FT_BLRED		"\033[101m"
# define FT_BLGREEN		"\033[102m"
# define FT_BLYELLOW	"\033[103m"
# define FT_BLBLUE		"\033[104m"
# define FT_BLPURPLE	"\033[105m"
# define FT_BLCYAN		"\033[106m"

/*
** --- Raw Memory Functions ----------------------------------------------------
*/

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);

/*
** --- Print/Put Functions -----------------------------------------------------
*/

ssize_t				ft_putchar(unsigned int c);
ssize_t				ft_putchar_fd(unsigned int c, int fd);
ssize_t				ft_putendl(char const *s);
ssize_t				ft_putendl_fd(char const *s, int fd);
ssize_t				ft_putnbr(int n);
ssize_t				ft_putnbr_fd(int n, int fd);
ssize_t				ft_putstr(char const *s);
ssize_t				ft_putstr_fd(char const *s, int fd);
int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
char				*ft_sprintf(const char *format, ...);
int					ft_nprintf(const char *format, ...);

/*
** --- Singly Linked List Functions --------------------------------------------
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstccpy(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstinsert(t_list **alst, t_list *new);
void				ft_lstappend(t_list **alst, t_list *new);
void				ft_lstfree(void *content, size_t content_size);
size_t				ft_lstsize(t_list *lst);

/*
** --- Is  'A' Functions -------------------------------------------------------
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
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
** --- 'A' To 'B' Functions ----------------------------------------------------
*/

int					ft_atoi(const char *src);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_itoa(int n);
size_t				ft_atozu(const char *src);

/*
** --- String Search Functions -------------------------------------------------
** size_t			ft_strcount(const char *s, int c);
*/
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strastr(const char *s1, const char *s2);
size_t				ft_strastri(const char *s1, const char *s2);
size_t				ft_strchri(const char *s, int c);
size_t				ft_strnchri(const char *s, int c, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_wstrlen(unsigned *str);
size_t				ft_wcharlen(unsigned wc);
int					ft_strlcmp(const char *s1, const char *s2);
char				*ft_strrstr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *s, int c);

/*
** --- String Set Functions ----------------------------------------------------
*/

void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_pathjoin(char const *s1, char const *s2);
void				ft_free_sarray(char ***s);

/*
** --- Parsing Functions  ------------------------------------------------------
*/

char				**ft_strsplit(char const *s, char c);
char				**ft_strssplit(char const *s, char const *c);
int					ft_gnl(const int fd, char **line, int keep_n);
int					ft_flagarg(int ac, char **av, uint32_t *flag,
						char *options);

/*
** --- Math Functions ----------------------------------------------------------
*/

int					ft_abs(int a);
#endif
