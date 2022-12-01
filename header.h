/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:42:56 by vgiordan          #+#    #+#             */
/*   Updated: 2022/12/01 11:41:57 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define WIDTH	1920
# define HEIGHT 1080

# define KEY_LEFT   123
# define KEY_RIGHT  124
# define KEY_DOWN   125
# define KEY_UP     126
# define KEY_SPACE  49
# define KEY_ESCAPE 53

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"

typedef struct z
{
	float	a;
	float	b;
}	t_z;

#endif