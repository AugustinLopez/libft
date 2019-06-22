# libft

The **libft** library is the first real project from the [42](https://www.42.fr) curriculum. While a 42 student rarely has access to external libraries, the use of our libft is always authorized and encouraged.

## Useful links
- The [libft PDF subject](https://github.com/AugustinLopez/libft/blob/master/rcs/libft.pdf)
- The [get_next_line PDF subject](https://github.com/AugustinLopez/libft/blob/master/rcs/get_next_line.pdf)
- The [printf PDF subject](https://github.com/AugustinLopez/libft/blob/master/rcs/ft_printf.pdf)
- The [GNU C Library Sources](https://sourceware.org/git/?p=glibc.git;a=summary)
- The [42 File Checker](https://github.com/jgigault/42FileChecker)
- The [Libftest](https://github.com/jtoty/Libftest)
- The [ft_printf checker](https://github.com/jeremiemartel/ft_printf_checker)
- The [IEEE 754 Standard for Floating-Point](https://ieeexplore.ieee.org/document/4610935)

## Available Functions
Symbol | Meaning
:-----:|:-----:
:white_large_square:| Standard C Functions.
:black_large_square:| Non Standard C Functions.
:white_circle:      | Subject Functions.
:black_circle:      | Bonus Functions.

### Print/Put Functions
- :black_large_square::white_circle:	void	ft_putchar(char c);
- :black_large_square::white_circle:	void	ft_putchar_fd(char c, int fd);
- :black_large_square::white_circle:	void	ft_putendl(char const \*s);
- :black_large_square::white_circle:	void	ft_putendl_fd(char const \*s, int fd);
- :black_large_square::white_circle:	void	ft_putnbr(int n);
- :black_large_square::white_circle:	void	ft_putnbr_fd(int n, int fd);
- :black_large_square::white_circle:	void	ft_putstr(char const \*s)
- :black_large_square::white_circle:	void	ft_putstr_fd(char const \*s, int fd);
- :white_large_square::black_circle:	int		ft_printf(const char \*format, ...);
- :white_large_square::black_circle:	int		ft_dprintf(int fd, const char \*format, ...);
- :white_large_square::black_circle:	char	\*ft_sprintf(const char \*format, ...);
- :black_large_square::black_circle:	int		ft_nprintf(const char \*format, ...);

### Raw Memory Functions
- :white_large_square::white_circle:	void	ft_memdel(void \*\*ap);
- :white_large_square::white_circle:	[ft_bzero]( https://github.com/AugustinLopez/libft/wiki/bzero )
- :white_large_square::white_circle:	[ft_memset]( https://github.com/AugustinLopez/libft/wiki/memset )
- :white_large_square::white_circle:	void	\*ft_memcpy(void \*dst, const void \*src, size_t n);
- :white_large_square::white_circle:	void	\*ft_memccpy(void \*dst, const void \*src, int c, size_t n);
- :white_large_square::white_circle:	void	\*ft_memmove(void \*dst, const void \*src, size_t len);
- :white_large_square::white_circle:	void	\*ft_memchr(const void \*s, int c, size_t n);
- :black_large_square::white_circle:	void	\*ft_memalloc(size_t size);
- :black_large_square::white_circle:	int		ft_memcmp(const void \*s1, const void \*s2, size_t n); 

### Singly Linked List Functions
- :black_large_square::white_circle:	t_list	\*ft_lstnew(void const \*content, size_t content_size); 
- :black_large_square::white_circle:	void	ft_lstdelone(t_list \*\*alst, void (\*del)(void \*, size_t));
- :black_large_square::white_circle:	void	ft_lstdel(t_list \*\*alst, void (\*del)(void \*, size_t));
- :black_large_square::white_circle:	void	ft_lstadd(t_list \*\*alst, t_list \*new);
- :black_large_square::white_circle:	void	ft_lstmap(t_list \*lst, t_list \*(\*f)(t_list \* elem));
- :black_large_square::white_circle:	void	ft_lstiter(t_list \*lst, void (\*f)(t_list \*elem));
- :black_large_square::black_circle:	void	ft_lstinsert(t_list \*\*alst, t_list \*new);
- :black_large_square::black_circle:	void	ft_lstappend(t_list \*\*alst, t_list \*new);
- :black_large_square::black_circle:	void	ft_lstfree(void \*content, size_t content_size);
- :black_large_square::black_circle:	size_t	ft_lstsize(t_list \*lst);

### Is 'A' Functions
- :white_large_square::white_circle:	int		ft_isalpha(int c);
- :white_large_square::white_circle:	int		ft_isdigit(int c);
- :white_large_square::white_circle:	int		ft_isalnum(int c);
- :white_large_square::white_circle:	int		ft_isascii(int c);
- :white_large_square::white_circle:	int		ft_isprint(int c);
- :black_large_square::black_circle:	int		ft_iswhitespace(char \*s, int ignore_line_feed);

### 'A' To 'B' Functions
- :white_large_square::white_circle:	int		ft_atoi(const char \*src);
- :white_large_square::white_circle:	int		ft_toupper(int c);
- :white_large_square::white_circle:	int		ft_tolower(int c);
- :black_large_square::white_circle:	char	\*ft_itoa(int n);
- :black_large_square::black_circle:	size_t	ft_atozu(const char \*src);

### String Search Functions
- :white_large_square::white_circle:	char	\*ft_strchr(const char \*s, int c);
- :white_large_square::white_circle:	int		ft_strcmp(const char \*s1, const char \*s2);
- :white_large_square::white_circle:	int		ft_strncmp(const char \*s1, const char \*s2, size_t n);
- :white_large_square::white_circle:	char	\*ft_strstr(const char \*haystack, const char \*needle);
- :white_large_square::white_circle:	char	\*ft_strnstr(const char \*haystack, const char \*needle, size_t len);
- :black_large_square::white_circle:	int		ft_strequ(char const \*s1, char const \*s2);
- :black_large_square::white_circle:	int		ft_strnequ(char const \*s1, char const \*s2);
- :black_large_square::black_circle:	char	\*ft_strastr(const char \*s1, const char \*s2);
- :black_large_square::black_circle:	size_t	ft_strastri(const char \*s1, const char \*s2);
- :black_large_square::black_circle:	size_t	ft_strchri(const char \*s, int c);
- :black_large_square::black_circle:	size_t	ft_strnchri(const char \*s, int c, size_t n);
- :black_large_square::black_circle:	int		ft_strlcmp(const char \*s1, const char \*s2);
- :black_large_square::black_circle:	char	\*ft_strrstr(const char \*haystack, const char \*needle);
- :black_large_square::black_circle:	char	\*ft_strrchr(const char \*s, int c);

### String Modification Functions
- :white_large_square::white_circle:	char	\*ft_strcat(char \*s1, const char \*s2);
- :white_large_square::white_circle:	char	\*ft_strncat(char \*s1, const char \*s2, size_t n);
- :white_large_square::white_circle:	char	\*ft_strlcat(char \*s1, const char \*s2, size_t n);
- :white_large_square::white_circle:	char	\*ft_strdup(const char \*s1);
- :white_large_square::white_circle:	char	\*ft_strcpy(char \*dst, const char \*src);
- :white_large_square::white_circle:	char	\*ft_strncpy(char \*dst, const char \*src, size_t len);
- :black_large_square::white_circle:	void	ft_strclr(char \*s);
- :black_large_square::white_circle:	void	ft_strdel(char \*\*as);
- :black_large_square::white_circle:	char	\*ft_strnew(size_t size);
- :black_large_square::white_circle:	char	\*ft_strsub(char const \*s, unsigned int start, size_t len);
- :black_large_square::white_circle:	char	\*ft_strjoin(char const \*s1, char const \*s2);
- :black_large_square::white_circle:	char	\*ft_strtrim(char const \*s);
- :black_large_square::white_circle:	void	ft_strtiter(char \*s, void (\*f)(char \*));
- :black_large_square::white_circle:	void	ft_striteri(char \*s, void (\*f)(unsigned int, char \*));
- :black_large_square::white_circle:	char	\*ft_strmap(char const \*s, char (\*f)(char));
- :black_large_square::white_circle:	char	\*ft_strmapi(char const \*s, char (\*f)(unsigned int, char));
- :black_large_square::black_circle:	char	\*ft_pathjoin(char const \*s1, char const \*s2);
- :black_large_square::black_circle:	void	ft_free_sarray(char \*\*\*s);

### Parsing Functions
- :black_large_square::white_circle:	char	\*\*ft_strsplit(char const \*s, char c);
- :black_large_square::black_circle:	char	\*\*ft_strssplit(char const \*s, char const \*c);
- :black_large_square::black_circle:	int		ft_gnl(const int fd, char \*\*line, int keep_n);
