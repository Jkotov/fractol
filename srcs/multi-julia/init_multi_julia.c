/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_multi_julia.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:10:07 by epainter          #+#    #+#             */
/*   Updated: 2020/01/07 17:26:02 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	init_multi_julia(t_params params)
{
	params.args.shift_x = 0.5;
	params.args.shift_y = 1;
	params.fractal_type = "julia";
	params = create_cl_kernel(params, "srcs/multi-julia/draw.cl");
	return (params);
}
