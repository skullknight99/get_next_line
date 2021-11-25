/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:08:02 by acmaghou          #+#    #+#             */
/*   Updated: 2021/11/25 14:36:22 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*srx;
	size_t			i;

	i = 0;
	dst = (unsigned char *)dest;
	srx = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dst[i] = srx[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s + start);
	if (len > i)
		len = i;
	t = malloc((len + 1) * sizeof(char));
	if (!t)
		return (NULL);
	t[len + 1] = '\0';
	if (start < ft_strlen(s) && len > 0)
		ft_memcpy(t, s + start, len);
	return (t);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char)) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}
