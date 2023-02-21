/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:13:23 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/21 17:50:21 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_z	fonction(t_z z, t_z c)
{
	double	t;

	t = z.a;
	z.a = z.a * z.a - z.b * z.b + c.a;
	z.b = 2 * t * z.b + c.b;
	return (z);
}

int	julia(int x, int y, t_utils *utils)
{
	t_z		z;
	int		i;
	double	d;
	t_z		c;

	z = pixel_in_complex(x, y, (utils->zpi));
	c = pixel_in_complex(utils->mp.x, utils->mp.y, utils->zpi);
	i = 0;
	while (i < maxIter)
	{
		z = fonction(z, c);
		i++;
		d = z.a * z.a + z.b * z.b;
		if (d > 4)
			return (i);
	}
	return (-1);
}

int	mandelbrot(int x, int y, t_utils *utils)
{
	t_z		c;
	t_z		z;
	int		i;
	double	d;
	double	p;

	z.a = 0;
	z.b = 0;
	c = pixel_in_complex(x, y, (utils->zpi));
	p = sqrt((c.a - 0.25) * (c.a - 0.25) + c.b * c.b);
	if (c.a < (p - 2.0 * p * p + 0.25))
		return (-2);
	if (((c.a + 1) * (c.a + 1) + c.b * c.b) < 0.0625)
		return (-2);
	i = 0;
	while (i < (maxIter))
	{
		z = fonction(z, c);
		i++;
		d = z.a * z.a + z.b * z.b;
		if (d > 4)
			return (i);
	}
	return (-1);
}
