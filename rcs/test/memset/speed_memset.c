/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_memset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 09:37:16 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/07 17:10:10 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <time.h>
# include <string.h>
# include <stdlib.h>
# include <libft.h>

size_t	memset_speed_test(int len, int second,
						void *(mem)(void *, int, size_t))
{
	clock_t			chrono;
	clock_t			start;
	unsigned char	chr;
	size_t			i;
	void			*buff;

	if (!(buff = malloc(len)))
		exit(1);
	chrono = 0;
	chr = 0;
	i = 0;
	memset(buff, 0, len);
	start = clock();
	while (chrono < second * CLOCKS_PER_SEC)
	{
		mem(buff, ++chr, len);
		i++;
		chrono = clock() - start;
	}
	free(buff);
	return (i);
}

int	main(int ac, char **av)
{
	int		size;
	size_t	n;
	size_t	d;

	size = atoi(av[1]);
	printf("%-7d: ", size);
	n = memset_speed_test(size, 5, *ft_memset);
	d = memset_speed_test(size, 5, *memset);
	printf("%.f%%\n", (n + 0.0) / (d + 0.0) * 100);
	return (0);
}
