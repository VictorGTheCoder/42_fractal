/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:07:35 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/23 19:32:10 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	threading(t_utils	*utils)
{
	construct_image(utils);
	return (0);
}

void	gui(t_utils *utils)
{
	mlx_string_put(utils->vars.mlx, utils->vars.win, 10, 10, WHITE, "FPS");
	mlx_string_put(utils->vars.mlx, utils->vars.win, 70, 10, WHITE, "ZOOM");
	mlx_string_put(utils->vars.mlx, utils->vars.win, 100, 10, WHITE,
		ft_itoa(utils->zpi.zoom_ratio));
	mlx_string_put(utils->vars.mlx, utils->vars.win, 150, 10, WHITE, "Iter: ");
	mlx_string_put(utils->vars.mlx, utils->vars.win, 200, 10, WHITE,
		ft_itoa(utils->max_iter));
}

int	loop(t_utils *utils)
{
	t_mp	mp;
	t_z		c;
	int		x;
	int		y;
	clock_t	t;

	x = 0;
	y = 0;
	t = clock();
	get_mouse_position(utils);
	utils->img.fps = t;
	threading(utils);
	t = clock() - t;
	t /= 1000;
	t = 1000 / t;
	gui(utils);
	mlx_string_put(utils->vars.mlx, utils->vars.win, 40, 10, WHITE, ft_itoa(t));
	return (0);
}

void	event_handler(t_utils *utils)
{
	mlx_mouse_hook(utils->vars.win, mouse_event, utils);
	mlx_hook(utils->vars.win, 17, 0, on_destroy, utils);
	mlx_hook(utils->vars.win, 2, 0, key_pressed, utils);
	mlx_loop_hook(utils->vars.mlx, loop, utils);
	mlx_loop(utils->vars.mlx);
}

int	main(int argc, char const *argv[])
{
	t_utils	utils;

	if (argc != 2)
		ft_putstr_fd("-->mandelbrot\n-->julia\n-->swiss\n-->burning_ship", 1);
	else
	{
		if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
			utils.fract = 0;
		else if (ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0)
			utils.fract = 1;
		else if (ft_strncmp(argv[1], "swiss", ft_strlen(argv[1])) == 0)
			utils.fract = 2;
		else if (ft_strncmp(argv[1], "burning_ship", ft_strlen(argv[1])) == 0)
			utils.fract = 3;
		else
		{
			ft_putstr_fd("-->mandelbrot\n-->julia\n-->swiss\n-->burning_ship", 1);
			return (0);
		}
		utils_init(&utils);
		event_handler(&utils);
	}
	return (0);
}
