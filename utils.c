/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:57:31 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/22 12:42:37 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	get_mouse_position(t_utils *utils)
{
	int		x;
	int		y;

	mlx_mouse_get_pos(utils->vars.win, &x, &y);
	utils->mp.x = x;
	utils->mp.y = y;
}
