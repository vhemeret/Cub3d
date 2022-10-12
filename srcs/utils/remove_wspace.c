/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_wspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:09:54 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/26 22:16:04 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*remove_wspace(char *str, t_all *all)
{
	int		i;
	int		j;
	int		k;
	char	*ret;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	j = i;
	while (str[j] && (str[j] < 9 || str[j] > 13))
		j++;
	ret = ft_malloc(sizeof(char) * ((j - i) + 1), &all->mem);
	if (!ret)
		return (NULL);
	j = i;
	k = 0;
	while (str[j] && (str[j] < 9 || str[j] > 13))
	{
		ret[k] = str[j];
		k++;
		j++;
	}
	ret[k] = '\0';
	return (ret);
}
