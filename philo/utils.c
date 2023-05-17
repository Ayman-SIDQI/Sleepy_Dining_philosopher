/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:03:56 by asidqi            #+#    #+#             */
/*   Updated: 2023/04/19 18:01:12 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

short	fork_create(t_general *all)
{
	int	i;

	i = 0;
	while (i < all->numberof_philos)
	{
		if (pthread_mutex_init(&all->fork[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&all->printer, NULL) != 0 || \
	pthread_mutex_init(&all->death, NULL) != 0)
		return (1);
	return (0);
}

t_general	*initializer_juj(t_general *all, char *av)
{
	int	i;

	i = 0;
	while (i < all->numberof_philos)
	{
		all->ethos[i].id = i + 1;
		all->ethos[i].meals = 0;
		all->ethos[i].usb = all;
		i++;
	}
	if (ft_atoi(av) < 1 || \
	all->numberof_philos < 1 || all->time_toeat < 1 || all->time_tosleep < 1)
		return (free(all->ethos), free(all), NULL);
	all->habess = 1;
	return (all);
}

t_general	*initializer(char **av, int ac)
{
	t_general	*all;
	int			i;

	i = 0;
	all = malloc(sizeof(t_general));
	if (!all)
		return (NULL);
	all->numberof_philos = ft_atoi(av[1]);
	all->ethos = (t_info *)malloc(sizeof(t_info) * all->numberof_philos);
	if (!all->ethos)
		return (free(all), NULL);
	all->time_todie = ft_atoi(av[2]);
	all->time_toeat = ft_atoi(av[3]);
	all->time_tosleep = ft_atoi(av[4]);
	all->start_ofprog = original_time();
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (free(all->ethos), free(all), NULL);
	else if (ac == 6)
		all->meal_number = ft_atoi(av[5]);
	else
		all->meal_number = -1;
	all = initializer_juj(all, av[2]);
	if (!all)
		return (NULL);
	return (all);
}

void	join_all(t_general *all)
{
	int	i;

	i = 0;
	while (i < all->numberof_philos)
	{
		if (pthread_join(all->ethos[i].philos, NULL) != 0)
			return ;
		i++;
	}
}

short	teat_chronos(t_general *all)
{
	size_t	now;
	int		i;

	i = 0;
	while (i < all->numberof_philos)
	{
		pthread_mutex_lock(&all->printer);
		now = (original_time() - all->start_ofprog) - all->ethos[i].lapse;
		pthread_mutex_unlock(&all->printer);
		if (now > all->time_todie)
		{
			pthread_mutex_lock(&all->death);
			all->habess = 0;
			pthread_mutex_unlock(&all->death);
			pthread_mutex_lock(&all->printer);
			printf("%lu %d %s\n", original_time() - all->start_ofprog, i + 1, \
			"died");
			if (all->numberof_philos == 1)
				pthread_mutex_unlock(&all->fork[0]);
			pthread_mutex_unlock(&all->printer);
			return (1);
		}
		i++;
	}
	return (0);
}
