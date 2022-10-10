/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:11:42 by brhajji-          #+#    #+#             */
/*   Updated: 2022/10/10 15:53:33 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub3d.h"

int	key_press(int key, t_info *info)
{
	if (key == 119)
	{
		if ((info->posX + info->dirX * info->moveSpeed) > 0 && '1' != info->all->map->map[((int)(info->posX + (info->dirX * info->moveSpeed)))][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if ((info->posY + info->dirY * info->moveSpeed) > 0 && '1' != info->all->map->map[(int)(info->posX)][((int)(info->posY + (info->dirY * info->moveSpeed)))])
			info->posY += info->dirY * info->moveSpeed;
	}
	if (key == 115)
	{
		if ((info->posX - info->dirX * info->moveSpeed) > 0 && '1' != info->all->map->map[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if ((info->posY -  info->dirY * info->moveSpeed) > 0 && '1' != info->all->map->map[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
	}
	if (key == 97)
	{
		if ((info->posX - info->dirY * info->moveSpeed) > 0 && '1' != info->all->map->map[(int)(info->posX - info->dirY * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirY * info->moveSpeed;
		if ((info->posY + info->dirX * info->moveSpeed) > 0 && '1' != info->all->map->map[(int)(info->posX)][(int)(info->posY + info->dirX * info->moveSpeed)])
			info->posY += info->dirX * info->moveSpeed;
	}
	if (key == 65307)
		mlx_loop_end(info->mlx);
	key_press_suite(key, info);
	return (0);
}

void	key_press_suite(int key, t_info *info)
{
	double	oldDirX;
	double	oldPlaneX;
	
	if (key == 100)
	{
		if ((info->posX + info->dirY * info->moveSpeed) > 0 && '1' != info->all->map->map[(int)(info->posX + info->dirY * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirY * info->moveSpeed;
		if ((info->posY - info->dirX * info->moveSpeed) > 0 && '1' != info->all->map->map[(int)(info->posX)][(int)(info->posY - info->dirX * info->moveSpeed)])
			info->posY -= info->dirX * info->moveSpeed;
	}
	if (key == 65363)//100
	{
		oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	key_press_end(key, info);
}

void	key_press_end(int key, t_info *info)
{
	double	oldDirX;
	double	oldPlaneX;
	
	if (key == 65361)//97
	{
		oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
}