/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:38:02 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/25 17:31:51 by vahemere         ###   ########.fr       */
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
	data->map_full = NULL;
	data->map = NULL;
}

int	manage_parsing(char *path, t_all *all)
{
	if (!check_fd(path))
		return (0);
	all->map = ft_malloc(sizeof(t_map), &all->mem);
	if (!all->map)
		return (0);
	init_data_map(all->map);
	all->map->map_full = get_map(path, &all->mem);
	if (all->map->map_full)
	{
		if (!check_map(all->map->map_full, all))
			return (0);
	}
	else
		return (0);
	return (1);
}
