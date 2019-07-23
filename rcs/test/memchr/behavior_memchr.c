/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior_memchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:17:33 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/01 14:29:20 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "testing.h"
#include <string.h>
#include <stdlib.h>
#include <signal.h>

static inline int	test_memory(void *(*mem)(const void *, int, size_t))
{
	void	*map;
	size_t	i;

	if (!(map = protected_memory(4096)))
		return (ERROR);
	i = 0;
	((char *)map)[4095] = 0;
	while (i < 4096)
	{
		mem(map + 4096 - i, 1, i);
		i++;
	}
	if (((char *)map)[4095] == 0)
		return (SUCCESS);
	return (FAILURE);
}

static inline int	test_char(void *(*mem)(const void *, int, size_t))
{
	char	src[10];
	size_t	i;

	i = 0;
	memset(src, 1, 10);
	src[6] = 0;
	if (memchr(src, 0, 5) != mem(src, 0, 5))
		return (FAIL_1);
	if (memchr(src, 0, 10) != mem(src, 0, 10))
		return (FAIL_2);
	src[8] = i;
	if (memchr(src, 0, 10) != mem(src, 0, 10))
		return (FAIL_3);
	memset(src, 0, 10);
	while (i++ < 255)
	{
		src[6] = i;
		if (memchr(src, i, 5) != mem(src, i, 5))
			return (FAIL_1);
		if (memchr(src, i, 10) != mem(src, i, 10))
			return (FAIL_2);
		src[8] = i;
		if (memchr(src, i, 10) != mem(src, i, 10))
			return (FAIL_3);
		src[8] = 0;
	}
	return (SUCCESS);
}

static inline int	test_size(void *(*mem)(const void *, int, size_t))
{
	char	src[4096];
	size_t	i;

	i = 0;
	memset(src, 1, 4096);
	while (i < 4096)
	{
		if (memchr(src, 0, i) != mem(src, 0, i))
			return (FAIL_1);
		if (i)
			src[i - 1] = 1;
		src[i++] = 0;
	}
	i = 0;
	memset(src, 0, 4096);
	while (i < 4096)
	{
		if (memchr(src, 1, i) != mem(src, 1, i))
			return (FAIL_1);
		if (i)
			src[i - 1] = 0;
		src[i++] = 1;
	}
	return (SUCCESS);
}

static inline int	test_undefined(void *(*mem)(const void *, int, size_t),
						int option)
{
	void	*map;

	signal(SIGSEGV, crash_expected);
	signal(SIGBUS, crash_expected);
	if (option == '4')
		mem(NULL, 0, 0);
	else if (option == '5')
		mem(NULL, 0, 1);
	else if (option == '6')
	{
		if (!(map = protected_memory(4096)))
			return (-1);
		mem(map, 0, 4097);
	}
	return (NO_CRASH);
}


static inline int	test_misaligned(void *(*mem)(const void *, int, size_t))
{
	char	src[4096];
	void	*pvs;
	void	*pvl;
	size_t	i;

	i = 0;
	memset(src, 0xff, 4096);
	while (i < 4096)
	{
		pvs = memchr(src + i, 0, 4096 - i);
		pvl = mem(src + i, 0, 4096 - i );
		if (pvs != pvl)
			return (FAIL_1);
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
	function = (av[2][0] == '0') ? memchr : ft_memchr;
	if (option == '0')
		ret = test_char(function);
	else if (option == '1')
		ret = test_size(function);
	else if (option == '2')
		ret = test_misaligned(function);
	else if (option == '3')
		ret = test_memory(function);
	else
		ret = test_undefined(function, option);
	return (cleanup(ret, av));
}
