/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:07:35 by vgiordan          #+#    #+#             */
/*   Updated: 2022/11/30 17:27:57 by vgiordan         ###   ########.fr       */
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

void fractal(float left, float top, float xside, float yside)
{
    float xscale, yscale, zx, zy, cx, tempx, cy;
    int x, y, i, j;
    int maxx, maxy, count;
  
    // getting maximum value of x-axis of screen
    maxx = 1920;
  
    // getting maximum value of y-axis of screen
    maxy = 1080;
  
    // setting up the xscale and yscale
    xscale = xside / maxx;
    yscale = yside / maxy;
  
    // scanning every point in that rectangular area.
    // Each point represents a Complex number (x + yi).
    // Iterate that complex number
    for (y = 1; y <= maxy - 1; y++) {
        for (x = 1; x <= maxx - 1; x++)
        {
            // c_real
            cx = x * xscale + left;
  
            // c_imaginary
            cy = y * yscale + top;
  
            // z_real
            zx = 0;
  
            // z_imaginary
            zy = 0;
            count = 0;
  
            // Calculate whether c(c_real + c_imaginary) belongs
            // to the Mandelbrot set or not and draw a pixel
            // at coordinates (x, y) accordingly
            // If you reach the Maximum number of iterations
            // and If the distance from the origin is
            // greater than 2 exit the loop
            while ((zx * zx + zy * zy < 50) && (count < 30))
            {
                // Calculate Mandelbrot function
                // z = z*z + c where z is a complex number
  
                // tempx = z_real*_real - z_imaginary*z_imaginary + c_real
                tempx = zx * zx - zy * zy + cx;
  
                // 2*z_real*z_imaginary + c_imaginary
                zy = 2 * zx * zy + cy;
  
                // Updating z_real = tempx
                zx = tempx;
  
                // Increment count
                count = count + 1;
            }
  
            // To display the created fractal
             mlx_pixel_put(mlx_ptr, win_ptr, x, y, 2000000*count);
        }
    }
}

/*void    fractal(void *mlx_ptr, void *win_ptr)
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
}*/

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
    fractal(-1.75, -0.25, 0.25, 0.45);
   /* while (a > 0)
    {   b = 1;
        while (b > 0)
        {
            mandelbrot_fonc(a, b, c, mlx_ptr, win_ptr, color);
            color += 50000;
            b -= 0.001;
        }
        a -= 0.001;
    }*/
    
    mlx_loop(mlx_ptr);
    
    return 0;
}
    