/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:57:31 by vgiordan          #+#    #+#             */
/*   Updated: 2023/03/01 15:49:54 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_put_pixel(t_utils *utils, int pixel, int color)
{
	*(int *)(utils->img.ptr + pixel) = color;
}

void	random_color(t_utils *utils)
{
	if (utils->color.color_mode == 3)
		utils->color.color_mode = 0;
	if (utils->color.color_mode == 0)
	{
		utils->color.r = 50;
		utils->color.g = 20;
		utils->color.b = 5;
	}
	if (utils->color.color_mode == 1)
	{
		utils->color.r = 5;
		utils->color.g = 20;
		utils->color.b = 50;
	}
	if (utils->color.color_mode == 2)
	{
		utils->color.r = 50;
		utils->color.g = 255;
		utils->color.b = 5;
	}
}

void	get_mouse_position(t_utils *utils)
{
	int	x;
	int	y;
	t_z	z;

	mlx_mouse_get_pos(utils->vars.win, &x, &y);
	z = pixel_in_complex(x, y, utils);
	if (utils->track)
	{
		utils->mp.x = x;
		utils->mp.y = y;
		utils->mp.cx = z.a;
		utils->mp.cy = z.b;
	}
}
