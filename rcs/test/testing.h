/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:09:30 by aulopez           #+#    #+#             */
/*   Updated: 2019/07/03 13:09:30 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_H
# define TESTING_H

void	crash_unexpected(int signo);
void	crash_expected(int signo);
void	*protected_memory(int i);
int		setup(int ac, char **av);
int		cleanup(int ret);

#endif
