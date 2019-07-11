/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:54:18 by etuffleb          #+#    #+#             */
/*   Updated: 2019/07/11 16:12:20 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fdf.h"

int ft_error(char *str)
{
	ft_putendl(str);
	exit (1);
}


void	create_win(int wid_x, int high_y)
{
	t_mlx	mlox;

	mlox.ptr = mlx_init();
	mlox.win = mlx_new_window(mlox.ptr, wid_x, high_y, "fils de fer | 42");

	//draw_something(mlox, wid_x, high_y);

	t_test	test;

	test.x = wid_x;
	test.y = high_y;
	test.tmlx = mlox;
	test.flag = 0;
	mlx_hook (mlox.win, 2, 0, key_hook, (void *)0);
	mlx_hook (mlox.win, 2, 0, key_hook, &test);

	mlx_loop (mlox.ptr);
	return ;
}

int main(int argc, char **argv)
{
	t_map	**map;

	map = ft_get_map(argc, argv[1]);
	create_win(1800, 1200);


	return (0);
}
