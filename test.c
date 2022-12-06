/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:39:53 by vgiordan          #+#    #+#             */
/*   Updated: 2022/12/06 14:02:39 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../42_fractal/minilibx_opengl/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct vars
{
	void *mlx;
	void *win;	
} t_vars;


int process()
{
	
	return (0);
}

int key_is_pressed(int key, t_vars *vars)
{
	
	if (key == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return (0);
}

void	*construct_image(t_vars vars, int x, int y)
{
	int pixel_bits;
	int line_bytes;
	int endian;
	char	*buffer;
	int size = 1000;
	void *image = mlx_new_image(vars.mlx, size, size);
	

	buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	printf("Pixel Bytes %d, lines_bytes %d, endian %d\n", pixel_bits, line_bytes, endian);
	printf("BUFFER \n %s", buffer);
	
	int currentPixel;


	/*if (pixel_bits != 32)
		color = mlx_get_color_value(mlx, color);*/
	int color = 16755234;

	currentPixel = (y * line_bytes + x * 4);
	if (endian == 1)
	{
		buffer[currentPixel] = color >> 24;
		buffer[currentPixel + 1] = (color >> 16);
		buffer[currentPixel + 2] = (color >> 8);
		buffer[currentPixel + 3] = color;
	}
	else
	{
		buffer[currentPixel] = color;
		buffer[currentPixel + 1] = color >> 8;
		buffer[currentPixel + 2] = color >> 16;
		buffer[currentPixel + 3] = color >> 24;
	}
	return image;
}

int main(int argc, char const *argv[])
{
	t_vars vars;
	int size = 1000;
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, size, size, "FRACTAL =)");
	vars.mlx = mlx;
	vars.win = win;
	mlx_key_hook(vars.win, key_is_pressed, &vars);
	

	/*while (x < size)
	{
		y = 0;
		while (y < size)
		{
			buffer[x * 4 + y * line_bytes] = color;
			y++;
		}
		x++;
	}*/
	
	//printf("BUFFER \n %s", buffer);
	void *image = construct_image(vars, 100, 100);
	mlx_put_image_to_window(mlx, win, image, 0, 0);
	mlx_loop(mlx);
	return 0;
}
