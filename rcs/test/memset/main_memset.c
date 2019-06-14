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
	signal(signo, SIG_DFL);
	if (!g_ptr || *g_ptr)
		dprintf(STDERR_FILENO, "Char: %d - len: %d\n", *g_c, *g_l);
	else if (g_ptr)
		dprintf(STDERR_FILENO, "Char: %d - len: %d - ptr: %p\n"
				, *g_c, *g_l, *g_ptr);
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

static inline double	speeder(size_t len, size_t *l, size_t *s)
{
	char	mem[100000];
	clock_t	chrono;
	clock_t	start;

	chrono = 0;
	*s = 0;
	*l = 0;
	memset(mem, 'a', len);
	start = clock();
	while (chrono < 5 * CLOCKS_PER_SEC)
	{
		memset(mem, 'a', len);
		(*s)++;
		chrono = clock() - start;
	}
	chrono = 0;
	start = clock();
	while (chrono < 5 * CLOCKS_PER_SEC)
	{
		ft_memset(mem, 'a', len);
		(*l)++;
		chrono = clock() - start;
	}
	return ((double)(*l)/(double)(*s) * 100);
}


static inline int	test_speed(void)
{
	size_t	l;
	size_t	s;

	printf("TEST_1:  (1)      ");
	printf("%6.2f%% ", speeder(1, &l, &s));
	printf("(%zu / %zu)\n", l, s);
	printf("TEST_2:  (7)      ");
	printf("%6.2f%% ", speeder(7, &l, &s));
	printf("(%zu / %zu)\n", l, s);
	printf("TEST_3:  (8)      ");
	printf("%6.2f%% ", speeder(8, &l, &s));
	printf("(%zu / %zu)\n", l, s);
	printf("TEST_4:  (64)     ");
	printf("%6.2f%% ", speeder(64, &l, &s));
	printf("(%zu / %zu)\n", l, s);
	printf("TEST_5:  (128)    ");
	printf("%6.2f%% ", speeder(128, &l, &s));
	printf("(%zu / %zu)\n", l, s);
	printf("TEST_6:  (256)    ");
	printf("%6.2f%% ", speeder(128, &l, &s));
	printf("(%zu / %zu)\n", l, s);
	printf("TEST_7:  (512)    ");
	printf("%6.2f%% ", speeder(512, &l, &s));
	printf("(%zu / %zu)\n", l, s);
	printf("TEST_8:  (1024)   ");
	printf("%6.2f%% ", speeder(1024, &l, &s));
	printf("(%zu / %zu)\n", l, s);
	printf("TEST_9:  (2048)   ");
	printf("%6.2f%% ", speeder(2048, &l, &s));
	printf("(%zu / %zu)\n", l, s);
	printf("TEST_10: (4096)   ");
	printf("%6.2f%% ", speeder(4096, &l, &s));
	printf("(%zu / %zu)\n", l, s);
	printf("TEST_11: (10000)  ");
	printf("%6.2f%% ", speeder(10000, &l, &s));
	printf("(%zu / %zu)\n", l, s);
	printf("TEST_12: (100000) ");
	printf("%6.2f%% ", speeder(100000, &l, &s));
	printf("(%zu / %zu)\n", l, s);
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
		ret = test_speed();
	if (!ret && option != '4')
		printf("Success\n");
	return (ret);
}
