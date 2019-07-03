/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior_memccpy.c                                 :+:      :+:    :+:   */
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
						void *(*mem)(void *, const void *, int, size_t))
{
	signal(SIGSEGV, crash_expected);
	signal(SIGBUS, crash_expected);
	if (option == 0)
		mem("", "1", 10, 1);
	if (option == 1)
		mem(NULL, NULL, 10, 1);
	if (option == 2)
		mem(NULL, "1", 10, 1);
	if (option == 3)
		mem("1", NULL, 10, 1);
	if (option == 4)
		mem(NULL, NULL, 10, 0);
	if (option == 5)
		mem(NULL, "1", 10, 0);
	if (option == 6)
		mem("1", NULL, 10, 0);
	return (10);
}

static inline int	test_memcpy_general(void *(*mem)
						(void *, const void *, int, size_t))
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
			memset(src + i - 1, 1, i);
		memset(sys_dst, 0, i);
		memset(lib_dst, 0, i);
		memccpy(sys_dst, src, 0, i);
		pc = mem(lib_dst, src, 0, i);
		if (memcmp(lib_dst, sys_dst, i))
			return (1);
		else if (pc)
			return (2);
		i++;
	}
	return (0);
}

static inline int	test_memchr_size(void *(*mem)
						(void *, const void *, int, size_t))

{
	char	src[4097];
	char	sys_dst[4097];
	char	lib_dst[4097];
	void	*pvs;
	void	*pvl;
	size_t	i;

	i = 0;
	memset(src, 1, 4097);
	memset(sys_dst, 1, 4097);
	memset(lib_dst, 1, 4097);
	while (i < 4097)
	{
		pvs = memccpy(sys_dst, src, 0, 4096);
		pvl = mem(lib_dst, src, 0, 4096);
		if (!(pvs == NULL && pvl == NULL))
		{
			if (memcmp(pvs, pvl, 4096 - i))
				return (1);
			if (memcmp(lib_dst, sys_dst, 4096))
				return (2);
		}
		if (i)
			src[i - 1] = 1;
		src[i++] = 0;
	}
	i = 0;
	memset(src, 0, 4097);
	memset(sys_dst, 0, 4097);
	memset(lib_dst, 0, 4097);
	while (i < 4097)
	{
		pvs = memccpy(sys_dst, src, 1, 4096);
		pvl = mem(lib_dst, src, 1, 4096);
		if (!(pvs == NULL && pvl == NULL))
		{
			if (memcmp(pvs, pvl, 4096 - i))
				return (3);
			if (memcmp(lib_dst, sys_dst, 4096))
				return (4);
		}
		if (i)
			src[i - 1] = 0;
		src[i++] = 1;
	}
	return (0);
}

static inline int	test_memchr_char(void *(*mem)
						(void *, const void *, int, size_t))
{
	char	src[10];
	char	ldst[10];
	char	sdst[10];
	char	*pvs;
	char	*pvl;
	size_t	i;

	memset(src, 1, 10);
	memset(ldst, 0, 10);
	memset(sdst, 0, 10);
	src[6] = 0;
	pvl = mem(ldst, src, 0, 5);
	pvs = memccpy(sdst, src, 0, 5);
	if (pvl || memcmp(ldst, sdst, 10))
		return (1);
	pvl = mem(ldst, src, 0, 10);
	pvs = memccpy(sdst, src, 0, 10);
	if (memcmp(pvl, pvs, 3) || memcmp(ldst, sdst, 10))
		return (2);
	src[8] = 0;
	pvl = mem(ldst, src, 0, 10);
	pvs = memccpy(sdst, src, 0, 10);
	if (memcmp(pvl, pvs, 3) || memcmp(ldst, sdst, 10))
		return (3);
	memset(src, 0, 10);
	i = 0;
	while (i++ < 255)
	{
		memset(ldst, 0, 10);
		memset(sdst, 0, 10);
		src[6] = i;
		pvl = mem(ldst, src, i, 5);
		pvs = memccpy(sdst, src, i, 5);
		if (pvl || memcmp(ldst, sdst, 10))
			return (1);
		pvl = mem(ldst, src, i, 10);
		pvs = memccpy(sdst, src, i, 10);
		if (memcmp(pvl, pvs, 3) || memcmp(ldst, sdst, 10))
			return (2);
		src[8] = i;
		pvl = mem(ldst, src, i, 10);
		pvs = memccpy(sdst, src, i, 10);
		if (memcmp(pvl, pvs, 3) || memcmp(ldst, sdst, 10))
			return (3);
		src[8] = 0;
	}
	return (0);
}

