/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:01:56 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/10 20:02:34 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	info_free(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img.img);
	if (info->win)
	{
		mlx_clear_window(info->mlx, info->win);
		mlx_destroy_window(info->mlx, info->win);
	}
	if (info->mlx)
	{
		mlx_destroy_display(info->mlx);
		free(info->mlx);
	}
	return (0);
}
