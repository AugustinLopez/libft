 <img src="https://github.com/AugustinLopez/libft/blob/master/rcs/HT_libft.png" width="110" align="right" />
 
 # libft

The **libft** library is the first real project from the [42](https://www.42.fr) curriculum. While a 42 student rarely has access to external libraries, the use of our libft is always authorized and encouraged.

## Available Functions
- :black_medium_small_square: - Standard C Functions.
- :white_medium_small_square: - Functions from the Libft Subject.
- :arrow_up_small: - Bonus Functions.

### Print/Put Functions
- void				ft_putchar(char c); :white_medium_small_square:
- void				ft_putchar_fd(char c, int fd); :white_medium_small_square:
- void				ft_putendl(char const *s); :white_medium_small_square:
- void				ft_putendl_fd(char const *s, int fd); :white_medium_small_square:
- void				ft_putnbr(int n); :white_medium_small_square:
- void				ft_putnbr_fd(int n, int fd); :white_medium_small_square:
- void				ft_putstr(char const *s); :white_medium_small_square:
- void				ft_putstr_fd(char const *s, int fd); :white_medium_small_square:
- int					ft_printf(const char *format, ...); :black_medium_small_square:
- int					ft_dprintf(int fd, const char *format, ...); :arrow_up_small:
- int					ft_nprintf(const char *format, ...); :arrow_up_small:
- char				*ft_sprintf(const char *format, ...); :arrow_up_small:

### Raw Memory Functions
- int					ft_memcmp(const void *s1, const void *s2, size_t n); :black_medium_small_square::white_medium_small_square:
- void				ft_memdel(void **ap); :white_medium_small_square:
- void				ft_bzero(void *s, size_t n); :black_medium_small_square::white_medium_small_square:
- void				*ft_memset(void *b, int c, size_t len); :black_medium_small_square::white_medium_small_square:
- void				*ft_memcpy(void *dst, const void *src, size_t n); :black_medium_small_square::white_medium_small_square:
- void				*ft_memccpy(void *dst, const void *src, int c, size_t n); :black_medium_small_square::white_medium_small_square:
- void				*ft_memmove(void *dst, const void *src, size_t len); :black_medium_small_square::white_medium_small_square:
- void				*ft_memchr(const void *s, int c, size_t n); :black_medium_small_square::white_medium_small_square:
- void				*ft_memalloc(size_t size); :white_medium_small_square:

### Singly Linked List Functions
- t_list				*ft_lstnew(void const *content, size_t content_size); :white_medium_small_square: :arrow_up_small:
- void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t)); :white_medium_small_square: :arrow_up_small:
- void				ft_lstdel(t_list **alst, void (*del)(void *, size_t)); :white_medium_small_square: :arrow_up_small:
- void				ft_lstadd(t_list **alst, t_list *new); :white_medium_small_square: :arrow_up_small:
- void				ft_lstinsert(t_list **alst, t_list *new); :arrow_up_small:
- void				ft_lstappend(t_list **alst, t_list *new); :arrow_up_small:
- void				ft_lstfree(void *content, size_t content_size); :arrow_up_small:
- size_t				ft_lstsize(t_list *lst); :arrow_up_small:

### Is 'A' Functions
- int					ft_iswhitespace(char *s, int ignore_line_feed); :arrow_up_small:

### 'A' To 'B' Functions
- int					ft_atoi(const char *src); :black_medium_small_square::white_medium_small_square:
- char				*ft_itoa(int n); :white_medium_small_square:
- size_t				ft_atozu(const char *src); :arrow_up_small:

### String Search Functions
- char				*ft_strchr(const char *s, int c); :black_medium_small_square::white_medium_small_square:
- char				*ft_strastr(const char *s1, const char *s2); :arrow_up_small:
- size_t				ft_strastri(const char *s1, const char *s2); :arrow_up_small:
- size_t				ft_strchri(const char *s, int c); :arrow_up_small:
- size_t				ft_strnchri(const char *s, int c, size_t n); :arrow_up_small:
- size_t				ft_strlen(const char *s); :black_medium_small_square::white_medium_small_square:
- size_t				ft_wstrlen(unsigned *str); :arrow_up_small:
- size_t				ft_wcharlen(unsigned wc); :arrow_up_small:
- int					ft_strcmp(const char *s1, const char *s2); :black_medium_small_square::white_medium_small_square:
- int					ft_strncmp(const char *s1, const char *s2, size_t n); :black_medium_small_square::white_medium_small_square:
- int					ft_strlcmp(const char *s1, const char *s2); :arrow_up_small:
- char				*ft_strstr(const char *haystack, const char *needle); :black_medium_small_square::white_medium_small_square:
- char				*ft_strrstr(const char *haystack, const char *needle); :arrow_up_small:
- char				*ft_strrchr(const char *s, int c); :arrow_up_small:

### String Modification Functions
- void				ft_strclr(char *s); :white_medium_small_square:
- void				ft_strdel(char **as); :white_medium_small_square:
- char				*ft_strcat(char *s1, const char *s2); :black_medium_small_square::white_medium_small_square:
- char				*ft_strncat(char *s1, const char *s2, size_t n); :black_medium_small_square::white_medium_small_square:
- char				*ft_strdup(const char *s1); :black_medium_small_square::white_medium_small_square:
- char				*ft_strcpy(char *dst, const char *src); :black_medium_small_square::white_medium_small_square:
- char				*ft_strnew(size_t size); :white_medium_small_square:
- char				*ft_strsub(char const *s, unsigned int start, size_t len); :white_medium_small_square:
- char				*ft_strjoin(char const *s1, char const *s2); :white_medium_small_square:
- char				*ft_pathjoin(char const *s1, char const *s2); :arrow_up_small:
- void				ft_free_sarray(char ***s); :arrow_up_small:
- char				*ft_strtrim(char const *s); :white_medium_small_square:

### Parsing Functions
- int					ft_gnl(const int fd, char **line, int keep_n); :arrow_up_small:
- char				**ft_strsplit(char const *s, char c); :white_medium_small_square:
- char				**ft_strssplit(char const *s, char const *c); :arrow_up_small:

## Useful links
- The [libft PDF subject](https://github.com/AugustinLopez/libft/blob/master/rcs/libft.pdf)
- The [GNU C Library Sources](https://sourceware.org/git/?p=glibc.git;a=summary)
- The [42 File Checker](https://github.com/jgigault/42FileChecker)
- The [Libftest](https://github.com/jtoty/Libftest)
