/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:12:26 by epainter          #+#    #+#             */
/*   Updated: 2019/12/16 16:36:47 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	tmp;
	int base;
	int flag;

	flag = 1;
	if (n < 0)
	{
		flag = -1;
		ft_putchar_fd('-', fd);
	}
	tmp = n;
	base = 1;
	while (tmp / 10)
	{
		tmp /= 10;
		base *= 10;
	}
	while (base)
	{
		ft_putchar_fd(flag * ((n / base) % 10) + '0', fd);
		base /= 10;
	}
}
