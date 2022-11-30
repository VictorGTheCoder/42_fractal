/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:07:35 by vgiordan          #+#    #+#             */
/*   Updated: 2022/11/30 17:15:59 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../42_fractal/minilibx_opengl/mlx.h"
#include "header.h"

void    *mlx_ptr;
void    *win_ptr;
int     max = 100;


int key_is_pressed(int key, void *param)
{
    
    if (key == KEY_ESCAPE)
    {
        mlx_destroy_window(mlx_ptr, win_ptr);
        exit(1);
    }
    return (0);
}
void    draw(void *mlx_ptr, void *win_ptr)
{
    
}

//z -> z^2 + c          z^2 = a^2 - b^2 + 2abi
int mandelbrot_fonc(float a, float b, float c, void *mlx_ptr, void *win_ptr, int color)
{
    float r = a*a - b*b + c;
    float i = 2*a*b;

    max--;
    if (max == 0)
    {
        max = 100;
        return (0);
    }
        
    //printf("INDEX : %d, r : %f, i : %f\n", max, r, i);
    //usleep(50000);
    mlx_pixel_put(mlx_ptr, win_ptr, r*10 + WIDTH/2 , i*10 + HEIGHT/2, (color));
    color += 100000;
    mandelbrot_fonc(r, i, c, mlx_ptr, win_ptr, color);
    return (0);
}

void    fractal(void *mlx_ptr, void *win_ptr)
{
    int a;
    int b;
    int i;

    int x=0;
    int y=0;

    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xe54f6e);
            y++;
        }
        x++;
    }
    
}

int main(int argc, char const *argv[])
{
    int i;
    float a = 1;
    float b;
    float c = 0;
    int color = 0;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "FRACTAL =)");
    mlx_key_hook(win_ptr, key_is_pressed, (void *)0);
    //fractal(mlx_ptr, win_ptr);
    while (a > 0)
    {   b = 1;
        while (b > 0)
        {
            mandelbrot_fonc(a, b, c, mlx_ptr, win_ptr, color);
            color += 50000;
            b -= 0.001;
        }
        a -= 0.001;
    }
    
    mlx_loop(mlx_ptr);
    
    return 0;
}
    