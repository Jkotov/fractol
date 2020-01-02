/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:53:29 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/02 18:17:18 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		keyboard_move(int key, t_control *p)
{
	if (key == 124)
		p->p->args.shift_x += 100;
	if (key == 123)
		p->p->args.shift_x -= 100;
	if (key == 126)
		p->p->args.shift_y += 100;
	if (key == 125)
		p->p->args.shift_y -= 100;
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
	if (key == 78 || key == 5)
	{
		p->p->args.zoom *= (float) 1.05;
		p->p->args.shift_x = (float) x * p->p->args.zoom;
	}
	if (key == 69 || key == 4)
	{
		p->p->args.zoom *= (float) 0.95;
		p->p->args.shift_x = (float) x * p->p->args.zoom;
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
