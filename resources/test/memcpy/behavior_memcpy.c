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

static inline int	test_undefined(void *(*mem)(void *, const void *, size_t),
						int option)
{
	signal(SIGSEGV, crash_expected);
	signal(SIGBUS, crash_expected);
	if (option == '3')
		mem("", "1", 1);
	if (option == '4')
		mem(NULL, NULL, 1);
	if (option == '5')
		mem(NULL, "1", 1);
	if (option == '6')
		mem("1", NULL, 1);
	if (option == '7')
		mem(NULL, NULL, 0);
	if (option == '8')
		mem(NULL, "1", 0);
	if (option == '9')
		mem("1", NULL, 0);
	return (NO_CRASH);
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
			return (FAIL_1);
		else if (pc != lib_dst)
			return (FAIL_2);
		i++;
	}
	return (SUCCESS);
}

static inline int	test_memory(void *(*mem)(void *, const void *, size_t))
{
	void	*dst;
	void	*src;
	size_t	i;

	if (!(dst = protected_memory(4096)))
		return (ERROR);
	if (!(src = protected_memory(4096)))
		return (ERROR);
	i = 0;
	while (i++ < 4096)
		mem(dst + 4096 - i, src + 4096 - i, i);
	if (!memcmp(dst, src, 4096))
		return (SUCCESS);
	return (FAIL_1);
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
			return (FAIL_1);
		else if (pc != lib_dst + i)
			return (FAIL_2);
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
	function = (av[2][0] == '0') ? memcpy : ft_memcpy;
	if (option == '0')
		ret = test_general(function);
	else if (option == '1')
		ret = test_memory(function);
	else if (option == '2')
		ret = test_misaligned(function);
	else
		ret = test_undefined(function, option);
	return (cleanup(ret, av));
}
