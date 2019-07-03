/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior_memset.c                                  :+:      :+:    :+:   */
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

static inline int	test_memory_access(void *(*mem)(void *, int, size_t))
{
	void	*map;
	size_t	i;

	if (!(map = protected_memory(4096)))
		return (-1);
	i = 0;
	while (i++ < 4096)
		mem(map + 4096 - i, (char)i, i);
	i--;
	if (((char *)map)[1] == (char)i)
		i = 0;
	else
		i = 1;
	return (i);
}

static inline int	test_general(void)
{
	char	lib_mem[4096];
	char	sys_mem[4096];
	void	*fix_ptr;
	size_t	len;

	len = 0;
	while (len < 4096)
	{
		memset(sys_mem, (char)len, len);
		fix_ptr = ft_memset(lib_mem, (char)len, len);
		if (fix_ptr != lib_mem)
			return (1);
		else if (memcmp(sys_mem, lib_mem, len) != 0)
			return (2);
		len++;
	}
	return (0);
}

static inline int	test_undefined(void *(*mem)(void *, int, size_t),
						int option)
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
		mem(map + 4096, 0, 1);
		free(map);
	}
	return (10);
}


int					main(int ac, char **av)
{
	int		option;
	int		ret;

	if (!setup(ac, av))
		return (0);
	ret = -1;
	if ((option = av[1][0]) == '0')
		ret = test_general();
	else if (option == '1')
		ret = test_memory_access(*ft_memset);
	else if (option == '2')
		ret = test_memory_access(*memset);
	else if (option == '3')
		ret = test_undefined(*ft_memset, 0);
	else if (option == '4')
		ret = test_undefined(*memset, 0);
	else if (option == '5')
		ret = test_undefined(*ft_memset, 1);
	else if (option == '6')
		ret = test_undefined(*memset, 1);
	else if (option == '7')
		ret = test_undefined(*ft_memset, 2);
	else if (option == '8')
		ret = test_undefined(*memset, 2);
	return (cleanup(ret));
}
