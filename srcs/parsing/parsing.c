/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:38:02 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/15 15:49:01 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	init_data_map(t_map *data)
{
	data->path_texture_no = NULL;
	data->path_texture_so = NULL;
	data->path_texture_we = NULL;
	data->path_texture_ea = NULL;
	data->f_r = 0;		
	data->f_g = 0;		
	data->f_b = 0;
	data->c_r = 0;	
	data->c_g = 0;
	data->c_b = 0;
	data->map = NULL;
}

int	manage_parsing(char *path, char **map, t_all *all)
{
	if (!check_fd(path))
		return (0);
	map = get_map(path);
	all->map = malloc(sizeof(t_map));
	if (!all->map)
		return (0);
	if (map)
	{
		init_data_map(all->map);
		if (!check_map(map, all))
		{
			free_double_arr(map);
			return (0);
		}
		free_double_arr(map);
	}
	else
		return (0);
	return (1);
}
