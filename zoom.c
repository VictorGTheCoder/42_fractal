/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:20:37 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/23 14:22:39 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_z	pixel_in_complex(int x, int y, t_zpi zpi)
{
	t_z	c;

	c.a = (-planComplexX + 2 * planComplexX * (double)x / WIDTH);
	c.a = c.a / zpi.zoom_ratio + zpi.centreX;
	c.b = (-planComplexY + 2 * planComplexY * (double)y / HEIGHT);
	c.b = c.b / zpi.zoom_ratio + zpi.centreY;
	return (c);
}

void	zoom(char c, t_utils *utils)
{
	if (c == 'f')
	{
		(utils->zpi.zoom_ratio) *= 1.1;
	}
	if (c == 'b')
	{
		if ((utils->zpi.zoom_ratio) > 1)
		{
			(utils->zpi.zoom_ratio) /= 1.1;
		}
	}
}

int	mouse_event(int key, int x, int y, t_utils *utils)
{
	if (key == 2)
	{
		return (2);
	}
	if (key == 4)
	{
		zoom('b', utils);
		return (2);
	}
	if (key == 5)
	{
		zoom('f', utils);
		return (5);
	}
	return (1);
}
