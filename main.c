/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:54:18 by etuffleb          #+#    #+#             */
/*   Updated: 2019/02/26 15:35:35 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fdf.h"

int **ft_read_fdf(int fd)
{
	char *str;
	int **arr;
	int n;
	int i;
	int j;

	n = -1;
	arr = (int **)malloc(sizeof(int *) * 12);
	while (get_next_line(fd, &str) == 1)
	{
		i = 0;
		j = -1;
		arr[++n] = (int *)malloc(sizeof(int) * 12);
		while(str[i] != '\0')
		{
			arr[n][++j] = ft_atoi(&(str[i]));
			while(str[i] != ' ' && str[i] != '\0')
				i++;
			i++;
		}
		free(str);
	}
	return (arr);
}

int ft_error(char *str)
{
	ft_putendl(str);
	exit (1);
}

int main(int argc, char **argv)
{
	int		**map;
	int		fd;
	t_mlx	mlox;

	if (argc != 2)
		ft_error("usage: ./fdf file");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("file doesn't exist");
	map = ft_read_fdf(fd);
	if (!map)
		ft_error("error");

	mlox.ptr = mlx_init();
	mlox.win = mlx_new_window(mlox.ptr, 1000, 1000, "fils de fer | 42");

	t_point one;
	t_point two;
	t_gradient color;


	one.x = 500.0;
	one.y = 500.0;
	two.y = 100.0;
	two.x = 100.0;

	color.first_col = 0x0000FF00;
	color.second_col = 0x00FFFFFF;

	while(two.x < 1000.0)
	{
		put_nice_line(one, two, mlox, color);
		two.x += 50.0;
	}

	two.x = 950.0;
	color.first_col = 0x000000FF;

	while(two.y < 1000.0)
	{
		put_nice_line(one, two, mlox, color);
		two.y += 50.0;
	}
	two.y = 950.0;

	color.first_col = 0x00FF0000;

	while(two.x > 0.0)
	{
		put_nice_line(one, two, mlox, color);
		two.x -= 50.0;
	}
	two.x = 50.0;

	color.first_col = 0x00FFFF00;

	while(two.y > 50.0)
	{
		put_nice_line(one, two, mlox, color);
		two.y -= 50.0;
	}

/*
	two.x = 500.0;
	two.y = 200.0;
	put_nice_line(one, two, mlx_ptr, win_ptr, 0x00FFFFFF);//

	two.y = 800.0;
	put_nice_line(one, two, mlx_ptr, win_ptr, 0x00FFFFFF);//


	two.x = 800.0;
	two.y = 200.0;
	put_nice_line(one, two, mlx_ptr, win_ptr, 0x00FFFFFF);

	two.y = 500.0;
	put_nice_line(one, two, mlx_ptr, win_ptr, 0x00FFFFFF);

	two.y = 800.0;
	put_nice_line(one, two, mlx_ptr, win_ptr, 0x00FFFFFF);


	two.x = 200.0;
	two.y = 800.0;
	put_nice_line(one, two, mlx_ptr, win_ptr, 0x00FFFFFF);

	two.y = 500.0;
	put_nice_line(one, two, mlx_ptr, win_ptr, 0x00FFFFFF);

	two.y = 200.0;
	put_nice_line(one, two, mlx_ptr, win_ptr, 0x00FFFFFF);
*/

	mlx_loop(mlox.ptr);

	return (0);
}