static inline int	test_memory(void *(*mem)
						(void *, const void *, int, size_t))
{
	void	*dst;
	void	*src;
	size_t	i;

	if (!(dst = protected_memory(4096)))
		return (-1);
	if (!(src = protected_memory(4096)))
		return (-1);
	memset(dst, 0, 4096);
	i = 0;
	while (i++ < 4096)
		ft_memccpy(dst + 4096 - i, src + 4096 - i, 1, i - 1);
	if (memcmp(dst, src, 4096))
		return (0);
	return (1);
}

static inline int	test_misaligned(void *(*mem)
						(void *, const void *, int, size_t))
{
	char	src[4097];
	char	sys_dst[4097];
	char	lib_dst[4097];
	void	*pvl;
	void	*pvs;
	size_t	i;

	i = 0;
	memset(src, 0, 4097);
	memset(src, 1, 4097);
	memset(src, 1, 4097);
	while (i < 4096)
	{
		if ((char)i)
			memset(src, (char)i, 4096);
		memset(sys_dst, 0, i);
		memset(lib_dst, 0, i);
		pvs = memccpy(sys_dst + i, src, 0, 4096 - i);
		pvl = mem(lib_dst + i, src, 0, 4096 - i );
		if (!(pvs == NULL && pvl == NULL))
		{
			if (memcmp(lib_dst, sys_dst, 4096))
				return (1);
			if (memcmp(pvl, pvs, 4096 - i))
				return (2);
		}
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
	option = av[1][0];
	ret = 10;
	if (option == '0')
		ret = test_memcpy_general(*ft_memccpy);
	else if (option == '1')
		ret = test_memcpy_general(*memccpy);
	else if (option == '2')
		ret = test_memchr_char(*ft_memccpy);
	else if (option == '3')
		ret = test_memchr_char(*memccpy);
	else if (option == '4')
		ret = test_memchr_size(*ft_memccpy);
	else if (option == '5')
		ret = test_memchr_size(*memccpy);
	else if (option == '6')
		ret = test_memory(*ft_memccpy);
	else if (option == '7')
		ret = test_memory(*memccpy);
	else if (option == '8')
		ret = test_misaligned(*ft_memccpy);
	else if (option == '9')
		ret = test_misaligned(*memccpy);
	else if (option == 'a')
		ret = test_undefined(0, *ft_memccpy);
	else if (option == 'b')
		ret = test_undefined(0, *memccpy);
	else if (option == 'c')
		ret = test_undefined(1, *ft_memccpy);
	else if (option == 'd')
		ret = test_undefined(1, *memccpy);
	else if (option == 'e')
		ret = test_undefined(2, *ft_memccpy);
	else if (option == 'f')
		ret = test_undefined(2, *memccpy);
	else if (option == 'g')
		ret = test_undefined(3, *ft_memccpy);
	else if (option == 'h')
		ret = test_undefined(3, *memccpy);
	else if (option == 'i')
		ret = test_undefined(4, *ft_memccpy);
	else if (option == 'j')
		ret = test_undefined(4, *memccpy);
	else if (option == 'k')
		ret = test_undefined(5, *ft_memccpy);
	else if (option == 'l')
		ret = test_undefined(5, *memccpy);
	else if (option == 'm')
		ret = test_undefined(6, *ft_memccpy);
	else if (option == 'n')
		ret = test_undefined(6, *memccpy);
	return (cleanup(ret));
}
