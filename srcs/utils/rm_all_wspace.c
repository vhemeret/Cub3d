/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_all_wspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:50:19 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/11 19:16:35 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*copy_str(char *str, int i, char *ret)
{
	int	j;
	int	k;

	j = i;
	k = 0;
	while (str[j] && str[j] != '\n'
		&& ((str[j] < 9 || str[j] > 13) && str[j] != ' '))
	{
		ret[k] = str[j];
		k++;
		j++;
	}
	ret[k] = '\0';
	return (ret);
}

char	*rm_all_wspace(char *str, t_all *all)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (str[i] && str[i] != '\n'
		&& ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	j = i;
	while (str[j] && str[j] != '\n'
		&& ((str[j] < 9 || str[j] > 13) && str[j] != ' '))
		j++;
	ret = ft_malloc(sizeof(char) * ((j - i) + 1), &all->mem);
	if (!ret)
		return (NULL);
	return (copy_str(str, i, ret));
}
