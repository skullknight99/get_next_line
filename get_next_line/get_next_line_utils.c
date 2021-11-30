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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	int		o_len;
	int		d_len;

	o_len = ft_strlen(s1);
	d_len = ft_strlen(s2);
	new = malloc ((o_len + d_len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (i < o_len)
		new[i++] = s1[j++];
	j = 0;
	while (j < d_len)
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;
	int		j;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	i = 0;
	j = 0;
	while (i < len && s[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (j < i)
		str[j++] = s[start++];
	str[i] = '\0';
	return (str);
}
