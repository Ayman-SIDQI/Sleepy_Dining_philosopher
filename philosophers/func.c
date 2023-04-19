/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:44:10 by asidqi            #+#    #+#             */
/*   Updated: 2023/04/19 15:10:59 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

size_t	original_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	print_protec(t_general *all, int a, char *str)
{
	pthread_mutex_lock(&all->printer);
	pthread_mutex_lock(&all->death);
	if (all->habess)
		printf("%lu %d %s\n", original_time() - all->start_ofprog, a, str);
	pthread_mutex_unlock(&all->death);
	pthread_mutex_unlock(&all->printer);
}

void	my_sleep(size_t	to_sleep, t_general *all)
{
	size_t	start;

	start = original_time();
	pthread_mutex_lock(&all->death);
	while (original_time() - start <= to_sleep && all->habess)
	{
		pthread_mutex_unlock(&all->death);
		usleep(200);
		pthread_mutex_lock(&all->death);
	}
	pthread_mutex_unlock(&all->death);
}

short	eating(int i, t_info *all)
{
	print_protec(all->usb, i, "is eating");
	pthread_mutex_lock(&all->usb->printer);
	all->lapse = original_time() - all->usb->start_ofprog;
	pthread_mutex_unlock(&all->usb->printer);
	my_sleep(all->usb->time_toeat, all->usb);
	pthread_mutex_lock(&all->usb->death);
	all->meals++;
	pthread_mutex_unlock(&all->usb->death);
	return (0);
}
