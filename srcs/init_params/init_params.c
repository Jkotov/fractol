/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:20:31 by epainter          #+#    #+#             */
/*   Updated: 2019/12/30 21:06:38 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	init_params(void)
{
	t_params params;

	params.cl_params = cl_init();
	params.mlx_params = mlx_params();
	params = create_cl_kernel(params);
	return (params);
}
