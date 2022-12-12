/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:07:35 by vgiordan          #+#    #+#             */
/*   Updated: 2022/12/12 18:14:02 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
double zoom_ratio = 1;
double centreX = 0;
double centreY = 0;

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
	if (key == KEY_LEFT)
	{
		
		centreX -= 0.1/zoom_ratio;
	}
	if (key == KEY_RIGHT)
	{
		centreX += 0.1/zoom_ratio;
	}
	if (key == KEY_DOWN)
	{
		centreY += 0.1/zoom_ratio;
	}
	if (key == KEY_UP)
	{
		centreY -= 0.1/zoom_ratio;
	}
	return (0);
}

t_mp get_mouse_position(t_vars *vars)
{
	int	x;
	int	y;
	t_mp mp;

	mlx_mouse_get_pos(vars->win, &x, &y);
	mp.x = x;
	mp.y = y;
	return (mp);
}

void *process(void *v)
{	
	long *vv = (long *) (v); 
	printf("%ld\n", *vv);
	usleep(1);
	printf("%ld\n", *vv);
	return NULL;
}

int	threading(t_vars *vars, t_z	c)
{
	t_image img1;
	t_image img2;
	pthread_t t1;
	pthread_t t2;

	img1.c = c;
	img1.vars = vars;

	img1.x_start = 0;
	img1.y_start = 0;
	img1.x_end = WIDTH;
	img1.y_end = HEIGHT;

	img2.c = c;
	img2.vars = vars;

	img2.x_start = 0;
	img2.y_start = HEIGHT / 2;
	img2.x_end = WIDTH;
	img2.y_end = HEIGHT;
	
	long value1 = 8;
	long value2 = 5;

	//pthread_create(&t1, NULL, process, (void *) &value1);
	//pthread_create(&t2, NULL, process, (void *) &value2);
	//pthread_create(&t1, NULL, construct_image, (void *) &img1);
	/*printf("1");
	usleep(10000);
	pthread_create(&t2, NULL, construct_image, (void *) &img2);
	printf("2");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);*/
	clock_t t;
	t = clock();
	construct_image(&img1);
	t = clock() - t;
	t /= 1000;
	printf("Render time %ld ms\n", t);
	
	//usleep(50000);
	return (0);
}
int	loop(t_vars *vars)
{
	t_mp mp;
	t_z	c;
	int	x = 0;
	int	y = 0;

	mp = get_mouse_position(vars);
	c = pixel_in_complex(mp.x, mp.y);
	printf("%f\n", zoom_ratio);
	//printf("Mouse Position x: %d, y :%d\n", mp.x, mp.y);
	//printf("Complex Plan Position x: %f, y :%f\n", c.a, c.b);
	
	threading(vars, c);
	return (0);
}

int main(int argc, char const *argv[])
{
	double   color;
	t_vars vars;
	void	*img;
	t_z 	c;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "FRACTAL =)");
	mlx_key_hook(vars.win, key_is_pressed, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	//t_z c;
	//process(&vars, c);
	mlx_loop_hook(vars.mlx, loop, &vars);
	mlx_loop(vars.mlx);
	return 0;
}