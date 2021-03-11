/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 02:32:35 by framdani          #+#    #+#             */
/*   Updated: 2019/10/31 07:30:12 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n)
	{
		*p = 0;
		p++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	si;

	si = count * size;
	if (!(ptr = (char*)malloc(si)))
		return (NULL);
	ft_bzero(ptr, si);
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	char		*s;
	size_t		i;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	if (!d && !s)
		return (NULL);
	if (d == s)
		return (unsigned char*)(dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (unsigned char*)(dest);
}
