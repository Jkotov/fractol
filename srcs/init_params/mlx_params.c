/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 21:47:51 by epainter          #+#    #+#             */
/*   Updated: 2019/12/30 21:47:51 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	mlx_params(void)
{
	t_mlx	mlx_params;
	int		bit_depth;
	int		line;
	int		endian;

	bit_depth = 32;
	line = WIN_SIZE_X;
	endian = 0;
	mlx_params.mlx = mlx_init();
	mlx_params.window = mlx_new_window(mlx_params.mlx, WIN_SIZE_X, WIN_SIZE_Y,\
	"fractol");
	mlx_params.img = mlx_new_image(mlx_params.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	mlx_params.img_data = (int*)mlx_get_data_addr(mlx_params.img,\
	&bit_depth, &line, &endian);
	return (mlx_params);
}
