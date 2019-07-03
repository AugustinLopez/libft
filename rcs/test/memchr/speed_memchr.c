/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_memchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 09:37:16 by aulopez           #+#    #+#             */
/*   Updated: 2019/06/30 09:37:16 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <time.h>
# include <string.h>
# include <stdlib.h>
# include <libft.h>

void	memchr_speed_test(int len, int second, char *buff,
						void *(mem)(const void *, int, size_t))
{
	clock_t			chrono;
	clock_t			start;
	size_t			i;

	chrono = 0;
	i = 0;
	memset(buff, 0, len);
	buff[len - 1] = 1;
	start = clock();
	while (chrono < second * CLOCKS_PER_SEC)
	{
		mem(buff, 1, len);
		i++;
		chrono = clock() - start;
	}
	printf("%zu\n", i);
}

int	main(int ac, char **av)
{
	int		size;
	char	*buff;

	if (ac < 2 || !(buff = (char *)malloc(sizeof(*buff) * (1000000 + 1))))
		return (0);
	size = atoi(av[1]);
	printf("ft_memchr: ");
	memchr_speed_test(size, 5, buff, *ft_memchr);
	printf("   memchr: ");
	memchr_speed_test(size, 5, buff, *memchr);
	free(buff);
	return (0);
}
