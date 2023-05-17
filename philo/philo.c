/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:44:03 by asidqi            #+#    #+#             */
/*   Updated: 2023/05/17 16:05:56 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_general *all)
{
	int	i;

	i = 0;
	while (i < all->numberof_philos)
	{
		pthread_mutex_destroy(&(all->fork[i]));
		i++;
	}
	pthread_mutex_destroy(&all->printer);
	pthread_mutex_destroy(&all->death);
	free(all->ethos);
	free(all);
}

void	error_print(void)
{
	printf("Error\n");
}

void	infinite_check(t_general *all, int ac)
{
	while (1)
	{
		if (teat_chronos(all) == 1 || meals_done(all, ac))
		{
			join_all(all);
			break ;
		}
	}
	free_all(all);
}

int	main(int ac, char **av)
{
	t_general	*all;
	int			i;

	all = NULL;
	if (ac != 5 && ac != 6)
		return (1);
	all = initializer(av, ac);
	if (all == NULL)
		return (1);
	if (valid(av[5]) || valid_number(av))
		return (1);
	if (fork_create(all) == 1)
		return (free_all(all), 1);
	i = 0;
	while (i < all->numberof_philos)
	{
		all->ethos[i].lapse = 0;
		if (pthread_create(&all->ethos[i].philos, NULL, \
		&routine, &all->ethos[i]))
			return (free_all(all), error_print(), 1);
		// usleep(150);
		i = i + 1;
	}
	infinite_check(all, ac);
	return (0);
}
