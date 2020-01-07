/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_burning_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:55:58 by epainter          #+#    #+#             */
/*   Updated: 2020/01/07 17:07:25 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	init_burning_ship(t_params params)
{
	params.args.shift_x = 2.5;
	params.args.shift_y = 1.5;
	params.fractal_type = "burning_ship";
	params = create_cl_kernel(params, "srcs/burning_ship/draw.cl");
	return (params);
}
