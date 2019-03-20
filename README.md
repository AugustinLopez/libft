# libft

The **libft** library is the first real project from the [42](https://www.42.fr) curriculum. While a 42 student rarely has access to external libraries, the use of our libft is always authorized and encouraged.

## Useful links
- The [libft PDF subject](https://github.com/AugustinLopez/libft/blob/master/rcs/libft.pdf)
- The [GNU C Library Sources](https://sourceware.org/git/?p=glibc.git;a=summary)
- The [42 File Checker](https://github.com/jgigault/42FileChecker)
- The [Libftest](https://github.com/jtoty/Libftest)

## Available Functions
- :white_large_square: - Standard C Functions.
- :black_large_square: - Non-Standard.
- :white_circle: - Functions from the Libft Subject.
- :black_circle: - Bonus Functions.

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
- :white_large_square::white_circle:	void	ft_bzero(void \*s, size_t n);
- :white_large_square::white_circle:	void	\*ft_memset(void \*b, int c, size_t len);
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
- :black_large_square::black_circle:	void	ft_lstinsert(t_list \*\*alst, t_list \*new);
- :black_large_square::black_circle:	void	ft_lstappend(t_list \*\*alst, t_list \*new);
- :black_large_square::black_circle:	void	ft_lstfree(void \*content, size_t content_size);
- :black_large_square::black_circle:	size_t	ft_lstsize(t_list \*lst);

### Is 'A' Functions
- :black_large_square::black_circle:	 	int		ft_iswhitespace(char \*s, int ignore_line_feed);

### 'A' To 'B' Functions
- :white_large_square::white_circle:	int		ft_atoi(const char \*src);
- :black_large_square::white_circle:	char	\*ft_itoa(int n);
- :black_large_square::black_circle:	size_t	ft_atozu(const char \*src);

### String Search Functions
- :white_large_square::white_circle:	char	\*ft_strchr(const char \*s, int c);
- :white_large_square::white_circle:	int		ft_strncmp(const char \*s1, const char \*s2, size_t n);
- :white_large_square::white_circle:	char	\*ft_strstr(const char \*haystack, const char \*needle);
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
- :white_large_square::white_circle:	char	\*ft_strdup(const char \*s1);
- :white_large_square::white_circle:	char	\*ft_strcpy(char \*dst, const char \*src);
- :black_large_square::white_circle:	void	ft_strclr(char \*s);
- :black_large_square::white_circle:	void	ft_strdel(char \*\*as);
- :black_large_square::white_circle:	char	\*ft_strnew(size_t size);
- :black_large_square::white_circle:	char	\*ft_strsub(char const \*s, unsigned int start, size_t len);
- :black_large_square::white_circle:	char	\*ft_strjoin(char const \*s1, char const \*s2);
- :black_large_square::white_circle:	char	\*ft_strtrim(char const \*s);
- :black_large_square::black_circle:	char	\*ft_pathjoin(char const \*s1, char const \*s2);
- :black_large_square::black_circle:	void	ft_free_sarray(char \*\*\*s);

### Parsing Functions
- :black_large_square::white_circle:	char	\*\*ft_strsplit(char const \*s, char c);
- :black_large_square::black_circle:	char	\*\*ft_strssplit(char const \*s, char const \*c);
- :black_large_square::black_circle:	int		ft_gnl(const int fd, char \*\*line, int keep_n);
