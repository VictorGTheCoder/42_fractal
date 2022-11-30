/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:07:35 by vgiordan          #+#    #+#             */
/*   Updated: 2022/11/30 18:37:07 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../42_fractal/minilibx_opengl/mlx.h"
#include "header.h"

void    *mlx_ptr;
void    *win_ptr;

int key_is_pressed(int key, void *param)
{
	
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(mlx_ptr, win_ptr);
		exit(1);
	}
	return (0);
}

float fractal(float a, float b)
{
	float	maxIter = 100;
	float	i = 0;

	while (i < maxIter)
	{
		a = a*a - b*b;
		b = 2*a*b;
		if (a*a + b*b > 4)
			return (i/maxIter);
		i++;
	}
	return (1);
}

int main(int argc, char const *argv[])
{
	float   color;
	float	x = WIDTH;
	float	y = HEIGHT;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "FRACTAL =)");

	while (x > 0)
	{
		y = HEIGHT;
		while (y > 0)
		{
			color = fractal(x, y);
			mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, color * 100000);
		}
	}
	mlx_key_hook(win_ptr, key_is_pressed, (void *)0);
	mlx_loop(mlx_ptr);
	
	return 0;
}
	