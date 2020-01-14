/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:52:04 by epainter          #+#    #+#             */
/*   Updated: 2020/01/07 16:52:04 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"
#include <stdio.h>
void		keyboard_move(int key, t_control *p)
{
	if (key == 65363)
		p->p->args.shift_x -= 50 / p->p->args.zoom;
	if (key == 65361)
		p->p->args.shift_x += 50 / p->p->args.zoom;
	if (key == 65362)
		p->p->args.shift_y += 50 / p->p->args.zoom;
	if (key == 65364)
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
	if (key == 65307)
		exit(0);
	else if (key == 65361 || key == 65362 || key == 65363 || key == 65364)
		keyboard_move(key, p);
	if (key == 32)
	{
		p->p->args.is_locked = p->p->args.is_locked ? 0 : 1;
	}
	if (key == 65451 && p->p->args.color < 1)
	{
		p->p->args.color += 0.01;
		draw(*p->p);
	}
	if (key == 65453 && p->p->args.color > 0.00)
	{
		p->p->args.color -= 0.01;
		draw(*p->p);
	}
	return (0);
}
