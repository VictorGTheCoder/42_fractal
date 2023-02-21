/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:42:56 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/21 18:05:07 by vgiordan         ###   ########.fr       */
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

# define WIDTH	700
# define HEIGHT 700

# define planComplexX 2
# define planComplexY 2


# define maxIter 500

# define KEY_LEFT   123
# define KEY_RIGHT  124
# define KEY_DOWN   125
# define KEY_UP     126
# define KEY_SPACE  49
# define KEY_ESCAPE 53

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

typedef struct all_utils
{
	t_vars	vars;
	t_zpi	zpi;
	t_z		c;
	t_mp	mp;
	t_image img;
	int		fract;
} t_utils;

/*--------------------events-------------------*/

int		key_pressed(int key, t_utils *utils);
void	onDestroy(t_utils *utils);


/*--------------------utils.c------------------*/

void	get_mouse_position(t_utils *utils);
int	create_trgb(int t, int r, int g, int b);
char	*ft_itoa(int n);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

void utils_init(t_utils *utils);
int mandelbrot(int x, int y, t_utils *utils);
int julia(int x, int y, t_utils *utils);
int	create_trgb(int t, int r, int g, int b);

int	mouse_event(int key, int x, int y, t_utils *utils);
void	*construct_image(t_utils *utils);

t_z pixel_in_complex(int x, int y, t_zpi zpi);


#endif