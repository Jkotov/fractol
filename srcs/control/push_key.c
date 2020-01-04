/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:53:29 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/04 17:59:35 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		keyboard_move(int key, t_control *p)
{
	if (key == 124)
		p->p->args.shift_x += 100 / p->p->args.zoom;
	if (key == 123)
		p->p->args.shift_x -= 100/ p->p->args.zoom;
	if (key == 126)
		p->p->args.shift_y += 100/ p->p->args.zoom;
	if (key == 125)
		p->p->args.shift_y -= 100/ p->p->args.zoom;
	draw(*p->p);
}

/*void		keyboard_rotate(int key, t_control *p)
{
	if (key == 86)
		p->p->angle_x = p->p->angle_x - M_PI / 36;
	if (key == 88)
		p->p->angle_x = p->p->angle_x + M_PI / 36;
	if (key == 84)
		p->p->angle_y = p->p->angle_y - M_PI / 36;
	if (key == 91)
		p->p->angle_y = p->p->angle_y + M_PI / 36;
	if (key == 83)
		p->p->angle_z = p->p->angle_z - M_PI / 36;
	if (key == 92)
		p->p->angle_z = p->p->angle_z + M_PI / 36;
	draw(*(p->map), *(p->p));
}
*/
void		key_zoom(int key, t_control *p, int x, int y)
{
	/*if (key == 78 || key == 5)
	{
		p->p->args.zoom *= (float) 1.05;
		p->p->args.shift_x = (float) x * p->p->args.zoom;
	}*/
	if (key == 69 || key == 4)
	{
		/*p->p->args.shift_y = (float)y / p->p->args.zoom + (float)p->p->args.shift_y - (float)y / p->p->args.zoom * 1.10f;
		p->p->args.shift_x = (float)x / p->p->args.zoom + (float)p->p->args.shift_x - (float)x / p->p->args.zoom * 1.10f;*/

		double a = x / p->p->args.zoom + p->p->args.shift_x;
		double b = y / p->p->args.zoom + p->p->args.shift_y;
		double a1 = x / (p->p->args.zoom * 1.1) + p->p->args.shift_x;
		double b1 = y / (p->p->args.zoom * 1.1) + p->p->args.shift_y;
		p->p->args.shift_x += a1 - a;
		p->p->args.shift_y += b1 - b;
		p->p->args.zoom *= (float) 1.10;
		p->p->args.iterations += 5;
	}
	draw(*p->p);
}

int			push_key(int key, void *param)
{
	t_control *p;

	p = (t_control *)param;
	if (key == 53)
		exit(0);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		keyboard_move(key, p);
	return (0);
}
