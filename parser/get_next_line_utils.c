/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 00:24:22 by framdani          #+#    #+#             */
/*   Updated: 2019/11/20 02:16:46 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		length;
	int		i;
	char	*res;

	length = 0;
	i = 0;
	if (!s1 && s2)
		length = ft_strlen(s2);
	else if (!s2 && s1)
		length = ft_strlen(s1);
	else if (s1 && s2)
		length = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = malloc(length + 1)))
		return (res);
	if (s1)
		while (*s1 != '\0')
			res[i++] = *(char *)s1++;
	if (s2)
		while (*s2 != '\0')
			res[i++] = *(char *)s2++;
	res[i] = '\0';
	return (res);
}

char		*ft_strdup(const char *s)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(ft_strlen(s) + 1);
	if (!tmp)
		return (NULL);
	while (s[i] != '\0')
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char		*ft_strchr(const char *s, int c)
{
	char	*ss;
	int		i;
	char	cc;

	i = 0;
	ss = (char *)s;
	cc = (char)c;
	while (ss[i] != cc)
	{
		if (ss[i] == '\0')
			return (NULL);
		i++;
	}
	return (ss + i);
}
