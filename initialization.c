/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:00:29 by vgiordan          #+#    #+#             */
/*   Updated: 2023/03/01 14:34:07 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	utils_init(t_utils *utils)
{
	utils->max_iter = MAXITER;
	utils->zpi.centrex = 0;
	utils->zpi.centrey = 0;
	utils->zpi.zoom_ratio = 1;
	utils->vars.mlx = mlx_init();
	utils->vars.win = mlx_new_window(utils->vars.mlx, WIDTH, HEIGHT, "fractol");
	utils->img.x_start = 0;
	utils->img.y_start = 0;
	utils->img.x_end = WIDTH;
	utils->img.y_end = HEIGHT;
	utils->img.image_x_size = utils->img.x_end - utils->img.x_start;
	utils->img.image_y_size = utils->img.y_end - utils->img.y_start;
	utils->img.color = 0;
	utils->color.color_mode = 0;
	utils->color.r = 5;
	utils->color.g = 20;
	utils->color.b = 50;
	utils->track = 1;
}
