/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:05:21 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/27 20:48:37 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	get_position_player(char **map, t_pos *pos)
{
	int	i;
	int	j;

	i = -1;
	pos->x = -1;
	pos->y = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				pos->x = j;
				pos->y = i;
			}
		}
	}
	if (pos->x == -1 && pos->y == -1)
		return (0);
	return (1);
}
