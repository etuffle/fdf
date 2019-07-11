/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:14:47 by etuffleb          #+#    #+#             */
/*   Updated: 2019/07/11 16:51:54 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fdf.h"

int		len_of_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

int		ft_is_valid_fdf(int fd, int *hight)
{
	int		n;
	int		m;
	char	*str;
	char	**arr;

	n = -1;
	*hight = 0;
	while (get_next_line(fd, &str) == 1)
	{
		if (!(arr = ft_strsplit(str, ' ')))
			return (0);
		m = len_of_arr(arr);
		if (n == -1)
			n = len_of_arr(arr);
		if (m != n)
			return (0);
		free(str);
		free(arr);
		hight++;
	}
	return (m);
}

t_map	*push_nb_col(char **arr, int width)
{
	t_map	*elem;
	t_map	*tmp;
	int		i;
	int		j;

	i = 0;
	if (!(tmp = (t_map *)malloc(sizeof(t_map) * width + 1)))
		return (NULL);
	elem = tmp;
	while (arr[i] != NULL)
	{
		j = 0;
		tmp->h = ft_atoi(arr[i]);
		while (arr[i][j] != '\0' && arr[i][j] != 'x')
			j++;
		if (arr[i][j] == 'x')
			tmp->color = ft_atoi_base(&(arr[i][j + 1]), 16);
		else
			tmp->color = 0x00FFFFFF;
		i++;
		tmp++;
	}
	return (elem);
}

t_map	**ft_read_fdf(int fd, int hight, int width)
{
	char	**arr_space;
	char	*str;
	t_map	**nb_and_col;
	int		i;

	i = 0;
	if (!(nb_and_col = (t_map **)malloc(sizeof(t_map) * hight + 1)))
		return (NULL);
	while (get_next_line(fd, &str) == 1)
	{
		arr_space = ft_strsplit(str, ' ');
		if (!(nb_and_col[i] = push_nb_col(arr_space, width)))
			return (NULL);
		free(str);
		free(arr_space);
		i++;
	}
	nb_and_col[i] = NULL;
	return (nb_and_col);
}



static void draw_something(t_mlx mlox, int wid_x, int high_y, int flag)
{
	t_point one;
	t_point two;
	t_gradient color;

	one.x = wid_x / 2;
	one.y = high_y / 2;
	two.y = 50.0;
	two.x = 50.0;
	color.first_col = 0x0000FF00;
	color.second_col = 0x00FFFFFF;

	if (flag == 0)
		while(two.x < wid_x)
		{
			put_nice_line(one, two, mlox, color);
			two.x += 50.0;
		}
	if (flag == 1)
	{
		color.first_col = 0x000000FF;
		while(two.y < 1200.0)
		{
			put_nice_line(one, two, mlox, color);
			two.y += 50.0;
		}
	}
	if (flag == 2)
	{
		two.x = 1750;
		two.y = 1150;
		color.first_col = 0x00FF0000;
		while(two.x > 0.0)
		{
			put_nice_line(one, two, mlox, color);
			two.x -= 50.0;
		}
	}
	if (flag == 3)
	{
		two.y = 1150;
		two.x = 1750;
		color.first_col = 0x00FFFF00;
		while(two.y > 50.0)
		{
			put_nice_line(one, two, mlox, color);
			two.y -= 50.0;
		}
	}
}


int key_hook(int key, t_test *param)
{

	if (key == 53 || param->flag == 4)
		exit (EXIT_SUCCESS);

	else if (key == 123 && param->flag == 0)
	{
		draw_something(param->tmlx, param->x, param->y, param->flag);
		param->flag++;
	}
	else if (key == 123 && param->flag == 1)
	{
		draw_something(param->tmlx, param->x, param->y, param->flag);
		param->flag++;
	}
	else if (key == 123 && param->flag == 2)
	{
		draw_something(param->tmlx, param->x, param->y, param->flag);
		param->flag++;
	}
	else if (key == 123 && param->flag == 3)
	{
		draw_something(param->tmlx, param->x, param->y, param->flag);
		param->flag++;
	}

	return (0);
}

t_map	**ft_get_map(int ac, char *av)
{
	t_map	**map;
	int		hight;
	int		width;
	int		fd;

	if (ac != 2)
		ft_error("usage: ./fdf file");
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error("file doesn't exist");
	if (!(width = ft_is_valid_fdf(fd, &hight)))
		ft_error("map is not valid");
	if (close(fd))
		ft_error("error in closing file");
	fd = open(av, O_RDONLY);
	map = ft_read_fdf(fd, hight, width);
	if (!map)
		ft_error("error in creating");
	return(map);
}



/*
	printf("%d, %x;  %d, %x;  %d, %x;  %d, %x;  %d, %x;  %d, %x;\n", (map[0][0]).h, (map[0][0]).color, (map[0][1]).h, (map[0][1]).color,
	(map[0][2]).h, (map[0][2]).color, (map[0][3]).h, (map[0][3]).color, (map[0][4]).h, (map[0][4]).color, (map[0][5]).h, (map[0][5]).color);
	printf("%d, %x;  %d, %x;  %d, %x;  %d, %x;  %d, %x;  %d, %x;\n", (map[1][0]).h, (map[1][0]).color, (map[1][1]).h, (map[1][1]).color,
	(map[1][2]).h, (map[1][2]).color, (map[1][3]).h, (map[1][3]).color, (map[1][4]).h, (map[1][4]).color, (map[1][5]).h, (map[1][5]).color);
	printf("%d, %x;  %d, %x;  %d, %x;  %d, %x; \n", (map[2][0]).h, (map[2][0]).color, (map[2][1]).h, (map[2][1]).color, (map[2][2]).h, (map[2][2]).color, (map[2][3]).h, (map[2][3]).color);
	printf("%d, %x;  %d, %x;  %d, %x;  %d, %x; \n", (map[3][0]).h, (map[3][0]).color, (map[3][1]).h, (map[3][1]).color, (map[3][2]).h, (map[3][2]).color, (map[3][3]).h, (map[3][3]).color);
*/
