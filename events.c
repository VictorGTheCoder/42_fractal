/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:46:19 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/20 16:56:52 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	key_pressed(int key, t_utils *utils)
{
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(utils->vars.mlx, utils->vars.win);
		exit(1);
	}
	if (key == KEY_LEFT)
	{
		utils->zpi.centreX -= 0.1 / utils->zpi.zoom_ratio;
	}
	if (key == KEY_RIGHT)
	{
		utils->zpi.centreX += 0.1 / utils->zpi.zoom_ratio;
	}
	if (key == KEY_DOWN)
	{
		utils->zpi.centreY += 0.1 / utils->zpi.zoom_ratio;
	}
	if (key == KEY_UP)
	{
		utils->zpi.centreY -= 0.1 / utils->zpi.zoom_ratio;
	}
	return (0);
}
