/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:11:42 by brhajji-          #+#    #+#             */
/*   Updated: 2022/10/11 13:00:16 by vahemere         ###   ########.fr       */
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
	return (key_press_suite(key, info));
}

int	key_press_suite(int key, t_info *info)
{
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
	return (key_press_move_camera_right(key, info));
}

int	key_press_move_camera_right(int key, t_info *info)
{
	double	tmp;

	if (key == 65363)
	{
		tmp = info->dir_x;
		info->dir_x = info->dir_x * cos(-info->rot_speed) - info->dir_y
			* sin(-info->rot_speed);
		info->dir_y = tmp * sin(-info->rot_speed) + info->dir_y
			* cos(-info->rot_speed);
		tmp = info->plane_x;
		info->plane_x = info->plane_x * cos(-info->rot_speed) - info->plane_y
			* sin(-info->rot_speed);
		info->plane_y = tmp * sin(-info->rot_speed) + info->plane_y
			* cos(-info->rot_speed);
	}
	return (key_press_move_camera_left(key, info));
}

int	key_press_move_camera_left(int key, t_info *info)
{
	double	tmp;

	if (key == 65361)
	{
		tmp = info->dir_x;
		info->dir_x = info->dir_x * cos(info->rot_speed) - info->dir_y
			* sin(info->rot_speed);
		info->dir_y = tmp * sin(info->rot_speed) + info->dir_y
			* cos(info->rot_speed);
		tmp = info->plane_x;
		info->plane_x = info->plane_x * cos(info->rot_speed) - info->plane_y
			* sin(info->rot_speed);
		info->plane_y = tmp * sin(info->rot_speed) + info->plane_y
			* cos(info->rot_speed);
	}
	return (0);
}
