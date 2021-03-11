/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 05:21:32 by framdani          #+#    #+#             */
/*   Updated: 2021/01/11 17:28:35 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/get_next_line.h"

int		check_rest(char **str, char **line)
{
	char *tmp;
	char *nl;

	if (*str)
	{
		tmp = ft_strchr(*str, '\n');
		if (tmp)
		{
			*tmp = '\0';
			if (!(*line = ft_strdup(*str)))
				return (-1);
			nl = *str;
			if (!(*str = ft_strdup(tmp + 1)))
				return (-1);
			free(nl);
			return (1);
		}
	}
	else
	{
		if (!(*str = ft_strdup("")))
			return (-1);
	}
	return (0);
}

int		check_nl(char **str, char **line, char **buff)
{
	char *tmp;
	char *nl;

	if (!(*str))
	{
		free(*buff);
		return (-1);
	}
	tmp = ft_strchr(*str, '\n');
	if (tmp)
	{
		*tmp = '\0';
		if (!(*line = ft_strdup(*str)))
			return (-1);
		nl = *str;
		if (!(*str = ft_strdup(tmp + 1)))
			return (-1);
		free(nl);
		free(*buff);
		return (1);
	}
	return (0);
}

int		check_buff(char **str, char **buff, char **line)
{
	char	*tmp;
	int		res;

	if (!(tmp = ft_strdup(*str)))
		return (-1);
	free(*str);
	if (!(*str = ft_strjoin(tmp, *buff)))
		return (-1);
	free(tmp);
	res = check_nl(str, line, buff);
	if (res != 0)
		return (res);
	return (0);
}

int		last_line(char **str, char **line, char **buff)
{
	free(*buff);
	if (*str)
	{
		if (!(*line = ft_strdup(*str)))
			return (-1);
		free(*str);
		*str = NULL;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			r;
	char		*buff;
	static char	*str;
	int			res;

	if (fd < 0 || (read(fd, NULL, 0)))
		return (-1);
	if ((res = check_rest(&str, line)) != 0)
		return (res);
	if (!(buff = malloc(32 + 1)))
	{
		if (str)
			free(str);
		return (-1);
	}
	while ((r = read(fd, buff, 32)) > 0)
	{
		buff[r] = '\0';
		if ((res = check_buff(&str, &buff, line)) != 0)
			return (res);
	}
	if (last_line(&str, line, &buff) == -1)
		return (-1);
	return (0);
}
