/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:31:21 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/10 20:05:17 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	malloc_texture2(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		info->texture[i] = ft_malloc(sizeof(int) * (64 * 64), &info->all->mem);
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
	return (1);
}

int	malloc_texture(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			info->buf[i][j] = 0;
	}
	info->texture = ft_malloc(sizeof(int *) * 4, &info->all->mem);
	if (!info->texture)
		return (0);
	if (!malloc_texture2(info))
		return (0);
	return (1);
}

int	load_texture(t_info *info)
{
	t_img	img;

	if (!malloc_texture(info))
		return (0);
	if (!load_image(info, info->texture[0],
			info->all->map->path_texture_no, &img))
		return (0);
	if (!load_image(info, info->texture[1],
			info->all->map->path_texture_so, &img))
		return (0);
	if (!load_image(info, info->texture[2],
			info->all->map->path_texture_we, &img))
		return (0);
	if (!load_image(info, info->texture[3],
			info->all->map->path_texture_ea, &img))
		return (0);
	return (1);
}

int	run_mlx(t_info *info)
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

int	exec(t_all *all)
{
	t_info	info;

	info.all = all;
	get_position_player(info.all->map->map, &info);
	info.re_buf = 0;
	info.tex_width = 64;
	info.tex_height = 64;
	info.move_speed = 0.099;
	info.rot_speed = 0.05;
	if (!run_mlx(&info))
		return (0);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 17, 0, mlx_loop_end, info.mlx);
	mlx_hook(info.win, 2, (1L << 0), key_press, &info);
	mlx_loop(info.mlx);
	info_free(&info);
	return (1);
}
