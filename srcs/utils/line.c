/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:27:58 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/27 16:02:31 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	first_line(char **map, t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ' && map[i][j] != '\n')
			j++;
		if (map[i][j] && map[i][j] != ' ' && map[i][j] != '\n')
			break ;
		i++;
	}
	all->map->first_line = i;
	return (i);
}

void	last_line(char **map, t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
		i++;
	i -= 1;
	while (i > 0)
	{
		j = 0;
		while (map[i][j] == ' ' && map[i][j] != '\n')
			j++;
		if (map[i][j] && map[i][j] != ' ' && map[i][j] != '\n')
			break ;
		i--;
	}
	all->map->last_line = i;
}
