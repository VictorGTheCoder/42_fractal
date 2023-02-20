/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:10:51 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/20 17:03:53 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*construct_image(t_utils *utils)
{
	int pixel_bits;
	t_image *img;
	int line_bytes;
	int endian;
	char	*buffer;
	int color;
	double r;
	int image_x_size;
	int image_y_size;
	void *image;
	int currentPixel;
	int x;
	int y;

	img = &(utils->img);
	image_x_size = img->x_end - img->x_start;
	image_y_size = img->y_end - img->y_start;
	image = mlx_new_image(img->vars->mlx, image_x_size, image_y_size);
	buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	x = img->x_start;
	if (pixel_bits != 32)
		color = mlx_get_color_value(img->vars->mlx, color);
	while (x < img->x_end)
	{
		y = img->y_start;
		while (y < img->y_end)
		{
			r = manderbrot(x, y, utils);
			//r = julia(x, y, img->c);
			if (r == -1)
				 color = create_trgb(0, 0, 0, 0);
			else
			{
				//double smoothed = log2(log2(x * x + y * y) / 2);  // log_2(log_2(|p|))
				//int colorI = (int)(sqrt(r + 10 - smoothed) * 256) % 2048;

				//r = r * log(log(fabs(sqrt(x*x + y*y)) / log(r)));
				//color = create_trgb(0, 10 * log(r * 3), 100* log(r * 2), 1000*log(r));
				//color = (int)(0xFFFFFF) / 2048 * colorI;
				color = create_trgb(0, 5*log(r), 30 * log(r), 50 * log(r));
			}
			currentPixel = (y * line_bytes + x * 4) % ((image_x_size) * (image_y_size ) * 4);
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
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(img->vars->mlx, img->vars->win, image, img->x_start, img->y_start);
	return image;
}
