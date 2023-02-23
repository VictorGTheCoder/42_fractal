/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swiss_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:01:47 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/23 14:33:26 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_z get_centre(int i, int ci)
{
	t_z centre;

	if (ci % 4 == 1 || ci % 4 == 2)
	{
		centre.a = pow((2/5), i) * WIDTH;
	}
	if (ci % 4 == 0 || ci % 4 == 3)
	{
		centre.a = WIDTH - pow((2/5), i) * WIDTH;
	}
	if (ci % 4 == 1 || ci % 4 == 0)
	{
		centre.b = pow((2/5), i) * HEIGHT;
	}
	if (ci % 4 == 2 || ci % 4 == 3)
	{
		centre.a = HEIGHT - pow((2/5), i) * HEIGHT;
	}
	printf("carre %d, iteration %d, centre x: %d, y: %d \n", ci, i, centre.a, centre.b);
	return (centre);
}

//x_start = 300 end = 500
//y_start = 0 end = 200

int	point_is_in_a_corner_square(t_utils *utils, int x, int y, int i)
{
	if (x <= (utils->carre.x_end - utils->carre.x_start) * 2 / 5 + utils->carre.x_start)
	{
		if ( y <= (utils->carre.y_end - utils->carre.y_start) * 2 / 5 + utils->carre.y_start)
			return (1);
		if ( y >= ((utils->carre.y_end - utils->carre.y_start) * 3 / 5 + utils->carre.y_start))
			return (4);
	}
	if (x >= (utils->carre.x_end - utils->carre.x_start) * 3 / 5 + utils->carre.x_start)
	{
		if ( y <= (utils->carre.y_end - utils->carre.y_start) * 2 / 5 + utils->carre.y_start)
			return (2);
		if ( y >= ((utils->carre.y_end - utils->carre.y_start) * 3 / 5 + utils->carre.y_start))
			return (3);
	}
	return (-1);
}

int point_is_in_side(t_utils *utils, int x, int y, int i)
{
	if (x > ((utils->carre.x_end - utils->carre.x_start) * 2 / 5) + utils->carre.x_start && x < ((utils->carre.x_end - utils->carre.x_start) * 3 / 5) + utils->carre.x_start)
	{
		if ( y < ((utils->carre.y_end - utils->carre.y_start) * 1 / 5) + utils->carre.y_start) 
			return (1);
		if ( y > ((utils->carre.y_end - utils->carre.y_start) * 4 / 5)  + utils->carre.y_start)
			return (3);
	}
	if (y > (((utils->carre.y_end - utils->carre.y_start) * 2 / 5) + utils->carre.y_start)  && y < ((utils->carre.y_end - utils->carre.y_start) * 3 / 5) + utils->carre.y_start)
	{
		if ( x < ((utils->carre.x_end - utils->carre.x_start) * 1 / 5) + utils->carre.x_start)
			return (4);
		if ( x > ((utils->carre.x_end - utils->carre.x_start) * 4 / 5) + utils->carre.x_start)
			return (2);
	}
	return (-1);
}
int get_chunk(int x, int y, t_utils *utils, int i)
{
	int temp;
	int cs;
		
	if (i <= 0)
		return (-2);
	cs = point_is_in_a_corner_square(utils, x, y, i);
	if (cs != -1)
	{
		if (cs == 1)
		{
			temp = utils->carre.x_start;
			utils->carre.x_end = (utils->carre.x_end - temp) * 2 / 5 + utils->carre.x_start;
			temp = utils->carre.y_start;
			utils->carre.y_end = (utils->carre.y_end - temp) * 2 / 5 + utils->carre.y_start;
			return (get_chunk(x, y, utils, i - 1));
		}	
		if (cs == 2)
		{
			temp = utils->carre.x_start;
			utils->carre.x_start = (utils->carre.x_end - utils->carre.x_start) * 3 / 5 + utils->carre.x_start;
			temp = utils->carre.y_start;
			utils->carre.y_end = (utils->carre.y_end - temp) * 2 / 5 + utils->carre.y_start;
			return (get_chunk(x, y, utils, i - 1));
		}
		if (cs == 3)
		{
			temp = utils->carre.x_start;
			utils->carre.x_start = (utils->carre.x_end - utils->carre.x_start) * 3 / 5 + utils->carre.x_start;
			temp = utils->carre.y_start;
			utils->carre.y_start = (utils->carre.y_end - utils->carre.y_start) * 3 / 5 + utils->carre.y_start;
			return (get_chunk(x, y, utils, i - 1));
		}
		if (cs == 4)
		{
			temp = utils->carre.x_start;
			utils->carre.x_end = (utils->carre.x_end - temp) * 2 / 5 + utils->carre.x_start;
			temp = utils->carre.y_start;
			utils->carre.y_start = (utils->carre.y_end - utils->carre.y_start) * 3 / 5 + utils->carre.y_start;
			return (get_chunk(x, y, utils, i - 1));
		}
	}
	else
	{
		cs = point_is_in_side(utils, x, y, i);
		if (cs == 1)
		{
			temp = utils->carre.x_start;
			utils->carre.x_end = (utils->carre.x_end - temp) * 2 / 5 + utils->carre.x_start;
			temp = utils->carre.y_start;
			utils->carre.y_start = (utils->carre.y_end - utils->carre.y_start) * 3 / 5 + utils->carre.y_start;
			return (get_chunk(x, y, utils, i - 1));
		}
		if (cs == 2)
		{
			temp = utils->carre.x_start;
			utils->carre.x_end = (utils->carre.x_end - temp) * 2 / 5 + utils->carre.x_start;
			temp = utils->carre.y_start;
			utils->carre.y_start = (utils->carre.y_end - utils->carre.y_start) * 3 / 5 + utils->carre.y_start;
			return (get_chunk(x, y, utils, i - 1));
		}
		if (cs == 3)
		{
			temp = utils->carre.x_start;
			utils->carre.x_end = (utils->carre.x_end - temp) * 2 / 5 + utils->carre.x_start;
			temp = utils->carre.y_start;
			utils->carre.y_start = (utils->carre.y_end - utils->carre.y_start) * 3 / 5 + utils->carre.y_start;
			return (get_chunk(x, y, utils, i - 1));
		}
		if (cs == 4)
		{
			temp = utils->carre.x_start;
			utils->carre.x_end = (utils->carre.x_end - temp) * 2 / 5 + utils->carre.x_start;
			temp = utils->carre.y_start;
			utils->carre.y_start = (utils->carre.y_end - utils->carre.y_start) * 3 / 5 + utils->carre.y_start;
			return (get_chunk(x, y, utils, i - 1));
		}
		if (cs != -1)
		{

			return (-2);
		}
		return (-3);
	}
}

int croix_suisse(t_utils *utils, int x, int y, t_z centre, int ci, int i)
{
	int r;
	utils->carre.x_start = 0;
	utils->carre.y_start = 0;
	utils->carre.x_end = WIDTH;
	utils->carre.y_end = HEIGHT;
	r = get_chunk(x, y, utils, i);
	return (r);
}
