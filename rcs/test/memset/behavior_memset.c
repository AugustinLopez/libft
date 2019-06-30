/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior_memset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:17:33 by aulopez           #+#    #+#             */
/*   Updated: 2019/06/30 16:00:04 by aulopez          ###   ########.fr       */
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

static inline void	crash_unexpected(int signo)
{
	printf("Crash\n");
	exit(EXIT_FAILURE);
}

static inline void	crash_expected(int signo)
{
	printf("Success\n");
	exit(EXIT_SUCCESS);
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

static inline int	test_size(void)
{
	char	*lib_mem;
	char	*sys_mem;
	void	*fix_ptr;
	size_t	len;

	len = 0;
	while (len < 4096)
	{
		lib_mem = (char *)malloc(sizeof(char) * (len + 1));
		sys_mem = (char *)malloc(sizeof(char) * (len + 1));
		if (!lib_mem || !sys_mem)
			return (-1);
		memset(sys_mem, (char)len, len);
		fix_ptr = ft_memset(lib_mem, (char)len, len);
		if (fix_ptr != lib_mem)
			return (1);
		else if (memcmp(sys_mem, lib_mem, len) != 0)
			return (2);
		free(lib_mem);
		free(sys_mem);
		len++;
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

	len = 0;
	chr = 0;
	ptr = NULL;
	ft_memset(ptr, chr, len);
	chr = '+';
	ft_memset(ptr, chr, len);
	len = 1;
	signal(SIGSEGV, crash_expected);
	ft_memset(ptr, chr, len);
	if (ptr)
		return (2);
	return (1);
}

static inline int	test_memory_access(void)
{
	void	*map;
	size_t	i;

	map = mmap(0, 8192, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	memset(map, 0xff, 8192);
	mprotect(map + 4096, 4096, PROT_NONE);
	i = 0;
	while (i < 4096)
	{
		ft_memset(map + 4096 - i, (char)i, i);
		i++;
	}
	i--;
	if (((char *)map)[i] == (char)i)
		return (0);
	return (1);
}

static inline int	test_char(void)
{
	char	lib_mem[8];
	char	sys_mem[8];
	void	*fix_ptr;
	int		chr;
	int		len;

	len = 8;
	chr = 0;
	while (chr < 256)
	{
		memset(sys_mem, chr, len);
		fix_ptr = ft_memset(lib_mem, chr, len);
		if (fix_ptr != lib_mem)
			return (1);
		else if (memcmp(sys_mem, lib_mem, len) != 0)
			return (2);
		chr++;
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
		ret = test_char();
	else if (option == '1')
		ret = test_size();
	else if (option == '2')
		ret = test_null_ptr();
	else if (option == '3')
		ret = test_memory_access();
	if (!ret)
		printf("Success\n");
	else
		printf("Failure: %d\n", ret);
	return (ret);
}
