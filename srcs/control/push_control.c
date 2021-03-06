/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:57:27 by epainter          #+#    #+#             */
/*   Updated: 2020/01/02 17:22:10 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"
#include <X11/X.h>

void	push_control(t_params *p)
{
	t_control	*control;
	t_mouse		*mouse;

	control = malloc(sizeof(t_control));
	control->p = p;
	mouse = malloc(sizeof(t_mouse));
	control->mouse = mouse;
	control->mouse->x = 0;
	control->mouse->y = 0;
	mlx_hook(p->mlx.window, 2, KeyPressMask, push_key, control);
	mlx_hook(p->mlx.window, 4, ButtonPressMask, push_mouse, control);
	mlx_hook(p->mlx.window, 5, ButtonPressMask, repush_mouse, control);
	mlx_hook(p->mlx.window, 6, PointerMotionMask, move_mouse, control);
}
