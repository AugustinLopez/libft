/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_memcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 09:37:16 by aulopez           #+#    #+#             */
/*   Updated: 2019/06/30 23:09:11 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <time.h>
# include <string.h>
# include <stdlib.h>
# include <libft.h>

void	memcmp_speed_test(int len, int second, char *dst, char *src,
							int (mem)(const void *, const void *, size_t))
{
	clock_t			chrono;
	clock_t			start;
	unsigned char	chr;
	size_t			i;

	chrono = 0;
	chr = 0;
	i = 0;
	memset(src, 0xff, len);
	memset(dst, 0xff, len);
	src[len - 1] = 0;
	start = clock();
	while (chrono < second * CLOCKS_PER_SEC)
	{
		mem(dst, src, len);
		i++;
		chrono = clock() - start;
	}
	printf("%zu\n", i);
}

int	main(int ac, char **av)
{
	int		size;
	char	*buff;
	char	*src;

	if (ac < 2)
		return (0);
	buff = (char *)malloc(sizeof(*buff) * (1000000 + 1));
	src = (char *)malloc(sizeof(*buff) * (1000000 + 7));
	if (buff && src)
	{
		size = atoi(av[1]);
		printf("ft_memcmp: ");
		memcmp_speed_test(size, 5, buff, src, *ft_memcmp);
		printf("   memcmp: ");
		memcmp_speed_test(size, 5, buff, src, *memcmp);
	}
	buff ? free(buff) : (void)0;
	src ? free(src) : (void)0;
	return (0);
}
