/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:38:02 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/04 00:29:10 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	manage_parsing(char *path, char **map)
{
	if (!check_fd(path))
		return (0);
	map = get_map(path);
	if (map)
	{
		if (!check_map(map))
			return (0);
	}
	else
		return (0);
	return (1);
}
