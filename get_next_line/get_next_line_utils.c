/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:51:59 by vahemere          #+#    #+#             */
/*   Updated: 2021/12/08 13:30:27 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char			*nws;
	unsigned int	len;
	unsigned int	s1_l;
	unsigned int	s2_l;
	unsigned int	i;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = -1;
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	len = s1_l + s2_l;
	nws = malloc(sizeof(char) * (len + 1));
	if (!nws)
		return (NULL);
	while (++i < s1_l)
		nws[i] = s1[i];
	i -= 1;
	while (++i < len)
		nws[i] = *s2++;
	nws[i] = '\0';
	return (nws);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	i = -1;
	str = (char *)s;
	while (++i <= len)
		if (str[i] == (char)c)
			return (&str[i]);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	size_t	s_len;
	size_t	i;
	char	*dst;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	dst = malloc(sizeof(char) * (s_len + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (s[++i])
		dst[i] = s[i];
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	else if (!s)
		return (NULL);
	if (ft_strlen(s) > start)
	{
		while (i < len && s[start])
		{
			dest[i] = s[start];
			start++;
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
