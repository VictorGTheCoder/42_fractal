/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:42:56 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/23 17:56:24 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
#include <pthread.h>
# include "../42_fractalb/mlx/mlx.h"
# include "../libft/libft.h"

# define WIDTH	700
# define HEIGHT 700

# define planComplexX 2
# define planComplexY 2

# define maxIter 5

# define KEY_LEFT   123
# define KEY_RIGHT  124
# define KEY_DOWN   125
# define KEY_UP     126
# define KEY_SPACE  49
# define KEY_ESCAPE 53
# define KEY_UPP 3
# define KEY_DOWNP 2

# define WHITE 0xFFFFFF
# define DARK 0x000000

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

typedef struct color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct swiss_utils
{
}	t_swiss;

typedef struct imageconstruct
{
	int		x_start;
	int		y_start;
	int		x_end;
	int		y_end;
	int		image_x_size;
	int		image_y_size;
	int		color;
	int		fps;
	int		current_pixel;
	int		endian;
	int		line_bytes;
	void	*image;
	int		pixel_bits;
}	t_image;

typedef struct carre
{
	double	x_start;
	double y_start;
	double x_end;
	double y_end;
} t_carre;
typedef struct all_utils
{
	t_vars	vars;
	t_zpi	zpi;
	t_z		c;
	t_mp	mp;
	t_image img;
	t_carre	carre;
	t_color	color;
	int		fract;
	int		max_iter;
} t_utils;

/*--------------------events-------------------*/

int		key_pressed(int key, t_utils *utils);
void	on_destroy(t_utils *utils);
int	mouse_event(int key, int x, int y, t_utils *utils);

/*--------------------utils.c------------------*/

void	get_mouse_position(t_utils *utils);
int	create_trgb(int t, int r, int g, int b);

/*--------------------fract.c------------------*/

int mandelbrot(int x, int y, t_utils *utils);
int julia(int x, int y, t_utils *utils);
int croix_suisse(t_utils *utils, int x, int y, int i);
int	burning_ship(int x, int y, t_utils *utils);

/*--------------------others.c------------------*/

void utils_init(t_utils *utils);
int	create_trgb(int t, int r, int g, int b);
void	*construct_image(t_utils *utils);
void	zoom(char c, t_utils *utils);
t_z pixel_in_complex(int x, int y, t_zpi zpi);
int get_chunk(int x, int y, t_utils *utils, int i);
void random_color(t_utils *utils);

void    chunk1(t_utils *utils);
void    chunk2(t_utils *utils);
void    chunk3(t_utils *utils);
void    chunk4(t_utils *utils);
void	chunk_corner_manager(t_utils	*utils, int cs);

void	chunk1_side(t_utils *utils);
void	chunk2_side(t_utils *utils);
void	chunk3_side(t_utils *utils);
void	chunk4_side(t_utils *utils);

#endif