/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:12:28 by epainter          #+#    #+#             */
/*   Updated: 2020/01/07 13:13:11 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	init_julia(t_params params)
{
	params.args.shift_x = 1;
	params.args.shift_y = 1;
	params.fractal_type = "julia";
	params = create_cl_kernel(params, "srcs/julia/draw.cl");
	return (params);
}
