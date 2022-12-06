/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:42:56 by vgiordan          #+#    #+#             */
/*   Updated: 2022/12/06 11:48:35 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH	150
# define HEIGHT 150

# define planX 2
# define planY 2

# define maxIter 20

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


int manderbrot(int x, int y);
int julia(int x, int y, t_z c);

#endif