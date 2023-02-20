/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:07:35 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/20 16:56:32 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	threading(t_utils	*utils)
{
	t_image	img1;

	img1.c = utils->c;
	img1.vars = &(utils->vars);
	img1.x_start = 0;
	img1.y_start = 0;
	img1.x_end = WIDTH;
	img1.y_end = HEIGHT;
	utils->img = img1;
	construct_image(utils);
	return (0);
}

int	loop(t_utils *utils)
{
	t_mp	mp;
	t_z		c;
	int		x;
	int		y;

	x = 0;
	y = 0;
	mp = get_mouse_position(&(utils->vars));
	c = pixel_in_complex(mp.x, mp.y, (utils->zpi));
	threading(utils);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_utils	utils;

	utils_init(&utils);
	mlx_key_hook(utils.vars.win, key_pressed, &utils);
	mlx_mouse_hook(utils.vars.win, mouse_event, &utils);
	mlx_loop_hook(utils.vars.mlx, loop, &utils);
	mlx_loop(utils.vars.mlx);
	return (0);
}
