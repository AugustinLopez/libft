/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior_memcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:17:33 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/01 14:34:53 by aulopez          ###   ########.fr       */
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

static inline void	crash_expected(int signo)
{
	printf("Success\n");
	exit(EXIT_SUCCESS);
}

static inline void	crash_unexpected(int signo)
{
	printf("Crash\n");
	signal(signo, SIG_DFL);
	raise(signo);
}

static inline void	set_signal(void)
{
	signal(SIGBUS, crash_unexpected);
	signal(SIGSEGV, crash_unexpected);
	signal(SIGABRT, crash_unexpected);
	signal(SIGFPE, crash_unexpected);
	signal(SIGILL, crash_unexpected);
	signal(SIGTRAP, crash_unexpected);
	signal(SIGSYS, crash_unexpected);
	signal(SIGXCPU, crash_unexpected);
	signal(SIGXFSZ, crash_unexpected);
	signal(SIGQUIT, crash_unexpected);
}

static inline int	test_general(void)
{
	char	src[4096];
	char	sys_dst[4096];
	char	lib_dst[4096];
	void	*pc;
	size_t	i;

	i = 0;
	pc = lib_dst;
	while (i < 4096)
	{
		if (i)
			memset(src + i - 1, (char)i, 1);
		memset(sys_dst, 0, i);
		memset(lib_dst, 0, i);
		memcpy(sys_dst, src, i);
		pc = ft_memcpy(lib_dst, src, i);
		if (memcmp(lib_dst, sys_dst, i))
			return (1);
		else if (pc != lib_dst)
			return (1);
		i++;
	}
	return (0);
}

static inline int	test_memory_access(void)
{
	void	*dst;
	void	*src;
	size_t	i;

	dst = mmap(0, 8192, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	src = mmap(0, 8192, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	memset(dst, 0, 8192);
	memset(src, 0xff, 8192);
	mprotect(dst + 4096, 4096, PROT_NONE);
	mprotect(src + 4096, 4096, PROT_NONE);
	i = 0;
	while (i < 4096)
	{
		ft_memcpy(dst + 4096 - i, src + 4096 - i, i);
		i++;
	}
	i--;
	if (((char *)src)[i] == ((char *)dst)[i])
		return (0);
	return (1);
}

static inline int	test_segfault(int option)
{
	signal(SIGSEGV, crash_expected);
	signal(SIGBUS, crash_expected);
	if (option == 0)
		memcpy("", "1", 1);
	if (option == 1)
		ft_memcpy(NULL, NULL, 1);
	if (option == 2)
		ft_memcpy(NULL, "1", 1);
	if (option == 3)
		ft_memcpy("1", NULL, 1);
	return (1);
}

static inline int	test_no_reaction(void)
{
	ft_memcpy(NULL, NULL, 0);
	ft_memcpy(NULL, "1", 0);
	ft_memcpy("1", NULL, 0);
	return (0);
}

static inline int	test_misaligned(void)
{
	char	src[4096];
	char	sys_dst[4096];
	char	lib_dst[4096];
	void	*pc;
	size_t	i;

	i = 0;
	pc = lib_dst;
	while (i < 4096)
	{
		if (i)
			memset(src, (char)i, 4096);
		memset(sys_dst, 0, i);
		memset(lib_dst, 0, i);
		memcpy(sys_dst + i, src, 4096 - i);
		pc = ft_memcpy(lib_dst + i, src, 4096 - i );
		if (memcmp(lib_dst, sys_dst, 4096 - i))
			return (1);
		else if (pc != lib_dst + i)
			return (1);
		i++;
	}
	return (0);

}

int					main(int ac, char **av)
{
	int		option;
	int		ret;

	if (ac < 2 || !(option = av[1][0]))
		return (0);
	ret = 10;
	set_signal();
	if (option == '0')
		ret = test_general();
	else if (option == '1')
		ret = test_memory_access();
	else if (option == '2')
		ret = test_segfault(0);
	else if (option == '3')
		ret = test_segfault(1);
	else if (option == '4')
		ret = test_segfault(2);
	else if (option == '5')
		ret = test_segfault(3);
	else if (option == '6')
		ret = test_no_reaction();
	else if (option == '7')
		ret = test_misaligned();
	if (!ret)
		printf("Success\n");
	else
		printf("Failure\n");
	return (ret);
}
