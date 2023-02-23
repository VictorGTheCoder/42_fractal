/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:46:19 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/23 15:42:39 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	on_destroy(t_utils *utils)
{
	exit(1);
}

int	mouse_event(int key, int x, int y, t_utils *utils)
{
	if (key == 3)
		random_color(utils);
	if (key == 2)
	{
		return (2);
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

int	key_pressed(int key, t_utils *utils)
{
	if (key == KEY_UPP)
		utils->max_iter += 1;
	if (key == KEY_DOWNP)
		utils->max_iter -= 1;
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(utils->vars.mlx, utils->vars.win);
		exit(1);
	}
	if (key == KEY_LEFT)
		utils->zpi.centreX -= 0.1 / utils->zpi.zoom_ratio;
	if (key == KEY_RIGHT)
		utils->zpi.centreX += 0.1 / utils->zpi.zoom_ratio;
	if (key == KEY_DOWN)
		utils->zpi.centreY += 0.1 / utils->zpi.zoom_ratio;
	if (key == KEY_UP)
		utils->zpi.centreY -= 0.1 / utils->zpi.zoom_ratio;
	return (0);
}
