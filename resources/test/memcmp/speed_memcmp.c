/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_memcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 09:37:16 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/07 17:31:15 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <libft.h>
# include <time.h>
# include <string.h>
# include <stdlib.h>

size_t	memcmp_speed_test(int len, int second, int (mem)(const void *, const void *, size_t))
{
	clock_t			chrono = 0;
	clock_t			start = 0;
	size_t			i = 0;
	void			*src;
	void			*dst;

	src = malloc(len + 1);
	dst = malloc(len + 1);
	if (!dst || !src)
		exit(1);
	memset(src, 0xff, len + 1);
	memset(dst, 0xff, len + 1);
	((char *)src)[len] = 0;
	start = clock();
	while (chrono < second * CLOCKS_PER_SEC)
	{
		mem(dst, src, len);
		i++;
		chrono = clock() - start;
	}
	free(src);
	free(dst);
	return (i);
}

int	main(int ac, char **av)
{
	int		size;
	size_t	n;
	size_t	d;

	size = atoi(av[1]);
	printf("%-7d: ", size);
	n = memcmp_speed_test(size, 5, *ft_memcmp);
	d = memcmp_speed_test(size, 5, *memcmp);
	printf("%.f%%\n", (n + 0.0) / (d + 0.0) * 100);
	return (0);
}
