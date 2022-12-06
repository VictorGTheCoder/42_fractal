/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:13:23 by vgiordan          #+#    #+#             */
/*   Updated: 2022/12/05 15:14:04 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_z fonction(t_z z, t_z c)
{
	float t;
	t = z.a;
	z.a = z.a*z.a - z.b * z.b + c.a;
	z.b = 2 * t * z.b + c.b;
	return (z);  
}

int julia(int x, int y, t_z c)
{
	t_z     z;
	int     i;
	float  d;

	z.a = -2 + 4 * (float)x /WIDTH;
	z.b = -2 + 4 * (float)y /HEIGHT;
	i = 0;
	while (i < maxIter)
	{
		z = fonction(z, c);
		i++;
		d = z.a * z.a + z.b * z.b;
		if (d > 4)
			return (i);   
	}
	return (-1);
}

int manderbrot(int x, int y)
{
	t_z c;
	t_z z;
	int i;
	float d;

	z.a = 0;
	z.b = 0;
	c.a = -2 + 4 * (float)x / WIDTH;
	c.b = -2 + 4 * (float)y / HEIGHT;
	//printf("x %d, y %d || c.a %f, c.b %f\n", x, y, c.a, c.b);
	i = 0;
	while (i < maxIter)
	{
		z = fonction(z, c);
		i++;
		d = z.a * z.a + z.b * z.b;
		if (d > 4)
			return (i);   
	}
	return (-1);
}