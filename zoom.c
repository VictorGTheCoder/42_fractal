/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:20:37 by vgiordan          #+#    #+#             */
/*   Updated: 2022/12/12 18:26:59 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern double zoom_ratio;
extern double centreX;
extern double centreY;
t_z pixel_in_complex(int x, int y)
{
    t_z c;
    c.a = (-planComplexX + 2 * planComplexX * (double)x / WIDTH) / zoom_ratio + centreX;
    c.b = (-planComplexY + 2 * planComplexY * (double)y / HEIGHT) / zoom_ratio + centreY;
    return (c);
}

int zoom(char c, t_vars *vars)
{
    //centreX = mi->mp.x;
    //centreY = mi->mp.y;
    //t_mp mp = get_mouse_position(vars);
    if (c == 'f')
    {
        zoom_ratio *= 1.2;
        //centreX = -0.06783611264225832;
        //centreY = 0.6617460391250546;
        //centreX = mp.x;
    }
    if (c == 'b')
    {
        if (zoom_ratio == 1)
            return (0);
        else
        {
            zoom_ratio /= 1.2;
            //centreX = -0.06783611264225832;
           // centreY = 0.6617460391250546;
        }
            
    }
    return (0);
}

int	mouse_hook(int key, t_vars *vars)
{
	t_zi zi;

    zi.zoom_ratio = 1;
    zi.zoomX = 0;
    zi.zoomY = 0;
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
