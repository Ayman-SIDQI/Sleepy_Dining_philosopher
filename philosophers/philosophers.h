/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:10:45 by asidqi            #+#    #+#             */
/*   Updated: 2023/04/19 18:47:15 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_general	t_general;

typedef struct s_info
{
	pthread_t			philos;
	size_t				lapse;
	int					meals;
	int					id;
	struct s_general	*usb;
}				t_info;

typedef struct s_general
{
	int					numberof_philos;
	int					time_toeat;
	int					time_tosleep;
	size_t				time_todie;
	size_t				start_ofprog;
	int					mn;
	short				habess;
	int					meal_number;
	pthread_mutex_t		fork[250];
	pthread_mutex_t		printer;
	pthread_mutex_t		death;
	t_info				*ethos;
}				t_general;

size_t		original_time(void);
short		eating(int i, t_info *all);
void		print_protec(t_general *all, int a, char *str);
void		my_sleep(size_t	to_sleep, t_general *all);
void		sleeping(int i, t_info *all);
void		*routine(void *arg);
short		fork_create(t_general *all);
t_general	*initializer(char **av, int ac);
void		join_all(t_general *all);
short		teat_chronos(t_general *all);
void		sleeping(int i, t_info *all);
void		*routine(void	*arg);
short		meals_done(t_general *all, int ac);
//=======================================================
int			ft_strcmp1(char *s1, char *s2);
int			ft_atoi(const char *str);
int			ft_isdigit(char *c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_itoa(int n);
int			ft_iszerostring(char *c);
short		valid(char *av);
short		valid_number(char **av);

#endif