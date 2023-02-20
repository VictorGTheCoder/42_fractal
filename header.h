/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:42:56 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/20 16:54:42 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
#include "../42_fractalb/mlx/mlx.h"

# define WIDTH	500
# define HEIGHT 500

# define planComplexX 2
# define planComplexY 2


# define maxIter 500

# define KEY_LEFT   123
# define KEY_RIGHT  124
# define KEY_DOWN   125
# define KEY_UP     126
# define KEY_SPACE  49
# define KEY_ESCAPE 53

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct	t_zoom_pos_info
{
	double	zoom_ratio;
	double	centreX;
	double	centreY;
}	t_zpi;

typedef struct z_complex
{
	double	a;
	double	b;
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

typedef struct all_utils
{
	t_vars	vars;
	t_zpi	zpi;
	t_mi	mi;
	t_z		c;
	t_mp	mp;
	t_image img;
} t_utils;

/*--------------------events-------------------*/

int	key_pressed(int key, t_utils *utils);


/*--------------------utils.c------------------*/

t_mp get_mouse_position(t_vars *vars);
int	create_trgb(int t, int r, int g, int b);

void utils_init(t_utils *utils);
int manderbrot(int x, int y, t_utils *utils);
int julia(int x, int y, t_utils *utils);
int	create_trgb(int t, int r, int g, int b);

int	mouse_event(int key, int x, int y, t_utils *utils);
void	*construct_image(t_utils *utils);

t_z pixel_in_complex(int x, int y, t_zpi zpi);

#endif