/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:33:18 by framdani          #+#    #+#             */
/*   Updated: 2021/03/04 19:19:34 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <sys/_types/_size_t.h>

int			ft_strcmp(const char *ss1, const char *ss2)
{
	size_t	i;

	i = 0;
	while (ss1[i] != '\0' || ss2[i] != '\0')
	{
		if (ss1[i] == ss2[i])
			i++;
		else
			return ((unsigned char)ss1[i] - (unsigned char)ss2[i]);
	}
	return (0);
}

int			ft_strncmp(const char *ss1, const char *ss2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (ss1[i] != '\0' || ss2[i] != '\0'))
	{
		if (ss1[i] == ss2[i])
			i++;
		else
			return ((unsigned char)ss1[i] - (unsigned char)ss2[i]);
	}
	return (0);
}

int			len_num(long long val)
{
	unsigned long long	n;
	int					cmpt;

	cmpt = 0;
	n = val;
	if (n < 0)
	{
		n = val * -1;
		cmpt++;
	}
	while (n >= 10)
	{
		n = n / 10;
		cmpt++;
	}
	return (cmpt);
}

long long	ft_atoi(const char *str)
{
	unsigned long long	a;
	long				sign;

	a = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		str++;
		sign = (-1);
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		a = a * 10 + *str - '0';
		str++;
	}
	if (a < 0 && sign < 0)
		return (0);
	if (a < 0 && sign > 0)
		return (-1);
	return (a * sign);
}

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
