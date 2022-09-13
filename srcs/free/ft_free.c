/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:23:07 by brhajji-          #+#    #+#             */
/*   Updated: 2022/09/13 14:03:19 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub3d.h"


void	free_map(t_data_engine	*engine)
{
	int	i;

	i = 0;
	while (i < engine->map->line)
	{
		if (engine->map->map[i])
			free(engine->map->map[i]);
		i++;
	}
	if (engine->map->map)
		free(engine->map->map);
	if (engine->map)
		free(engine->map);
}

int	litle_free(t_data_engine	*engine)
{
	if (engine->img)
		free_img(engine);
	if (engine->init)
		free(engine->init);
	if (engine->map)
		free_map(engine);
	if (engine->player)
		free(engine->player);
	free(engine);
	return (0);
}

int	game_over(t_data_engine	*engine)
{
	if (engine->img && engine->img->img)
		mlx_destroy_image(engine->init->mlx, engine->img->img);
	if (engine->img)
		free_img(engine);
	if (engine->init->window)
	{
		mlx_clear_window(engine->init->mlx, engine->init->window);
		mlx_destroy_window(engine->init->mlx, engine->init->window);
	}
	if (engine->init->mlx)
	{
		mlx_destroy_display(engine->init->mlx);
		free(engine->init->mlx);
	}
	if (engine->init)
		free(engine->init);
	if (engine->map)
		free_map(engine);
	if (engine->player)
		free(engine->player);
	free(engine);
	return (0);
}