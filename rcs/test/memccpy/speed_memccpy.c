/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_memccpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 09:37:16 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/07 17:13:11 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <libft.h>
# include <time.h>
# include <string.h>
# include <stdlib.h>

size_t	memccpy_speed_test(int len, int second, void *(mem)(void *, const void *, int, size_t))
{
	clock_t	chrono = 0;
	clock_t	start = 0;
	size_t	i = 0;
	void	*dst;
	void	*src1;
	void	*src2;

	dst = malloc(len + 1);
	src1 = malloc(len + 1);
	src2 = malloc(len + 1);
	if (!dst || !src1 || !src2)
		exit(1);
	memset(src1, 0xff, len + 1);
	memset(src2, 0, len + 1);
	memset(dst, 0, len + 1);
	((char *)src1)[len] = 0;
	((char *)src2)[len] = 0xff;
	start = clock();
	while (chrono < second * CLOCKS_PER_SEC)
	{
		if (i % 2)
			mem(dst, src1, 0, len + 1);
		else
			mem(dst, src2, 0xff, len + 1);
		i++;
		chrono = clock() - start;
	}
	free(dst);
	free(src1);
	free(src2);
	return (i);
}

int	main(int ac, char **av)
{
	int		size;
	size_t	d;
	size_t	n;

	size = atoi(av[1]);
	printf("%-7d: ", size);
	n = memccpy_speed_test(size, 5, *ft_memccpy);
	d = memccpy_speed_test(size, 5, *memccpy);
	printf("%.f%%\n", (n + 0.0) / (d + 0.0) * 100);
	return (0);
}
