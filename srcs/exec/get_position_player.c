/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:05:21 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/10 17:21:41 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*static void check_wall(char **map, int i, int j, t_info *info)
{	
	if (map[i][j + 1])
	{
		if (map[i][j + 1] == '1')
			info->pos_x = j - 0.5;
	}
	else
		info->pos_x = j + 0.5;
	if (map[i + 1][j])
	{
		if (map[i + 1][j] == '1')
			info->pos_y = i - 0.5;
	}
	else
		info->pos_y = i + 0.5;
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
					//printf("pos_y = %i, pos_x = %i, haut = %c , bas = %c, droite = %c , gauche =  %c\n", i, j, map[i - 1][j], map[i + 1][j], map[i][j + 1], map[i][j - 1]);
					info->pos_x = i + 0.5;
					info->pos_y = j + 0.5;
					if (map[i][j] == 'S')//SUD
					{
						info->dir_x = 0.99;
						info->plane_x = 0;
						info->dir_y = 0;
						info->plane_y = -0.6;
					}
					if (map[i][j] == 'N')//NORD
					{
						info->dir_x = -0.99;
						info->plane_x = 0;
						info->dir_y = 0;
						info->plane_y = 0.6;
					}
					if (map[i][j] == 'W')
					{
						info->dir_x = 0;
						info->plane_x = -0.6;
						info->dir_y = -0.99;
						info->plane_y = 0;
					}
					if (map[i][j] == 'E')
					{
						info->dir_x = 0;
						info->plane_x = 0.6;
						info->dir_y = 0.99;
						info->plane_y = 0;
					}
					map[i][j] = 0;

					break;
				}
		}
	}
	/*if (info->pos_x == -1 || info->pos_y == -1)
		return (0);*/
	return (1);
}
