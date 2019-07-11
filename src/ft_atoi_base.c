/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:18:44 by etuffleb          #+#    #+#             */
/*   Updated: 2019/07/11 16:57:48 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int			ft_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	else
		return (nb * (ft_power(nb, power - 1)));
}

static int	check_nb(char c, int base)
{
	int		result;

	if (c >= '0' && c <= '9')
		result = c - 48;
	else if (c >= 'a' && c <= 'z')
		result = c - 97 + 10;
	else if (c >= 'A' && c <= 'Z')
		result = c - 65 + 10;
	else
		result = -1;
	if (result < base && result != -1)
		return (result);
	else
		ft_error("color(s) are invalid");
	return (-1);
}

static int	len_nb(char *str, int base)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (check_nb(str[i], base) == -1)
			break ;
		i++;
	}
	return (i);
}

int			ft_atoi_base(char *str, int base)
{
	int res;
	int len;

	if (base == 10)
		return (ft_atoi(str));
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	len = len_nb(str, base) - 1;
	res = 0;
	while (*str && len >= 0 && check_nb(*str, base) != -1)
	{
		res += check_nb(*str, base) * ft_power(base, len);
		str++;
		len--;
	}
	return (res);
}
