/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:48:21 by etuffleb          #+#    #+#             */
/*   Updated: 2019/03/03 17:53:53 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 100

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_gradient
{
	int			first_col;
	int			second_col;
}				t_gradient;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
}				t_mlx;

typedef struct	s_coords
{
	double		x;
	double		y;
}				t_coords;

int		get_next_line(const int fd, char **line);

int		**ft_read_fdf(int fd);
int		ft_error(char *str);


//draw
int		ft_opasity(int argb, double y, int tru);
void	ft_swap_points(t_point *first, t_point *second, t_gradient *color);
void	mlx_line_put(t_coords *coord, t_mlx mlx, int color, int tg);
void	put_nice_line(t_point one, t_point two, t_mlx mlx, t_gradient color);
int		ft_gradient(double from, double to, t_gradient color, double current);

void put_ugly_line(t_point one, t_point two, t_mlx mlx, t_gradient color);


#endif
