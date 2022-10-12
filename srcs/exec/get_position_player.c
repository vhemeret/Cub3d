/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:05:21 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/11 11:17:33 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	set_south_or_north(char c, t_info *info)
{
	if (c == 'S')
	{
		info->dir_x = 0.99;
		info->plane_x = 0;
		info->dir_y = 0;
		info->plane_y = -0.6;
	}
	else if (c == 'N')
	{
		info->dir_x = -0.99;
		info->plane_x = 0;
		info->dir_y = 0;
		info->plane_y = 0.6;
	}
}

static void	set_west_or_east(char c, t_info *info)
{
	if (c == 'W')
	{
		info->dir_x = 0;
		info->plane_x = -0.6;
		info->dir_y = -0.99;
		info->plane_y = 0;
	}
	else if (c == 'E')
	{
		info->dir_x = 0;
		info->plane_x = 0.6;
		info->dir_y = 0.99;
		info->plane_y = 0;
	}
}

int	get_position_player(char **map, t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				info->pos_x = i + 0.5;
				info->pos_y = j + 0.5;
				if (map[i][j] == 'S' || map[i][j] == 'N')
					set_south_or_north(map[i][j], info);
				if (map[i][j] == 'W' || map[i][j] == 'E')
					set_west_or_east(map[i][j], info);
				map[i][j] = 0;
				break ;
			}
		}
	}
	return (1);
}
