/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:20:37 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/23 17:37:45 by vgiordan         ###   ########.fr       */
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
