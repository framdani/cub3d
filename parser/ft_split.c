/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:31:04 by framdani          #+#    #+#             */
/*   Updated: 2019/10/27 22:30:53 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_nbr_mots(const char *s, char c)
{
	int test;
	int nbr;
	int i;

	i = 0;
	test = 1;
	nbr = 0;
	while (s[i] != '\0')
	{
		if (test == 1 && s[i] != c)
		{
			nbr++;
			test = 0;
		}
		else if (s[i] == c)
		{
			test = 1;
		}
		i++;
	}
	return (nbr);
}

static int	ft_length_word(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i);
}

static char	*ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	if (!s)
		return (0);
	l = ft_nbr_mots(s, c);
	if (!(tab = malloc(sizeof(char *) * (l + 1))))
		return (NULL);
	while (i < l)
	{
		while ((k = ft_length_word(s, c)) == 0)
			s++;
		if (!(tab[i] = malloc(sizeof(char) * (k + 1))))
			ft_free(tab, i - 1);
		j = 0;
		while (j < k)
			tab[i][j++] = *s++;
		tab[i++][j] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
