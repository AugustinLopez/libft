/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior_memset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:17:33 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/07 16:24:48 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "testing.h"
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

static inline int	test_valid_conversion(void *(*mem)(void *, int, size_t))
{
	char	buf[10];
	char	cmp[10];
	int		c;
	size_t	n;

	n = 0;
	while (n < 10)
	{
		c = -1000;
		if ((unsigned char)c == 0)
			memset(buf, 1, 10);
		else
			memset(buf, 0, 10);
		memcpy(cmp, buf, 10);
		while (c < 1001)
		{
			if ((buf != mem(buf, c, n + 1)))
				return (FAIL_1);
			memset(cmp, c, n + 1);
			if (memcmp(buf, cmp, 10))
				return (FAIL_2);
			++c;
		}
		++n;
	}
	return (SUCCESS);
}

static inline int	test_valid_size(void *(*mem)(void *, int, size_t))
{
	char	buf[4096];
	char	cmp[4096];
	size_t	n;

	n = 0;
	while (n < 4096)
	{
		memset(cmp, 0, 4096);
		memset(buf, 0, 4096);
		if (buf != mem(buf, 1, n))
			return (FAIL_1);
		memset(cmp, 1, n);
		if (memcmp(buf, cmp, n))
			return (FAIL_2);
		n++;
	}
	return (SUCCESS);
}

static inline int	test_valid_memory(void *(*mem)(void *, int, size_t))
{
	void	*map;
	size_t	len;

	if (!(map = protected_memory(4096)))
		return (ERROR);
	len = 1;
	memset(map, 0, 4096);
	while (len < 4097)
	{
		mem(map + 4096 - len, 1, len);
		++len;
	}
	if (*(char *)map != 1)
		return (FAIL_1);
	return (SUCCESS);
}

static inline int	test_undefined(void *(*mem)(void *, int, size_t),
						int option)
{
	void	*map;

	signal(SIGSEGV, crash_expected);
	signal(SIGBUS, crash_expected);
	if (option == '3')
		mem(NULL, 0, 0);
	else if (option == '4')
		mem(NULL, 0, 1);
	else if (option == '5')
		mem("abc", 0, 3);
	else if (option == '6')
	{
		if (!(map = protected_memory(4096)))
			return (ERROR);
		mem(map + 4096, 0, 1);
	}
	else
		return (SUCCESS);
	return (NO_CRASH);
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
	function = (av[2][0] == '0') ? memset : ft_memset;
	if (option == '0')
		ret = test_valid_conversion(function);
	else if (option == '1')
		ret = test_valid_size(function);
	else if (option == '2')
		ret = test_valid_memory(function);
	else
		ret = test_undefined(function, option);
	return (cleanup(ret, av));
}
