/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:57:31 by vgiordan          #+#    #+#             */
/*   Updated: 2023/02/21 18:04:46 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*src)
		str[i++] = *src++;
	str[i] = '\0';
	return (str);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	get_mouse_position(t_utils *utils)
{
	int		x;
	int		y;

	mlx_mouse_get_pos(utils->vars.win, &x, &y);
	utils->mp.x = x;
	utils->mp.y = y;
}

static int	sizeofn(int n)
{
	int	n_size;

	n_size = 0;
	if (n < 0)
	{
		n = -n;
		n_size++;
	}
	while (n > 9)
	{
		n /= 10;
		n_size++;
	}
	n_size++;
	return (n_size);
}

char	*ft_itoa(int n)
{
	int		n_size;
	char	*result;
	int		i;

	i = 0;
	n_size = sizeofn(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = malloc((n_size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		result[0] = '-';
	}
	while (n > 9)
	{
		result[n_size - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	result[n_size - i - 1] = n % 10 + '0';
	result[n_size] = '\0';
	return (result);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}