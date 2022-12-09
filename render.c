/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:10:51 by vgiordan          #+#    #+#             */
/*   Updated: 2022/12/09 15:48:26 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*construct_image(void *imgtp)
{
	int pixel_bits;
	t_image *img = imgtp;
	int line_bytes;
	int endian;
	char	*buffer;
	int color;
	int r;
	void *image = mlx_new_image(img->vars->mlx, WIDTH, HEIGHT);
	buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	
	int currentPixel;
	int x;
	int y;
	x = img->x_start;
	if (pixel_bits != 32)
		color = mlx_get_color_value(img->vars->mlx, color);
	while (x < img->x_end)
	{
		y = img->y_start;
		while (y < img->y_end)
		{
			r = julia(x, y, img->c);
			if (r == -1)
				 color = create_trgb(0, 0, 0, 0);
			else
			{
				r = r * log(log(fabs(sqrt(x*x + y*y)) / log(r)));
				color = create_trgb(0, r * 5, r * 2, r);
			}
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
			y++;
		}
		x++;
	}
	printf("BUFFER %s\n", buffer);
	mlx_put_image_to_window(img->vars->mlx, img->vars->win, image, 0, 0);
	return image;
}