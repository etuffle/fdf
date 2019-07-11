/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:07:44 by etuffleb          #+#    #+#             */
/*   Updated: 2019/07/11 15:34:08 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fdf.h"

t_vector get_vector(t_map **map, int x, int y)
{
	t_vector res;

	res.x = x;
	res.y = y;
	res.z = map[x][y].h;
	return (res);
}

