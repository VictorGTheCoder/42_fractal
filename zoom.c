/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:20:37 by vgiordan          #+#    #+#             */
/*   Updated: 2022/12/12 17:06:48 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern int zoom_ratio;
extern int centreX;
extern int centreY;
t_z pixel_in_complex(int x, int y, int zoom_ratio)
{
    t_z c;
    c.a = (-planComplexX + 2 * planComplexX * (float)x / WIDTH) / zoom_ratio + centreX;
    c.b = (-planComplexY + 2 * planComplexY * (float)y / HEIGHT) / zoom_ratio + centreY;
    return (c);
}

int zoom(char c, t_vars *vars)
{
    //centreX = mi->mp.x;
    //centreY = mi->mp.y;
    //t_mp mp = get_mouse_position(vars);
    if (c == 'f')
    {
        zoom_ratio++;
        //centreX = mp.x;
    }

    if (c == 'b')
    {
        if (zoom_ratio == 1)
            return (0);
        else
        {
            zoom_ratio--;
            //centreY = mp.y;
        }
            
    }
    return (0);
}

int	mouse_hook(int key, t_vars *vars)
{

	
	printf("mouse_hook\n");
	if (key == 2)
	{
		printf("key2\n");
		return (2);
	}
    if (key == 4)
	{
        zoom('b', vars);
		printf("ZOOMB\n");
		return (2);
	}
    if (key == 5)
	{
        zoom('f', vars);
		printf("ZOOMF\n");
		return (5);
	}
	return (1);
}
