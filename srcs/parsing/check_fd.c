/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:23:08 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/11 18:01:33 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_name_file(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (path[i - 4])
	{
		if (path[i - 1] != 'b' || path[i - 2] != 'u' || path[i - 3] != 'c'
			|| path[i - 4] != '.')
			return (0);
	}
	else
		return (0);
	return (1);
}

static int	check_is_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

static int	check_is_directory(char *path)
{
	int	fd;

	fd = open(path, __O_DIRECTORY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	check_fd(char *path)
{
	if (!check_name_file(path))
	{
		printf("Error\nWrong file name.\n");
		return (0);
	}
	else if (!check_is_file(path))
	{
		printf("Error\nFile does not exist.\n");
		return (0);
	}
	else if (!check_is_directory(path))
	{
		printf("Error\nFile is a directory.\n");
		return (0);
	}
	return (1);
}
