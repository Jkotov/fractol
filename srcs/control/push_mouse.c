/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:57:40 by epainter          #+#    #+#             */
/*   Updated: 2020/01/02 17:57:24 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

int			push_mouse(int key, int x, int y, void *param)
{
	t_control *p;

	(void)x;
	(void)y;
	p = (t_control *)param;
	if (key == 4 || key == 5)
	{
		key_zoom(key, p, x, y);
		draw(*p->p);
	}
	if (key == 1)
		p->mouse->press_l = 1;
	if (key == 2)
		p->mouse->press_r = 1;
	return (0);
}

int			repush_mouse(int key, int x, int y, void *param)
{
	t_control *p;

	(void)x;
	(void)y;
	(void)key;
	p = (t_control *)param;
	p->mouse->press_l = 0;
	p->mouse->press_r = 0;
	return (0);
}

int			move_mouse(int x, int y, void *param)
{
	t_control *p;

	p = (t_control *)param;
	p->mouse->x_pred = p->mouse->x;
	p->mouse->y_pred = p->mouse->y;
	p->mouse->x = x;
	p->mouse->y = y;
	if (p->mouse->press_l == 1)
	{
		p->p->args.shift_x = p->p->args.shift_x + (x - p->mouse->x_pred);
		p->p->args.shift_y = p->p->args.shift_y + (y - p->mouse->y_pred);
		draw(*p->p);
	}
	return (0);
}
