/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:31:10 by brhajji-          #+#    #+#             */
/*   Updated: 2022/10/10 18:54:20 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub3d.h"

void	init_calc(t_info *info, int *step_x, int *step_y)
{
	info->utils.delta_distx = fabs(1 / info->utils.ray_dirx);
	info->utils.delta_disty = fabs(1 / info->utils.ray_diry);
	if (info->utils.ray_dirx < 0)
	{
		*step_x = -1;
		info->utils.side_distx = (info->pos_x - info->map_x)
			* info->utils.delta_distx;
	}
	else
	{
		*step_x = 1;
		info->utils.side_distx = (info->map_x + 1.0 - info->pos_x)
			* info->utils.delta_distx;
	}
	if (info->utils.ray_diry < 0)
	{
		*step_y = -1;
		info->utils.side_disty = (info->pos_y - info->map_y)
			* info->utils.delta_disty;
	}
	else
	{
		*step_y = 1;
		info->utils.side_disty = (info->map_y + 1.0 - info->pos_y)
			* info->utils.delta_disty;
	}
}

void	dda(t_info *info, int step_x, int step_y)
{
	while (info->map_x >= 0 && info->map_y >= 0)
	{
		if (info->utils.side_distx < info->utils.side_disty)
		{
			info->utils.side_distx += info->utils.delta_distx;
			info->map_x += step_x;
			info->side = 0;
		}
		else
		{
			info->utils.side_disty += info->utils.delta_disty;
			info->map_y += step_y;
			info->side = 1;
		}
		if (info->all->map->map[info->map_x][info->map_y]
			&& info->all->map->map[info->map_x][info->map_y] > '0'
				&& info->all->map->map[info->map_x][info->map_y] != '*')
			break ;
	}
}

void	calc(t_info *info)
{
	int	x;
	int	step_x;
	int	step_y;

	x = -1;
	while (++x < WIDTH)
	{
		info->map_x = (int)info->pos_x;
		info->map_y = (int)info->pos_y;
		info->utils.ray_dirx = info->dir_x + (info->plane_x
				* ((double)(2 * x / (double)WIDTH - 1)));
		info->utils.ray_diry = info->dir_y + (info->plane_y
				* ((double)(2 * x / (double)WIDTH - 1)));
		init_calc(info, &step_x, &step_y);
		dda(info, step_x, step_y);
		draw_utils(info, step_x, step_y);
		draw_color_texture(info, x, get_num_tex(info),
			(double)(1.0 * info->tex_height / info->line_height));
	}
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}
