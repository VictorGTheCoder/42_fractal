/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swiss_fract_side.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:42:45 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/23 17:53:07 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	chunk1_side(t_utils *utils)
{
	int	temp;

	temp = utils->carre.x_start;
	utils->carre.x_start = (utils->carre.x_end - temp) * 2 / 5 + temp;
	utils->carre.x_end = (utils->carre.x_end - temp) * 3 / 5 + temp;
	temp = utils->carre.y_start;
	utils->carre.y_end = (utils->carre.y_end - utils->carre.y_start)
		* 1 / 5 + temp;
}

void	chunk2_side(t_utils *utils)
{
	int	temp;

	temp = utils->carre.x_start;
	utils->carre.x_start = (utils->carre.x_end - temp) * 4 / 5 + temp;
	temp = utils->carre.y_start;
	utils->carre.y_start = (utils->carre.y_end - temp) * 2 / 5 + temp;
	utils->carre.y_end = (utils->carre.y_end - temp) * 3 / 5 + temp;
}

void	chunk3_side(t_utils *utils)
{
	int	temp;

	temp = utils->carre.x_start;
	utils->carre.x_start = (utils->carre.x_end - temp) * 2 / 5 + temp;
	utils->carre.x_end = (utils->carre.x_end - temp) * 3 / 5 + temp;
	temp = utils->carre.y_start;
	utils->carre.y_start = (utils->carre.y_end - utils->carre.y_start)
		* 4 / 5 + temp;
}

void	chunk4_side(t_utils *utils)
{
	int	temp;

	temp = utils->carre.x_start;
	utils->carre.x_end = (utils->carre.x_end - temp) * 1 / 5 + temp;
	temp = utils->carre.y_start;
	utils->carre.y_start = (utils->carre.y_end - temp) * 2 / 5 + temp;
	utils->carre.y_end = (utils->carre.y_end - temp) * 3 / 5 + temp;
}
