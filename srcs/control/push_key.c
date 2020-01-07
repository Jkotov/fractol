/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:53:29 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/07 14:12:27 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		keyboard_move(int key, t_control *p)
{
	if (key == 124)
		p->p->args.shift_x -= 50 / p->p->args.zoom;
	if (key == 123)
		p->p->args.shift_x += 50 / p->p->args.zoom;
	if (key == 126)
		p->p->args.shift_y += 50 / p->p->args.zoom;
	if (key == 125)
		p->p->args.shift_y -= 50 / p->p->args.zoom;
	draw(*p->p);
}

void		key_zoom(int key, t_control *p, int x, int y)
{
	double a;
	double b;
	double a1;
	double b1;

	a = x / p->p->args.zoom + p->p->args.shift_x;
	b = y / p->p->args.zoom + p->p->args.shift_y;
	if (key == 5)
	{
		a1 = x / (p->p->args.zoom / 1.1) + p->p->args.shift_x;
		b1 = y / (p->p->args.zoom / 1.1) + p->p->args.shift_y;
		p->p->args.shift_x += a1 - a;
		p->p->args.shift_y += b1 - b;
		p->p->args.zoom /= 1.10f;
		p->p->args.iterations -= MAX_ITERATION < p->p->args.iterations ? 5 : 0;
	}
	if (key == 4)
	{
		a1 = x / (p->p->args.zoom * 1.1) + p->p->args.shift_x;
		b1 = y / (p->p->args.zoom * 1.1) + p->p->args.shift_y;
		p->p->args.shift_x += a1 - a;
		p->p->args.shift_y += b1 - b;
		p->p->args.zoom *= 1.10f;
		p->p->args.iterations += 5;
	}
}

int			push_key(int key, void *param)
{
	t_control *p;

	p = (t_control *)param;
	if (key == 53)
		exit(0);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		keyboard_move(key, p);
	if (key == 49)
	{
		p->p->args.is_locked = p->p->args.is_locked ? 0 : 1;
	}
	return (0);
}
