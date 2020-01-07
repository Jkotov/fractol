/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:37:13 by epainter          #+#    #+#             */
/*   Updated: 2020/01/07 16:39:53 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(int code)
{
	if (code)
	{
		ft_putstr("error while set openCL values");
		exit(-1);
	}
}
