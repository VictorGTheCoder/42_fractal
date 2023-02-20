/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:00:29 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/20 17:01:28 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	utils_init(t_utils *utils)
{
	utils->zpi.centreX = 0;
	utils->zpi.centreY = 0;
	utils->zpi.zoom_ratio = 1;
	utils->vars.mlx = mlx_init();
	utils->vars.win = mlx_new_window(utils->vars.mlx, WIDTH, HEIGHT, "FRACTAL");
}
