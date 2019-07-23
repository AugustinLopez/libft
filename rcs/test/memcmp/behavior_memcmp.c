/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior_memcmp.c                                  :+:      :+:    :+:   */
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

static inline int	test_undefined(int (*mem)(void *, const void *, size_t),
						int option)
{
	signal(SIGSEGV, crash_expected);
	signal(SIGBUS, crash_expected);
	if (option == '2')
		mem(NULL, NULL, 1);
	if (option == '3')
		mem(NULL, "1", 1);
	if (option == '4')
		mem("1", NULL, 1);
	if (option == '5')
		mem(NULL, NULL, 0);
	if (option == '6')
		mem(NULL, "1", 0);
	if (option == '7')
		mem("1", NULL, 0);
	return (NO_CRASH);
}

static inline int	test_char(int (*mem)(const void *, const void *, size_t))
{
	char	zero[20];
	char	comp[10];
	int		sys_ret;
	int		lib_ret;
	size_t	i;

	i = 0;
	memset(zero, 0, 20);
	memset(comp, 0, 10);
	while (i < 4096)
	{
		if (i)
			comp[(i - 1) % 10] = 0;
		comp[i % 10] = (char)i;
		if ((unsigned char)i != mem(comp, zero + 5, 10))
			return (FAIL_1);
		i++;
	}
	i = 0;
	while (i < 256)
	{
		memset(comp, (unsigned char)i, 10);
		memset(zero, (unsigned char)i, 20);
		zero[5 + i % 10] = 0;
		if ((unsigned char)i != mem(comp, zero + 5, 10))
			return (FAIL_2);
		i++;
	}

	return (SUCCESS);
}


static inline int	test_memory(int *(*mem)(const void *, const void *, size_t))
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

int					main(int ac, char **av)
{
	int		option;
	int		ret;
	void	*function;

	g_av = av;
	if (!setup(ac, av))
		return (ERROR);
	option = av[1][0];
	function = (av[2][0] == '0') ? memcmp : ft_memcmp;
	if (option == '0')
		ret = test_char(function);
	else if (option == '1')
		ret = test_memory(function);
	else
		ret = test_undefined(function, option);
	return (cleanup(ret, av));
}
