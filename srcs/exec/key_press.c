/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:11:42 by brhajji-          #+#    #+#             */
/*   Updated: 2022/10/10 19:03:28 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub3d.h"

int	key_press(int key, t_info *info)
{
	if (key == 119)
	{
		if ((info->pos_x + info->dir_x * info->move_speed) > 0
			&& '1' != info->all->map->map[((int)(info->pos_x + (info->dir_x
						* info->move_speed)))][(int)(info->pos_y)])
			info->pos_x += info->dir_x * info->move_speed;
		if ((info->pos_y + info->dir_y * info->move_speed) > 0
			&& '1' != info->all->map->map[(int)(info->pos_x)][((int)(info->pos_y
				+ (info->dir_y * info->move_speed)))])
			info->pos_y += info->dir_y * info->move_speed;
	}
	if (key == 115)
	{
		if ((info->pos_x - info->dir_x * info->move_speed) > 0
			&& '1' != info->all->map->map[(int)(info->pos_x
				- info->dir_x * info->move_speed)][(int)(info->pos_y)])
			info->pos_x -= info->dir_x * info->move_speed;
		if ((info->pos_y - info->dir_y * info->move_speed) > 0
			&& '1' != info->all->map->map[(int)(info->pos_x)][(int)(info->pos_y
				- info->dir_y * info->move_speed)])
			info->pos_y -= info->dir_y * info->move_speed;
	}
	if (key == 65307)
		mlx_loop_end(info->mlx);
	key_press_suite(key, info);
	return (0);
}

void	key_press_suite(int key, t_info *info)
{
	double	old_dirx;
	double	old_planex;

	if (key == 100)
	{
		if ((info->pos_x + info->dir_y * info->move_speed) > 0
			&& '1' != info->all->map->map[(int)(info->pos_x + info->dir_y
				* info->move_speed)][(int)(info->pos_y)])
			info->pos_x += info->dir_y * info->move_speed;
		if ((info->pos_y - info->dir_x * info->move_speed) > 0
			&& '1' != info->all->map->map[(int)(info->pos_x)][(int)(info->pos_y
				- info->dir_x * info->move_speed)])
			info->pos_y -= info->dir_x * info->move_speed;
	}
	if (key == 97)
	{
		if ((info->pos_x - info->dir_y * info->move_speed) > 0
			&& '1' != info->all->map->map[(int)(info->pos_x
				- info->dir_y * info->move_speed)][(int)(info->pos_y)])
			info->pos_x -= info->dir_y * info->move_speed;
		if ((info->pos_y + info->dir_x * info->move_speed) > 0
			&& '1' != info->all->map->map[(int)(info->pos_x)][(int)(info->pos_y
				+ info->dir_x * info->move_speed)])
			info->pos_y += info->dir_x * info->move_speed;
	}
	key_press_end(key, info);
}

void	key_press_end(int key, t_info *info)
{
	double	old_dirx;
	double	old_planex;

	if (key == 65363)
	{
		old_dirx = info->dir_x;
		info->dir_x = info->dir_x * cos(-info->rot_speed) - info->dir_y
			* sin(-info->rot_speed);
		info->dir_y = old_dirx * sin(-info->rot_speed) + info->dir_y
			* cos(-info->rot_speed);
		old_planex = info->plane_x;
		info->plane_x = info->plane_x * cos(-info->rot_speed) - info->plane_y
			* sin(-info->rot_speed);
		info->plane_y = old_planex * sin(-info->rot_speed) + info->plane_y
			* cos(-info->rot_speed);
	}
	if (key == 65361)
	{
		old_dirx = info->dir_x;
		info->dir_x = info->dir_x * cos(info->rot_speed) - info->dir_y
			* sin(info->rot_speed);
		info->dir_y = old_dirx * sin(info->rot_speed) + info->dir_y
			* cos(info->rot_speed);
		old_planex = info->plane_x;
		info->plane_x = info->plane_x * cos(info->rot_speed) - info->plane_y
			* sin(info->rot_speed);
		info->plane_y = old_planex * sin(info->rot_speed) + info->plane_y
			* cos(info->rot_speed);
	}
}
