/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swiss_fract_corner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:33:19 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/23 17:55:48 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	chunk1(t_utils *utils)
{
	int	temp;

	temp = utils->carre.x_start;
	utils->carre.x_end = (utils->carre.x_end - temp)
		* 2 / 5 + utils->carre.x_start;
	temp = utils->carre.y_start;
	utils->carre.y_end = (utils->carre.y_end - temp)
		* 2 / 5 + utils->carre.y_start;
}

void	chunk2(t_utils *utils)
{
	int	temp;

	temp = utils->carre.x_start;
	utils->carre.x_start = (utils->carre.x_end - utils->carre.x_start)
		* 3 / 5 + utils->carre.x_start;
	temp = utils->carre.y_start;
	utils->carre.y_end = (utils->carre.y_end - temp)
		* 2 / 5 + utils->carre.y_start;
}

void	chunk3(t_utils *utils)
{
	int	temp;

	temp = utils->carre.x_start;
	utils->carre.x_start = (utils->carre.x_end - utils->carre.x_start)
		* 3 / 5 + utils->carre.x_start;
	temp = utils->carre.y_start;
	utils->carre.y_start = (utils->carre.y_end - utils->carre.y_start)
		* 3 / 5 + utils->carre.y_start;
}

void	chunk4(t_utils *utils)
{
	int	temp;

	temp = utils->carre.x_start;
	utils->carre.x_end = (utils->carre.x_end - temp)
		* 2 / 5 + utils->carre.x_start;
	temp = utils->carre.y_start;
	utils->carre.y_start = (utils->carre.y_end - utils->carre.y_start)
		* 3 / 5 + utils->carre.y_start;
}

void	chunk_corner_manager(t_utils	*utils, int cs)
{
	if (cs == 1)
		chunk1(utils);
	else if (cs == 2)
		chunk2(utils);
	else if (cs == 3)
		chunk3(utils);
	else
		chunk4(utils);
}
