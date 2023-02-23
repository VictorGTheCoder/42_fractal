/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:10:51 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/23 15:45:49 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	color_manage(t_utils *utils, int x, int y)
{
	double	r;

	if (utils->fract == 0)
		r = mandelbrot(x, y, utils);
	else if (utils->fract == 1)
		r = julia(x, y, utils);
	else if (utils->fract == 2)
		r = croix_suisse(utils, x, y, utils->max_iter);
	else
		r = burning_ship(x, y, utils);
	if (r == -1)
		utils->img.color = create_trgb(0, 0, 0, 0);
	else if (r == -2)
		utils->img.color = create_trgb(0, 255, 0, 0);
	else if (r == -3)
		utils->img.color = create_trgb(0, 255, 255, 255);
	else
		utils->img.color = create_trgb(0, utils->color.r * log(r),
				utils->color.g * log(r), utils->color.b * log(r));
}

void	fill_buffer(t_utils *utils, int endian, int current_pixel, char *buffer)
{
		buffer[current_pixel] = (utils->img.color);
		buffer[current_pixel + 1] = (utils->img.color >> 8);
		buffer[current_pixel + 2] = (utils->img.color >> 16);
		buffer[current_pixel + 3] = utils->img.color >> 24;
}

void	*construct_image(t_utils *u)
{
	char	*buffer;
	int		current_pixel;
	int		x;
	int		y;

	u->img.image = mlx_new_image
		(u->vars.mlx, u->img.image_x_size, u->img.image_y_size);
	buffer = mlx_get_data_addr(u->img.image,
			&u->img.pixel_bits, &u->img.line_bytes, &u->img.endian);
	x = u->img.x_start - 1;
	if (u->img.pixel_bits != 32)
		u->img.color = mlx_get_color_value(u->vars.mlx, u->img.color);
	while (++x < u->img.x_end)
	{
		y = u->img.y_start - 1;
		while (++y < u->img.y_end)
		{
			color_manage(u, x, y);
			current_pixel = (y * u->img.line_bytes + x * u->img.pixel_bits / 8);
			fill_buffer(u, u->img.endian, current_pixel, buffer);
		}
	}
	mlx_put_image_to_window(u->vars.mlx, u->vars.win, u->img.image, 0, 0);
	return (u->img.image);
}
