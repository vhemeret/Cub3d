/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:31:21 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/07 06:41:08 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int malloc_texture(t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			info->buf[i][j] = 0;
	}
	info->texture = malloc(sizeof(int *) * 4);
	if (!info->texture)
		return (0);
	i = -1;
	while (++i < 4)
	{
		info->texture[i] = (int *)malloc(sizeof(int) * (64 * 64));
		if (!info->texture[i])
			return (0);
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < (64 * 64))
			info->texture[i][j] = 0;
	}
	return (i);
}

int load_texture(t_info *info)
{
	t_img img;

	if (!malloc_texture(info))
		return (0);
	if (!load_image(info, info->texture[0], info->all->map->path_texture_ea, &img))
		return (0);
	if (!load_image(info, info->texture[1], info->all->map->path_texture_no, &img))
		return (0);
	if (!load_image(info, info->texture[2], info->all->map->path_texture_so, &img))
		return (0);
	if (!load_image(info, info->texture[3], info->all->map->path_texture_we, &img))
		return (0);
	return (1);
}

int run_mlx(t_info *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
	{
		printf("Error: Failed to init Mlx\n");
		return (0);
	}
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "mlx");
	if (!info->win)
	{
		printf("Error: Failed to create window\n");
		return (0);
	}
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->img.img)
	{
		printf("Error: Failed to create image\n");
		return (0);
	}
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp,
		&info->img.size_l, &info->img.endian);
	if (!load_texture(info))
		return (0);
	return (1);
}

int exec(t_all *all)
{
	t_info info;

	info.all = all;
	get_position_player(info.all->map->map, &info);
	//info.dirX = -1.0;
	//info.dirY = 0.0;
/*	info.planeX = 0.0;
	info.planeY = 0.66;*/
	info.re_buf = 0;
	info.texWidth = 64;
	info.texHeight = 64;
	info.moveSpeed = 0.033;
	info.rotSpeed = 0.05;
	if (!run_mlx(&info))
	{
		printf("fewfew\n");
		return (0);
	}
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 17, 0, mlx_loop_end, info.mlx);
	mlx_hook(info.win, 2, (1L << 0), key_press, &info);
	mlx_loop(info.mlx);
	return (1);
}