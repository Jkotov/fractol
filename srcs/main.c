/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 20:36:34 by epainter          #+#    #+#             */
/*   Updated: 2020/01/04 20:40:16 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
int		main(int argc, char **argv)
{
	t_params	params;

	if (argc != 2)
		usage();
	params = init_params(argv[1]);
	draw(params);
	mlx_clear_window(params.mlx.mlx, params.mlx.window);
	mlx_put_image_to_window(params.mlx.mlx,\
	params.mlx.window, params.mlx.img, 0, 0);
	push_control(&params);
	mlx_loop(params.mlx.mlx);
	clReleaseMemObject(params.cl.memobj);
	return (0);
}
