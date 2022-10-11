/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:13:23 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/11 19:10:32 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_path_data(char **arr, t_all *all)
{
	if (arr[0][0] == 'N')
		all->map->path_texture_no = remove_wspace(arr[1], all);
	else if (arr[0][0] == 'S')
		all->map->path_texture_so = remove_wspace(arr[1], all);
	else if (arr[0][0] == 'W')
		all->map->path_texture_we = remove_wspace(arr[1], all);
	else if (arr[0][0] == 'E')
		all->map->path_texture_ea = remove_wspace(arr[1], all);
}

void	put_rgb_data(char c, char **rgb, t_map *data, t_all *all)
{
	if (c == 'F')
		data->f_rgb = 65536 * atoi(rm_all_wspace(rgb[0], all))
			+ 256 * atoi(rm_all_wspace(rgb[1], all))
			+ atoi(rm_all_wspace(rgb[2], all));
	else if (c == 'C')
		data->c_rgb = 65536 * atoi(rm_all_wspace(rgb[0], all))
			+ 256 * atoi(remove_wspace(rgb[1], all))
			+ atoi(rm_all_wspace(rgb[2], all));
}

int	wich_data(char *data, t_face face)
{	
	if (data[0])
	{
		if (data[0] == 'N')
			face.no = 1;
		else if (data[0] == 'S')
			face.so = 1;
		else if (data[0] == 'W')
			face.we = 1;
		else if (data[0] == 'E')
			face.ea = 1;
		else if (data[0] == 'F')
			face.f = 1;
		else if (data[0] == 'C')
			face.c = 1;
		else
			return (0);
	}
	else
	{
		(void)face;
		return (0);
	}
	return (1);
}

int	check_path_texture(char *line, t_all *all)
{
	int			fd;
	char		*path;
	int			i;

	i = 0;
	path = remove_wspace(line, all);
	while (path[i])
		i++;
	if (path[--i])
	{
		if (path[i] != 'm' && path[i] != 'M')
			return (0);
		if (path[i - 1] != 'p' && path[i - 2] != 'P')
			return (0);
		if (path[i - 2] != 'x' && path[i - 3] != 'X' && path[i - 3] != '.')
			return (0);
	}
	else
		return (0);
	fd = open(path, O_RDONLY);
	path = NULL;
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	check_value(char **rgb, t_all *all)
{
	int		i;
	int		j;
	int		nb;
	char	*rgb_clean;

	i = -1;
	while (rgb[++i])
	{
		rgb_clean = rm_all_wspace(rgb[i], all);
		j = -1;
		if (!rgb_clean[0])
			return (0);
		while (rgb_clean[++j] && rgb_clean[j] != '\n')
			if (rgb_clean[j] < '0' || rgb_clean[j] > '9')
				return (0);
	}
	i = -1;
	while (rgb[++i])
	{
		nb = ft_atoi(rm_all_wspace(rgb[i], all));
		if (nb < 0 || nb > 255)
			return (0);
	}
	return (1);
}
