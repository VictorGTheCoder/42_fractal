/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:20:37 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/23 19:04:41 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_z	pixel_in_complex(int x, int y, t_utils *utils)
{
	t_z	c;

	c.a = (-PLANCOMPLEXX + 2 * PLANCOMPLEXX * (double)x / WIDTH);
	c.a = c.a / utils->zpi.zoom_ratio + utils->zpi.centrex;
	c.b = (-PLANCOMPLEXY + 2 * PLANCOMPLEXY * (double)y / HEIGHT);
	c.b = c.b / utils->zpi.zoom_ratio + utils->zpi.centrey;
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
