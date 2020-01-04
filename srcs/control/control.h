/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epainter <epainter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:56:43 by epainter          #+#    #+#             */
/*   Updated: 2020/01/02 16:56:53 by epainter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CONTROL_H
# define FDF_CONTROL_H

# include "fractol.h"

typedef struct	s_mouse
{
	int			press_l;
	int			press_r;
	int			x;
	int			y;
	int			x_pred;
	int			y_pred;
}				t_mouse;

typedef struct	s_control
{
	t_params			*p;
	t_mouse				*mouse;
}				t_control;

void			keyboard_move(int key, t_control *p);
void			key_zoom(int key, t_control *p, int x, int y);
int				push_key(int key, void *param);
int				push_mouse(int key, int x, int y, void *param);
int				repush_mouse(int key, int x, int y, void *param);
int				move_mouse(int x, int y, void *param);

#endif
