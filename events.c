/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:46:19 by vgiordan          #+#    #+#             */
/*   Updated: 2023/03/01 15:39:50 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	on_destroy(t_utils *utils)
{
	exit(1);
	return (1);
}

int	mouse_event(int key, int x, int y, t_utils *utils)
{
	if (key == 2)
	{
		utils->color.color_mode += 1;
		random_color(utils);
	}
	if (key == 4)
	{
		zoom('b', utils);
		return (2);
	}
	if (key == 5)
	{
		zoom('f', utils);
		return (5);
	}
	return (1);
}

static void	space(t_utils *utils)
{
	if (utils->track == 0)
		utils->track = 1;
	else
		utils->track = 0;
}

int	key_pressed(int key, t_utils *utils)
{	
	if (key == KEY_SPACE)
		space(utils);
	if (key == E)
		utils->max_iter += 10;
	if (key == R)
		utils->max_iter -= 10;
	if (key == F)
		utils->max_iter += 1;
	if (key == G)
		utils->max_iter -= 1;
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(utils->vars.mlx, utils->vars.win);
		exit(1);
	}
	if (key == KEY_LEFT || key == A)
		utils->zpi.centrex -= 0.1 / utils->zpi.zoom_ratio;
	if (key == KEY_RIGHT || key == D)
		utils->zpi.centrex += 0.1 / utils->zpi.zoom_ratio;
	if (key == KEY_DOWN || key == S)
		utils->zpi.centrey += 0.1 / utils->zpi.zoom_ratio;
	if (key == KEY_UP || key == W)
		utils->zpi.centrey -= 0.1 / utils->zpi.zoom_ratio;
	return (0);
}
