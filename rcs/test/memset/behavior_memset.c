/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:17:33 by aulopez           #+#    #+#             */
/*   Updated: 2019/06/14 10:17:33 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <sys/mman.h>

int		*g_c;
int		*g_l;
char	**g_ptr;

static inline void	set_global(void *ptr_mem, int *chr, int *len)
{
	g_c = chr;
	g_l = len;
	g_ptr = (char **)ptr_mem;
}

static inline void	signal_core(int signo)
{
	int	fd;

	fd = STDERR_FILENO;
	signal(signo, SIG_DFL);
	if (!g_ptr || *g_ptr)
		dprintf(fd, "Char: %d - len: %d\n", *g_c, *g_l);
	else if (g_ptr)
		dprintf(fd, "Char: %d - len: %d - ptr: %p\n", *g_c, *g_l, *g_ptr);
	raise(signo);
}

static inline void	signal_bad_access(int signo)
{
	int	fd;

	fd = STDERR_FILENO;
	signal(signo, SIG_DFL);
	dprintf(fd,
		"ft_memset: attempt to read byte on unauthorized memory area\n");
	raise(signo);
}


static inline void	signal_crash_expected(int signo)
{
	printf("Success\n");
	exit(EXIT_SUCCESS);
}

static inline void	set_core_signal(void)
{
	signal(SIGBUS, signal_core);
	signal(SIGSEGV, signal_core);
	signal(SIGABRT, signal_core);
	signal(SIGFPE, signal_core);
	signal(SIGILL, signal_core);
	signal(SIGTRAP, signal_core);
	signal(SIGSYS, signal_core);
	signal(SIGXCPU, signal_core);
	signal(SIGXFSZ, signal_core);
	signal(SIGQUIT, signal_core);
}

static inline int	invalid_test(int ac, char **av, char *valid)
{
	int	ret;

	ret = 0;
	if (ac < 2)
		ret = -1;
	else if (!strchr(valid, av[1][0]))
		ret = -2;
	if (ret == -1)
		printf("Options: [-%s]\n", valid);
	else if (ret)
		printf("test '%c' does not exists.\n", av[1][0]);
	return (ret);
}

static inline int	test_char(void)
{
	char	lib_mem[8];
	char	sys_mem[8];
	void	*fix_ptr;
	int		chr;
	int		len;

	set_global(&lib_mem, &chr, &len);
	len = 8;
	chr = 0;
	while (chr < 256)
	{
		memset(sys_mem, chr, len);
		fix_ptr = ft_memset(lib_mem, chr, len);
		if (fix_ptr != lib_mem)
		{
			dprintf(STDERR_FILENO,
				"ft_memset: char %d - len %d: return value %p. Expect %p\n",
				chr, len, fix_ptr, lib_mem);
			return (1);
		}
		else if (memcmp(sys_mem, lib_mem, len) != 0)
		{
			dprintf(STDERR_FILENO,
				"ft_memset: char %d - len %d: memory is |%s|. Expect |%s|\n",
				chr, len, lib_mem, sys_mem);
			return (2);
		}
		chr++;
	}
	return (0);
}

static inline int	test_size(void)
{
	char	*lib_mem;
	char	*sys_mem;
	void	*fix_ptr;
	int		chr;
	int		len;

	set_global(&lib_mem, &chr, &len);
	len = 0;
	chr = '+';
	while (++len < 4096 + 1)
	{
		lib_mem = (char *)malloc(sizeof(char) * (len + 1));
		sys_mem = (char *)malloc(sizeof(char) * (len + 1));
		if (!lib_mem || !sys_mem)
		{
			lib_mem == NULL ? (void)0 : free(lib_mem);
			sys_mem == NULL ? (void)0 : free(sys_mem);
			dprintf(STDERR_FILENO, "Invalid test: not enough memory\n");
		}
		memset(sys_mem, chr, len);
		fix_ptr = ft_memset(lib_mem, chr, len);
		if (fix_ptr != lib_mem)
		{
			dprintf(STDERR_FILENO,
				"ft_memset: char %d - len %d: return value %p. Expect %p\n",
				chr, len, fix_ptr, lib_mem);
			return (1);
		}
		else if (memcmp(sys_mem, lib_mem, len) != 0)
		{
			dprintf(STDERR_FILENO,
				"ft_memset: char %d - len %d: memory is |%s|.\n",
				chr, len, lib_mem);
			return (2);
		}
		free(lib_mem);
		free(sys_mem);
		len++;
	}
	return (0);
}

static inline int	test_null_len(void)
{
	char	lib_mem[10];
	char	sys_mem[10];
	void	*fix_ptr;
	int		chr;
	int		len;

	set_global(&lib_mem, &chr, &len);
	memset(lib_mem, 0, 10);
	memset(sys_mem, 0, 10);
	len = 0;
	chr = '+';
	memset(lib_mem, chr, len);
	ft_memset(lib_mem, chr, len);
	if (memcmp(sys_mem, lib_mem, len) != 0)
	{
		dprintf(STDERR_FILENO,
			"ft_memset: char %d - len %d: memory is |%s|. Expect |%s|\n",
			chr, len, lib_mem, sys_mem);
		return (2);
	}
	return (0);
}

static inline int	test_null_ptr(void)
{
	char	lib_mem[8];
	char	sys_mem[8];
	void	*ptr;
	int		chr;
	int		len;

	set_global(&ptr, &chr, &len);
	len = 0;
	chr = 0;
	ptr = NULL;
	ft_memset(ptr, chr, len);
	chr = '+';
	ft_memset(ptr, chr, len);
	len = 1;
	signal(SIGSEGV, signal_crash_expected);
	ft_memset(ptr, chr, len);
	dprintf(STDERR_FILENO,
		"ft_memset: no crash despite NULL pointer and len > 0\n");
	return (1);
}

static inline int	test_memory_access(void)
{
	void	*map;
	int		i;

	map = mmap(NULL, 8192, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
			-1, 0);
	memset(map, 0xff, 8192);
	mprotect(map + 4096, 4096, PROT_NONE);
	i = 0;
	signal(SIGSEGV, signal_bad_access);
	while (i < 4096)
	{
		ft_memset(map + 4096 - i, 0, i);
		i++;
	}
	return (0);
}

int					main(int ac, char **av)
{
	int		option;
	int		ret;

	if (invalid_test(ac, av, "01234"))
		return (0);
	set_global(0, &option, &option);
	set_core_signal();
	option = av[1][0];
	ret = 0;
	if (option == '0')
		ret = test_char();
	else if (option == '1')
		ret = test_size();
	else if (option == '2')
		ret = test_null_ptr();
	else if (option == '3')
		ret = test_null_len();
	else if (option == '4')
		ret = test_memory_access();
	if (!ret)
		printf("Success\n");
	return (ret);
}
