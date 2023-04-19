/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:21:30 by asidqi            #+#    #+#             */
/*   Updated: 2023/04/19 17:18:27 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	size_t	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	while ((c[i] >= '0' && c[i] <= '9') || (c[i] == '+') || (c[i] == '-'))
		i++;
	if (c[i] == '\0')
		return (0);
	return (1);
}

int	ft_iszerostring(char *c)
{
	int	i;

	i = 0;
	if ((c[i] == '+') || (c[i] == '-'))
		i++;
	while (c[i] == '0')
		i++;
	if (c[i] == '\0')
		return (1);
	return (0);
}

short	valid_number(char **av)
{
	int	i;

	i = 1;
	(void)av;
	while (i < 5)
	{
		if ((ft_isdigit(av[i])) \
		|| (ft_atoi(av[i]) == 0 && !ft_iszerostring(av[i])) \
		|| ft_strcmp1(av[i], ft_itoa(ft_atoi(av[i]))) \
		|| !(ft_atoi(av[i]) >= -2147483648 && ft_atoi(av[i]) <= 2147483647))
		{
			printf("Error\nAlkhawa chni 3andek ntina al3ayl?");
			return (1);
		}
		i++;
	}
	return (0);
}

short	valid(char *av)
{
	if (av)
	{
		if ((ft_isdigit(av)) \
		|| (ft_atoi(av) == 0 && !ft_iszerostring(av)) \
		|| ft_strcmp1(av, ft_itoa(ft_atoi(av))) \
		|| !(ft_atoi(av) >= -2147483648 && ft_atoi(av) <= 2147483647))
		{
			printf("Error\nAlkhawa chni 3andek ntina al3ayl?");
			return (1);
		}
	}
	return (0);
}
