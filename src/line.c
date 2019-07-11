/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:27:09 by etuffleb          #+#    #+#             */
/*   Updated: 2019/06/29 18:08:08 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_opasity(int argb, double y, int tru)
{
	int		opacity;

	if (tru)
		opacity = (y - (int)y) * 255;
	else
		opacity = (1 - (y - (int)y)) * 255;
	return (argb | (opacity << 24));
}

void	ft_swap_points(t_point *first, t_point *second, t_gradient *color)
{
	double	tmp;

	tmp = first->x;
	first->x = second->x;
	second->x = tmp;
	tmp = first->y;
	first->y = second->y;
	second->y = tmp;
	tmp = color->first_col;
	color->first_col = color->second_col;
	color->second_col = tmp;
}

void	mlx_line(t_point *coord, t_mlx mlx, int color, int tg)
{
	if (tg)
	{
		mlx_pixel_put(mlx.ptr, mlx.win, (int)coord->x, (int)coord->y,
		ft_opasity(color, coord->x, 1));
		mlx_pixel_put(mlx.ptr, mlx.win, (int)coord->x + 1, (int)coord->y,
		ft_opasity(color, coord->x, 0));
		if (tg == -1)
			(coord->y)++;
		else
			(coord->y)--;
	}
	else
	{
		mlx_pixel_put(mlx.ptr, mlx.win, (int)coord->x, (int)coord->y,
		ft_opasity(color, coord->y, 1));
		mlx_pixel_put(mlx.ptr, mlx.win, (int)coord->x, (int)coord->y + 1,
		ft_opasity(color, coord->y, 0));
		(coord->x)++;
	}
}

int		f_gr(double from, double to, t_gradient color, double current)
{
	int		new_color;
	int		a;
	int		b;
	int		i;

	i = 0;
	new_color = 0x00000000;
	a = fabs(current - from);
	b = fabs(to - current);
	while (i <= 24)
	{
		new_color |= (((color.first_col >> i) & 0xFF * b / (a + b)) +
		((color.second_col >> i & 0xFF) * a / (a + b))) << i;
		i += 8;
	}
	return (new_color);
}

void	put_nice_line(t_point one, t_point two, t_mlx mlx, t_gradient color)
{
	t_point	coord;

	if (one.x > two.x)
		ft_swap_points(&one, &two, &color);
	coord.y = one.y;
	coord.x = one.x;
	if (fabs(two.x - one.x) < fabs(two.y - one.y))
		if (two.y < one.y)
			while (coord.y >= two.y)
			{
				mlx_line(&(coord), mlx, f_gr(one.y, two.y, color, coord.y), 1);
				coord.x += fabs(two.x - one.x) / fabs(two.y - one.y);
			}
		else
			while (coord.y <= two.y)
			{
				mlx_line(&(coord), mlx, f_gr(one.y, two.y, color, coord.y), -1);
				coord.x += fabs(two.x - one.x) / fabs(two.y - one.y);
			}
	else
		while (coord.x <= two.x)
		{
			mlx_line(&(coord), mlx, f_gr(one.x, two.x, color, coord.x), 0);
			coord.y += (two.y - one.y) / (two.x - one.x);
		}
}
