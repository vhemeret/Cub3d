/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:05:21 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/08 02:04:52 by brhajji-         ###   ########.fr       */
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
					//printf("posy = %i, posX = %i, haut = %c , bas = %c, droite = %c , gauche =  %c\n", i, j, map[i - 1][j], map[i + 1][j], map[i][j + 1], map[i][j - 1]);
					info->posX = i + 0.5;
					info->posY = j + 0.5;
					if (map[i][j] == 'S')//SUD
					{
						info->dirX = 1;
						info->planeX = 0;
						info->dirY = 0;
						info->planeY = -0.6;
					}
					if (map[i][j] == 'N')//NORD
					{
						info->dirX = -1;
						info->planeX = 0;
						info->dirY = 0;
						info->planeY = 0.6;
					}
					if (map[i][j] == 'W')
					{
						info->dirX = 0;
						info->planeX = -0.6;
						info->dirY = -1;
						info->planeY = 0;
					}
					if (map[i][j] == 'E')
					{
						info->dirX = 0;
						info->planeX = 0.6;
						info->dirY = 1;
						info->planeY = 0;
					}
					map[i][j] = 0;

					break;
				}
		}
	}
	/*if (info->posX == -1 || info->posY == -1)
		return (0);*/
	return (1);
}
