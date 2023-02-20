/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:57:31 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/20 16:57:39 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_mp	get_mouse_position(t_vars *vars)
{
	int		x;
	int		y;
	t_mp	mp;

	mlx_mouse_get_pos(vars->win, &x, &y);
	mp.x = x;
	mp.y = y;
	return (mp);
}
