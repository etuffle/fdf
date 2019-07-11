/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:48:21 by etuffleb          #+#    #+#             */
/*   Updated: 2019/07/11 16:12:05 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 100


// for line
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

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

// for map
typedef struct	s_map
{
	int			h;
	int			color;
}				t_map;

typedef struct	s_test
{
	int			x;
	int			y;
	t_mlx		tmlx;
	int			flag;
}				t_test;

int		ft_error(char *str);
int		get_next_line(const int fd, char **line);
int		ft_is_valid_fdf(int fd, int *hight);
t_map	**ft_read_fdf(int fd, int hight, int width);
t_map	*push_nb_col(char **arr, int width);

//line
int		ft_opasity(int argb, double y, int tru);
void	ft_swap_points(t_point *first, t_point *second, t_gradient *color);
void	mlx_line(t_point *coord, t_mlx mlx, int color, int tg);
void	put_nice_line(t_point one, t_point two, t_mlx mlx, t_gradient color);
int		f_gr(double from, double to, t_gradient color, double current);


int		ft_power(int nb, int power);
int		ft_atoi_base(char *nb, int base);

void	create_win(int wid_x, int high_y);
t_map	**ft_get_map(int ac, char *av);
int key_hook(int key, t_test *param);

#endif
