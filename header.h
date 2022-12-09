/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:42:56 by vgiordan          #+#    #+#             */
/*   Updated: 2022/12/09 15:55:17 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
#include "../42_fractal/minilibx_opengl/mlx.h"

# define WIDTH	700
# define HEIGHT 700

# define planComplexX 2
# define planComplexY 2


# define maxIter 100

# define KEY_LEFT   123
# define KEY_RIGHT  124
# define KEY_DOWN   125
# define KEY_UP     126
# define KEY_SPACE  49
# define KEY_ESCAPE 53

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct z_complex
{
	float	a;
	float	b;
}	t_z;

typedef struct mouse_pos
{
	int	x;
	int	y;
}	t_mp;

typedef struct mouse_info
{
	t_vars vars;
	t_mp mp;
}	t_mi;

typedef struct imageconstruct
{
	int	x_start;
	int	y_start;
	int	x_end;
	int	y_end;
	t_vars *vars;
	t_z	c;
}	t_image;

int manderbrot(int x, int y);
int julia(int x, int y, t_z c);
int	create_trgb(int t, int r, int g, int b);

int	mouse_hook(int key, t_mi *mi);
t_mp get_mouse_position(t_vars *vars);
void	*construct_image(void *img);

t_z pixel_in_complex(int x, int y, int zoom_ratio);

#endif