/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 20:36:34 by epainter          #+#    #+#             */
/*   Updated: 2020/01/02 17:10:16 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(void)
{
	t_params	params;

	params = init_params();
	draw(params);
	mlx_clear_window(params.mlx.mlx, params.mlx.window);
	mlx_put_image_to_window(params.mlx.mlx,\
	params.mlx.window, params.mlx.img, 0, 0);
	push_control(&params);
	mlx_loop(params.mlx.mlx);
	clReleaseMemObject(params.cl.memobj);
	return (0);
}
