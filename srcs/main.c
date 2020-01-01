/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 20:36:34 by epainter          #+#    #+#             */
/*   Updated: 2020/01/01 20:08:11 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(void)
{
	t_params	params;

	params = init_params();
	mlx_clear_window(params.mlx.mlx, params.mlx.window);
	params.mlx.img_data[2000] = 0xffffff;
	mlx_put_image_to_window(params.mlx.mlx,\
	params.mlx.window, params.mlx.img, 0, 0);
	mlx_loop(params.mlx.mlx);
	return (0);
}
