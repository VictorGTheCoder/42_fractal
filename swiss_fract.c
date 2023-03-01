/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swiss_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:01:47 by vgiordan          #+#    #+#             */
/*   Updated: 2023/03/01 13:54:03 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	point_is_in_a_corner_square(t_utils *utils, int x, int y, int i)
{
	if (x <= (utils->carre.x_end - utils->carre.x_start)
		* 2 / 5 + utils->carre.x_start)
	{
		if (y <= (utils->carre.y_end - utils->carre.y_start)
			* 2 / 5 + utils->carre.y_start)
			return (1);
		if (y >= (utils->carre.y_end - utils->carre.y_start)
			* 3 / 5 + utils->carre.y_start)
			return (4);
	}
	if (x >= (utils->carre.x_end - utils->carre.x_start)
		* 3 / 5 + utils->carre.x_start)
	{
		if (y <= (utils->carre.y_end - utils->carre.y_start)
			* 2 / 5 + utils->carre.y_start)
			return (2);
		if (y >= (utils->carre.y_end - utils->carre.y_start)
			* 3 / 5 + utils->carre.y_start)
			return (3);
	}
	return (-1);
}

static int	point_is_in_side(t_utils *utils, int x, int y, int i)
{
	if (x > ((utils->carre.x_end - utils->carre.x_start) * 2 / 5)
		+ utils->carre.x_start && x < ((utils->carre.x_end
				- utils->carre.x_start) * 3 / 5) + utils->carre.x_start)
	{
		if (y < ((utils->carre.y_end - utils->carre.y_start) * 1 / 5)
			+ utils->carre.y_start)
			return (1);
		if (y > ((utils->carre.y_end - utils->carre.y_start) * 4 / 5)
			+ utils->carre.y_start)
			return (3);
	}
	if (y > (((utils->carre.y_end - utils->carre.y_start) * 2 / 5)
			+ utils->carre.y_start) && y < ((utils->carre.y_end
				- utils->carre.y_start) * 3 / 5) + utils->carre.y_start)
	{
		if (x < ((utils->carre.x_end - utils->carre.x_start)
				* 1 / 5) + utils->carre.x_start)
			return (4);
		if (x > ((utils->carre.x_end - utils->carre.x_start)
				* 4 / 5) + utils->carre.x_start)
			return (2);
	}
	return (-1);
}

int	get_chunk(int x, int y, t_utils *utils, int i)
{
	int	cs;

	if (i <= 0)
		return (-2);
	cs = point_is_in_a_corner_square(utils, x, y, i);
	if (cs != -1)
	{
		chunk_corner_manager(utils, cs);
		return (get_chunk(x, y, utils, i - 1));
	}
	else
	{
		cs = point_is_in_side(utils, x, y, i);
		if (cs == 1)
			chunk1_side(utils);
		else if (cs == 2)
			chunk2_side(utils);
		else if (cs == 3)
			chunk3_side(utils);
		else if (cs == 4)
			chunk4_side(utils);
		else
			return (-3);
		return (get_chunk(x, y, utils, i - 1));
	}
}

int	croix_suisse(t_utils *utils, int x, int y, int i)
{
	utils->carre.x_start = 0;
	utils->carre.y_start = 0;
	utils->carre.x_end = WIDTH;
	utils->carre.y_end = HEIGHT;
	return (get_chunk(x, y, utils, i));
}
