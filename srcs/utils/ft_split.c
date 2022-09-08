/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:58:11 by vahemere          #+#    #+#             */
/*   Updated: 2021/11/29 19:37:19 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sep(char s, char c)
{
	if (s == c)
		return (0);
	return (1);
}

int	nb_words(char const *s, char c)
{
	int	word;
	int	i;

	i = -1;
	word = 0;
	while (s[++i])
		if (is_sep((char)s[i], c) && (i == 0 || !is_sep((char)s[i - 1], c)))
			word++;
	return (word);
}

char	*put_in_tab(char const *s, char c)
{
	char	*tab;
	int		i;

	i = 0;
	while (s[i] && is_sep((char)s[i], c))
		i++;
	tab = malloc(sizeof(*tab) * (i + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (s[++i] && is_sep((char)s[i], c))
		tab[i] = s[i];
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		word;
	int		i;

	word = 0;
	i = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(*tab) * (nb_words(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i] && !is_sep((char)s[i], c))
		i++;
	i -= 1;
	while (s[++i] && word < nb_words(s, c))
	{
		if (is_sep((char)s[i], c) && (i == 0 || !is_sep((char)s[i - 1], c)))
		{
			tab[word] = put_in_tab(&s[i], c);
			word++;
		}
	}
	tab[word] = 0;
	return (tab);
}
