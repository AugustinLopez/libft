/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior_memcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:17:33 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/02 14:23:06 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "testing.h"
#include <string.h>
#include <stdlib.h>
#include <signal.h>

static inline int	test_undefined(int option,
						void *(*mem)(void *, const void *, size_t))
{
	signal(SIGSEGV, crash_expected);
	signal(SIGBUS, crash_expected);
	if (option == 0)
		mem("", "1", 1);
	if (option == 1)
		mem(NULL, NULL, 1);
	if (option == 2)
		mem(NULL, "1", 1);
	if (option == 3)
		mem("1", NULL, 1);
	if (option == 4)
		mem(NULL, NULL, 0);
	if (option == 5)
		mem(NULL, "1", 0);
	if (option == 6)
		mem("1", NULL, 0);
	return (10);
}

static inline int	test_general(void *(*mem)(void *, const void *, size_t))
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
		pc = mem(lib_dst, src, i);
		if (memcmp(lib_dst, sys_dst, i))
			return (1);
		else if (pc != lib_dst)
			return (2);
		i++;
	}
	return (0);
}

static inline int	test_memory(void *(*mem)(void *, const void *, size_t))
{
	void	*dst;
	void	*src;
	size_t	i;

	if (!(dst = protected_memory(4096)))
		return (-1);
	if (!(src = protected_memory(4096)))
		return (-1);
	i = 0;
	while (i++ < 4096)
		mem(dst + 4096 - i, src + 4096 - i, i);
	if (!memcmp(dst, src, 4096))
		return (0);
	return (1);
}

static inline int	test_misaligned(void *(*mem)(void *, const void *, size_t))
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
		pc = mem(lib_dst + i, src, 4096 - i );
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

	if (!setup(ac, av))
		return (0);
	ret = -1;
	option = av[1][0];
	if (option == '0')
		ret = test_general(*ft_memcpy);
	else if (option == '1')
		ret = test_general(*memcpy);
	else if (option == '2')
		ret = test_memory(*ft_memcpy);
	else if (option == '3')
		ret = test_memory(*memcpy);
	else if (option == '4')
		ret = test_misaligned(*ft_memcpy);
	else if (option == '5')
		ret = test_misaligned(*memcpy);
	else if (option == '6')
		ret = test_undefined(0, *ft_memcpy);
	else if (option == '7')
		ret = test_undefined(0, *memcpy);
	else if (option == '8')
		ret = test_undefined(1, *ft_memcpy);
	else if (option == '9')
		ret = test_undefined(1, *memcpy);
	else if (option == 'a')
		ret = test_undefined(2, *ft_memcpy);
	else if (option == 'b')
		ret = test_undefined(2, *memcpy);
	else if (option == 'c')
		ret = test_undefined(3, *ft_memcpy);
	else if (option == 'd')
		ret = test_undefined(3, *memcpy);
	else if (option == 'e')
		ret = test_undefined(4, *ft_memcpy);
	else if (option == 'f')
		ret = test_undefined(4, *memcpy);
	else if (option == 'g')
		ret = test_undefined(5, *ft_memcpy);
	else if (option == 'h')
		ret = test_undefined(5, *memcpy);
	else if (option == 'i')
		ret = test_undefined(6, *ft_memcpy);
	else if (option == 'j')
		ret = test_undefined(6, *memcpy);
	return (cleanup(ret));
}
