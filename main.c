/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:07:35 by vgiordan          #+#    #+#             */
/*   Updated: 2022/12/06 14:03:18 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../42_fractal/minilibx_opengl/mlx.h"
#include "header.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int key_is_pressed(int key, t_vars *vars)
{
	
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return (0);
}

int process(t_vars *vars, t_z c)
{	
	int	x;
	int	y;
	int	r;

	x = 0
	c.a =  - 2 + 4 * (c.a / WIDTH);
	c.b = -2 + 4 * (c.b / HEIGHT);
	//printf("Process a = %f, b = %f\n", c.a, c.b);
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			r = julia(x, y, c);
			if (r == -1)
				mlx_pixel_put(vars->mlx, vars->win, x, y, 0x000000);
			else
				mlx_pixel_put(vars->mlx, vars->win, x, y,  create_trgb(0, 20 * r, 10 * r, 5*r));
			y++;
		}
		x++;
	}
	return (0);
}

int	mouse_hook(int key, t_vars *vars)
{

	
	printf("mouse_hook\n");
	if (key == 2)
	{
		printf("key2\n");
		return (2);
	}
	return (1);
}

int	loop(t_vars *vars)
{
	t_z	c;
	int	x = 0;
	int	y = 0;

	mlx_mouse_hook(vars->win, mouse_hook, vars);

	//printf("loop\n");
	
	mlx_mouse_get_pos(vars->win, &x, &y);
	//printf("Mouse Position x: %d, y :%d\n", x, y);
	c.a = x;
	c.b = y;
	process(vars, c);
	return (0);
}



int main(int argc, char const *argv[])
{
	float   color;
	t_vars vars;
	void	*img;
	char	*relative_path = "./test.xpm";

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "FRACTAL =)");
	mlx_key_hook(vars.win, key_is_pressed, &vars);
	mlx_loop_hook(vars.mlx, loop, &vars);
	mlx_loop(vars.mlx);
	return 0;
}