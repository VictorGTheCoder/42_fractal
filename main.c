/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:07:35 by vgiordan          #+#    #+#             */
/*   Updated: 2022/11/30 16:19:18 by vgiordan         ###   ########.fr       */
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
void    draw(void *mlx_ptr, void *win_ptr)
{
    
}

//f(z) = z^2 + c Pour c = 0
//a + bi = a^2 - b^2 + 2abi
//a = a^2 - b^2 && bi = 2abi => 2a = 1 => a = 1/2
//1/2 = 1/4 - b^2 => b^2 = 1/2 => b = 1/4
int mandelbrot_fonc(int x, int y)
{
    
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
            if ()
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xe54f6e);
            y++;
        }
        x++;
    }
    
}

int main(int argc, char const *argv[])
{


    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FRACTAL =)");
    mlx_pixel_put(mlx_ptr, win_ptr, 50, 50, 255255255);
    mlx_key_hook(win_ptr, key_is_pressed, (void *)0);
    fractal(mlx_ptr, win_ptr);
    mlx_loop(mlx_ptr);
    return 0;
}
    