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

/*
** Main test: alignment, buffer over-read
** Sub test: n value.
*/

static inline int	test_valid_memory(void *(*mem)(void *, int, size_t))
{
	void	*map;
	size_t	len;

	if (!(map = protected_memory(4096)))
		return (-1);
	len = 1;
	memset(map, 0, 4096);
	while (len < 4097)
	{
		mem(map + 4096 - len, 1, len);
		++len;
	}
	if (*(char *)map != 1)
		return (1);
	return (0);
}

/*
** Main test: c value.
** Sub test: return value, n value.
*/

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
				return (1);
			memset(cmp, c, n + 1);
			if (memcmp(buf, cmp, 10))
				return (2);
			++c;
		}
		++n;
	}
	return (0);
}

/*
** Main test: n value, !n
** Sub test: return value
*/

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
			return (1);
		memset(cmp, 1, n);
		if (memcmp(buf, cmp, n))
			return (2);
		n++;
	}
	return (0);
}

/*
** Main test: undefined behavior
*/

static inline int	test_undefined(void *(*mem)(void *, int, size_t),
						int option)
{
	void	*map;

	signal(SIGSEGV, crash_expected);
	signal(SIGBUS, crash_expected);
	if (option == '0')
		mem(NULL, 0, 0);
	else if (option == '1')
		mem(NULL, 0, 1);
	else if (option == '2')
		mem("abc", 0, 3);
	else if (option == '3')
	{
		if (!(map = protected_memory(4096)))
			return (-1);
		mem(map + 4096, 0, 1);
	}
	return (10);
}

int					main(int ac, char **av)
{
	int		option;
	int		suboption;
	int		ret;
	void	*function;

	if (!setup(ac, av))
		return (0);
	ret = 10;
	option = av[1][0];
	suboption = av[3][0];
	if (av[2][0] == '0')
		function = memset;
	else
		function = ft_memset;
	if (option == '0')
		ret = test_valid_conversion(function);
	else if (option == '1')
		ret = test_valid_size(function);
	else if (option == '2')
		ret = test_valid_memory(function);
	else if (option == '3')
		ret = test_undefined(function, suboption);
	return (cleanup(ret));
}
