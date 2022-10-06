/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:05:21 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/05 20:23:21 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*static void check_wall(char **map, int i, int j, t_info *info)
{	
	if (map[i][j + 1])
	{
		if (map[i][j + 1] == '1')
			info->posX = j - 0.5;
	}
	else
		info->posX = j + 0.5;
	if (map[i + 1][j])
	{
		if (map[i + 1][j] == '1')
			info->posY = i - 0.5;
	}
	else
		info->posY = i + 0.5;
}*/

int	get_position_player(char **map, t_info *info)
{
	int	i;
	int	j;

	i = -1;
	(void)(map);

	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				{
					map[i][j] = 0;
					info->posX = i - 0.5;
					info->posY = j - 0.5;
					break;
				}
		}
	}
	/*if (info->posX == -1 || info->posY == -1)
		return (0);*/
	return (1);
}
