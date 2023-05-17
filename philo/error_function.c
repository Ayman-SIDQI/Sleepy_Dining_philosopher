/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:06:30 by asidqi            #+#    #+#             */
/*   Updated: 2023/04/19 01:15:12 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strcmp1(char *s1, char *s2)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	if (s1[i] == '-' && s1[i + 1] == '0' && ft_iszerostring((char *)s1))
		i++;
	else if (s1[i] == '-' && s1[i + 1] == '0')
	{
		i++;
		o++;
	}
	while (s1[i] == '+')
		i++;
	while (s1[i + 1] && s1[i] == '0')
		i++;
	while ((s1[i] != '\0' || s2[o] != '\0'))
	{
		if (s1[i] != s2[o])
			return ((unsigned char)s1[i] - (unsigned char)s2[o]);
		i++;
		o++;
	}
	free(s2);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

static char	*ktebasidi(char *ret, long long int i, int size)
{
	if (i < 0)
	{
		i *= -1;
		while (--size > 0)
		{
			ret[size] = (i % 10) + 48;
			i = i / 10;
		}
		ret[size] = '-';
	}
	else
	{
		while (--size >= 0)
		{
			ret[size] = (i % 10) + 48;
			i /= 10;
		}
	}
	return (ret);
}

static int	chalmndigit(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long long int	i;
	int				size;
	char			*ret;

	i = n;
	size = chalmndigit(n);
	ret = (char *)malloc ((sizeof(char) * size) + 1);
	if (!ret)
		return (0);
	ret[size] = '\0';
	ret = ktebasidi(ret, i, size);
	return (ret);
}
