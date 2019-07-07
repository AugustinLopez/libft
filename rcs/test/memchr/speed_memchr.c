/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_memchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 09:37:16 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/07 17:24:38 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <libft.h>
# include <time.h>
# include <string.h>
# include <stdlib.h>

size_t	memchr_speed_test(int len, int second, void *(mem)(const void *, int, size_t))
{
	clock_t			chrono = 0;
	clock_t			start = 0;
	size_t			i = 0;
	void			*buff;

	if (!(buff = malloc(len + 1)))
		exit(1);
	memset(buff, 0, len + 1);
	((char *)buff)[len] = 1;
	start = clock();
	while (chrono < second * CLOCKS_PER_SEC)
	{
		mem(buff, 1, len + 1);
		i++;
		chrono = clock() - start;
	}
	free(buff);
	return (i);
}

int	main(int ac, char **av)
{
	int		size;
	size_t	d;
	size_t	n;

	size = atoi(av[1]);
	printf("%-7d: ", size);
	n = memchr_speed_test(size, 5, *ft_memchr);
	d = memchr_speed_test(size, 5, *memchr);
	printf("%.f%%\n", (n + 0.0) / (d + 0.0) * 100);
	return (0);
}
