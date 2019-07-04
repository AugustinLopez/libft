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
		return (-1);
	i = 0;
	((char *)map)[4095] = 0;
	while (i < 4096)
	{
		mem(map + 4096 - i, 1, i);
		i++;
	}
	if (((char *)map)[4095] == 0)
		return (0);
	return (1);
}

static inline int	test_char(void)
{
	char	src[10];
	size_t	i;

	i = 0;
	memset(src, 1, 10);
	src[6] = 0;
	if (memchr(src, 0, 5) != ft_memchr(src, 0, 5))
		return (1);
	if (memchr(src, 0, 10) != ft_memchr(src, 0, 10))
		return (2);
	src[8] = i;
	if (memchr(src, 0, 10) != ft_memchr(src, 0, 10))
		return (3);
	memset(src, 0, 10);
	while (i++ < 255)
	{
		src[6] = i;
		if (memchr(src, i, 5) != ft_memchr(src, i, 5))
			return (1);
		if (memchr(src, i, 10) != ft_memchr(src, i, 10))
			return (2);
		src[8] = i;
		if (memchr(src, i, 10) != ft_memchr(src, i, 10))
			return (3);
		src[8] = 0;
	}
	return (0);
}

static inline int	test_size(void)
{
	char	src[4096];
	size_t	i;

	i = 0;
	memset(src, 1, 4096);
	while (i < 4096)
	{
		if (memchr(src, 0, i) != ft_memchr(src, 0, i))
			return (1);
		if (i)
			src[i - 1] = 1;
		src[i++] = 0;
	}
	i = 0;
	memset(src, 0, 4096);
	while (i < 4096)
	{
		if (memchr(src, 1, i) != ft_memchr(src, 1, i))
			return (1);
		if (i)
			src[i - 1] = 0;
		src[i++] = 1;
	}
	return (0);
}

static inline int	test_undefined(int option,
						void *(*mem)(const void *, int, size_t))
{
	void	*map;

	signal(SIGSEGV, crash_expected);
	signal(SIGBUS, crash_expected);
	if (option == 0)
		mem(NULL, 0, 0);
	else if (option == 1)
		mem(NULL, 0, 1);
	else if (option == 2)
	{
		if (!(map = protected_memory(4096)))
			return (-1);
		mem(map, 0, 4097);
	}
	return (10);
}


static inline int	test_misaligned(void)
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
		pvl = ft_memchr(src + i, 0, 4096 - i );
		if (pvs != pvl)
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
		ret = test_char();
	else if (option == '1')
		ret = test_size();
	else if (option == 'a')
		ret = test_misaligned();
	else if (option == '2')
		ret = test_memory(*ft_memchr);
	else if (option == '3')
		ret = test_memory(*memchr);
	else if (option == '4')
		ret = test_undefined(0, *ft_memchr);
	else if (option == '5')
		ret = test_undefined(0, *memchr);
	else if (option == '6')
		ret = test_undefined(1, *ft_memchr);
	else if (option == '7')
		ret = test_undefined(1, *memchr);
	else if (option == '8')
		ret = test_undefined(2, *ft_memchr);
	else if (option == '9')
		ret = test_undefined(2, *memchr);
	return (cleanup(ret));
}
