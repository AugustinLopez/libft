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

static inline int	test_undefined(
						void *(*mem)(void *, const void *, int, size_t),
						int option)
{
	signal(SIGSEGV, crash_expected);
	signal(SIGBUS, crash_expected);
	if (option == '5')
		mem("", "1", 10, 1);
	if (option == '6')
		mem(NULL, NULL, 10, 1);
	if (option == '7')
		mem(NULL, "1", 10, 1);
	if (option == '8')
		mem("1", NULL, 10, 1);
	if (option == '9')
		mem(NULL, NULL, 10, 0);
	if (option == 'a')
		mem(NULL, "1", 10, 0);
	if (option == 'b')
		mem("1", NULL, 10, 0);
	return (NO_CRASH);
}

static inline int	test_memcpy_general(
						void *(*mem)(void *, const void *, int, size_t))
{
	char	src[4096];
	char	sys_dst[4096];
	char	lib_dst[4096];
	void	*pc;
	size_t	i;

	i = 0;
	pc = lib_dst;
	
	memset(src, 0, 4096);
	while (i < 4096)
	{
		if (i)
			memset(src + i - 1, 1, 4096 - i);
		memset(sys_dst, 0, i);
		memset(lib_dst, 0, i);
		memccpy(sys_dst, src, 0, i);
		pc = mem(lib_dst, src, 0, i);
		if (memcmp(lib_dst, sys_dst, i))
			return (FAIL_1);
		else if (pc)
			return (FAIL_2);
		i++;
	}
	return (SUCCESS);
}

static inline int	test_memchr_size(
						void *(*mem)(void *, const void *, int, size_t))

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
				return (FAIL_1);
			if (memcmp(lib_dst, sys_dst, 4096))
				return (FAIL_2);
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
				return (FAIL_3);
			if (memcmp(lib_dst, sys_dst, 4096))
				return (FAIL_4);
		}
		if (i)
			src[i - 1] = 0;
		src[i++] = 1;
	}
	return (SUCCESS);
}

static inline int	test_memchr_char(
						void *(*mem)(void *, const void *, int, size_t))
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
		return (FAIL_1);
	pvl = mem(ldst, src, 0, 10);
	pvs = memccpy(sdst, src, 0, 10);
	if (memcmp(pvl, pvs, 3) || memcmp(ldst, sdst, 10))
		return (FAIL_2);
	src[8] = 0;
	pvl = mem(ldst, src, 0, 10);
	pvs = memccpy(sdst, src, 0, 10);
	if (memcmp(pvl, pvs, 3) || memcmp(ldst, sdst, 10))
		return (FAIL_3);
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
			return (FAIL_1);
		pvl = mem(ldst, src, i, 10);
		pvs = memccpy(sdst, src, i, 10);
		if (memcmp(pvl, pvs, 3) || memcmp(ldst, sdst, 10))
			return (FAIL_2);
		src[8] = i;
		pvl = mem(ldst, src, i, 10);
		pvs = memccpy(sdst, src, i, 10);
		if (memcmp(pvl, pvs, 3) || memcmp(ldst, sdst, 10))
			return (FAIL_3);
		src[8] = 0;
	}
	return (SUCCESS);
}

static inline int	test_memory(
						void *(*mem)(void *, const void *, int, size_t))
{
	void	*dst;
	void	*src;
	size_t	i;

	if (!(dst = protected_memory(4096)))
		return (ERROR);
	if (!(src = protected_memory(4096)))
		return (ERROR);
	memset(dst, 0, 4096);
	i = 0;
	while (i++ < 4096)
		ft_memccpy(dst + 4096 - i, src + 4096 - i, 1, i - 1);
	memset(dst, 0xff, 4096);
	memset(src, 0xff, 4096);
	if (!memcmp(dst, src, 4096))
		return (SUCCESS);
	return (FAILURE);
}

static inline int	test_misaligned(
						void *(*mem)(void *, const void *, int, size_t))
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
				return (FAIL_1);
			if (memcmp(pvl, pvs, 4096 - i))
				return (FAIL_2);
		}
		i++;
	}
	return (SUCCESS);
}

int					main(int ac, char **av)
{
	int		option;
	int		ret;
	void	*function;

	g_av = av;
	if (!setup(ac, av))
	return (ERROR);
	option = av[1][0];
	function = (av[2][0] == '0') ? memccpy : ft_memccpy;
	if (option == '0')
		ret = test_memcpy_general(function);
	else if (option == '1')
		ret = test_memchr_char(function);
	else if (option == '2')
		ret = test_memchr_size(function);
	else if (option == '3')
		ret = test_memory(function);
	else if (option == '4')
		ret = test_misaligned(function);
	else
		ret = test_undefined(function, option);
	return (cleanup(ret, av));
}
