/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:21:26 by asidqi            #+#    #+#             */
/*   Updated: 2023/05/17 16:07:27 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	sleeping(int i, t_info *all)
{
	print_protec(all->usb, i, "is sleeping");
	my_sleep(all->usb->time_tosleep, all->usb);
}

void	*routine(void	*arg)
{
	t_info			*priv;
	int				i;

	priv = (t_info *)arg;
	i = priv->id;
	if (i % 2 == 0)
		my_sleep(priv->usb->time_toeat / 2, priv->usb);
	pthread_mutex_lock(&priv->usb->death);
	while (priv->usb->habess)
	{
		pthread_mutex_unlock(&priv->usb->death);
		print_protec(priv->usb, i, "is thinking");
		pthread_mutex_lock(&priv->usb->fork[i - 1]);
		print_protec(priv->usb, i, "has taken a fork");
		pthread_mutex_lock(&priv->usb->fork[i % priv->usb->numberof_philos]);
		print_protec(priv->usb, i, "has taken a fork");
		if (eating(i, priv) == 1)
			return (NULL);
		pthread_mutex_unlock(&priv->usb->fork[i - 1]);
		pthread_mutex_unlock(&priv->usb->fork[i % priv->usb->numberof_philos]);
		sleeping(i, priv);
		pthread_mutex_lock(&priv->usb->death);
	}
	pthread_mutex_unlock(&priv->usb->death);
	return (NULL);
}

short	meals_done(t_general *all, int ac)
{
	int	i;

	i = 0;
	if (ac != 6)
		return (0);
	while (i < all->numberof_philos)
	{
		pthread_mutex_lock(&all->death);
		if (all->ethos[i].meals < all->meal_number)
		{
			pthread_mutex_unlock(&all->death);
			return (0);
		}
		pthread_mutex_unlock(&all->death);
		i++;
	}
	pthread_mutex_lock(&all->death);
	all->habess = 0;
	pthread_mutex_unlock(&all->death);
	return (1);
}
