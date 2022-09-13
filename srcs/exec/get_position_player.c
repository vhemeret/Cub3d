/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:05:21 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/04 01:14:56 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int check_wall(char **map, int i, int j, t_pos *pos)
{
	(double)i;
	(double)j;
	
	if (map[i][j + 1])
		if (map[i][j + 1] == '1')
			pos->x = j - 0.5;
	else
		pos->x = j + 0.5;
			if (map[i][j + 1])
	if (map[i + 1][j] == '1')
			pos->y = i - 0.5;
	else
		pos->y = i + 0.5;
}

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
				check_wall(map, i, j, pos);
		}
	}
	if (pos->x == -1 || pos->y == -1)
		return (0);
	return (1);
}
