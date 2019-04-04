/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf(new).c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:27:09 by etuffleb          #+#    #+#             */
/*   Updated: 2019/02/26 15:11:56 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdio.h>

int		ft_opasity(int argb, double y, int tru)
{
	int		opacity;

	if (tru)
		opacity = (y - (int)y) * 255;
	else
		opacity = (1 - (y - (int)y)) * 255;
	return (argb | (opacity << 24));
}

void	ft_swap_points(t_point *first, t_point *second)
{
	double	tmp;

	tmp = first->x;
	first->x = second->x;
	second->x = tmp;
	tmp = first->y;
	first->y = second->y;
	second->y = tmp;
}

void	mlx_line_put(t_coords *coord, t_mlx mlx, int color, int tg)
{
	if (tg)
	{
		mlx_pixel_put(mlx.ptr, mlx.win, (int)coord->x, (int)coord->y,
		ft_opasity(color, coord->x, 1));
		mlx_pixel_put(mlx.ptr, mlx.win, (int)coord->x + 1, (int)coord->y,
		ft_opasity(color, coord->x, 0));
		if (tg == -1)
			(coord->y)--;
		else
			(coord->y)++;
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

void	put_nice_line(t_point one, t_point two, t_mlx mlx, int color)
{
	t_coords coord;

	if (one.x > two.x)
		ft_swap_points(&one, &two);
	coord.y = one.y;
	coord.x = one.x;
	if (fabs(two.x - one.x) < fabs(two.y - one.y))
		if (two.y < one.y)
			while (coord.y >= two.y)
			{
				put_nice_line(&(coord), mlx, color, 1);
				coord.x += fabs(two.x - one.x) / fabs(two.y - one.y);
//				color.first_col += (color.second_col - color.first_col);
			}
		else
			while (coord.y <= two.y)
			{
				put_nice_line(&(coord), mlx, color, -1);
				coord.x += fabs(two.x - one.x) / fabs(two.y - one.y);
			}
	else
		while (coord.x <= two.x)
		{
			put_nice_line(&(coord), mlx, color, 0);
			coord.y += (two.y - one.y) / (two.x - one.x);
		}
}
