/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:10:51 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/21 17:58:00 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	color_manage(t_utils *utils, int x, int y)
{
	double	r;

	//r = mandelbrot(x, y, utils);
	r = julia(x, y, utils);
	if (r == -1)
		utils->img.color = create_trgb(0, 0, 0, 0);
	else if (r == -2)
		utils->img.color = create_trgb(0, 255, 0, 0);
	else
		utils->img.color = create_trgb(0, 5 * log(r), 30 * log(r), 50 * log(r));
}

void	fill_buffer(t_utils *utils, int endian, int current_pixel, char *buffer)
{
		buffer[current_pixel] = utils->img.color;
		buffer[current_pixel + 1] = utils->img.color >> 8;
		buffer[current_pixel + 2] = utils->img.color >> 16;
		buffer[current_pixel + 3] = utils->img.color >> 24;
}

void	*construct_image(t_utils *utils)
{
	char	*buffer;
	int		current_pixel;
	int		x;
	int		y;

	utils->img.image = mlx_new_image
		(utils->vars.mlx, utils->img.image_x_size, utils->img.image_y_size);
	buffer = mlx_get_data_addr(utils->img.image,
			&utils->img.pixel_bits, &utils->img.line_bytes, &utils->img.endian);
	x = utils->img.x_start - 1;
	if (utils->img.pixel_bits != 32)
		utils->img.color = mlx_get_color_value(utils->vars.mlx, utils->img.color);
	while (x++ < utils->img.x_end)
	{
		y = utils->img.y_start - 1;
		while (y++ < utils->img.y_end)
		{
			color_manage(utils, x, y);
			current_pixel = (y * utils->img.line_bytes + x * 4) % (
					(utils->img.image_x_size) * (utils->img.image_y_size) * 4);
			fill_buffer(utils, utils->img.endian, current_pixel, buffer);
		}
	}
	mlx_put_image_to_window(utils->vars.mlx, utils->vars.win, utils->img.image, 0, 0);
	return (utils->img.image);
}
