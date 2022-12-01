/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:07:35 by vgiordan          #+#    #+#             */
/*   Updated: 2022/12/01 13:16:03 by vgiordan         ###   ########.fr       */
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

int	process()
{
	
	int A, B, i;
	double a, b, n = 600, x, y, t;
	float d;

	B = 0;
	while (B <= HEIGHT)
	{
		b = 0.9 - (B/n);
		A = 0;
		while (A <= WIDTH)
		{
			a = -2.2 + (A / n);
			x = 0;
			y = 0;
			i = 1;
			while(i <= 1000)
			{
				t = x;
				x = (x * x) - (y * y) + a;
				y = (2 * t * y) + b;
				d = (x * x) + (y * y);
				if ( d > 4)
					break; 
				i++;
			}
			if (i == 1001)
				mlx_pixel_put(mlx_ptr, win_ptr, A, B, 0x000000);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, A, B, (int)0xFFFFFF / (d * 100));
			A++;
		}
		B++;
	}
	return (1);
}

//gcc -I minilibx_opengl main.c -L minilibx_opengl -lmlx -framework OpenGL -framework AppKit
/*float fractal(float a, float b)
{
	float	maxIter = 20;
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
}*/

int main(int argc, char const *argv[])
{

	
	float   color;
	float	x = WIDTH;
	float	y = HEIGHT;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "FRACTAL =)");
	process();
	/*while (x > 0)
	{
		y = HEIGHT;
		while (y > 0)
		{
			color = fractal(x, y);
			mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, color * 1000);
			y--;
		}
		x--;
	}*/
	mlx_key_hook(win_ptr, key_is_pressed, (void *)0);
	mlx_loop(mlx_ptr);
	
	return 0;
}
