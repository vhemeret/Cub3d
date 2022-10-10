/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:55:46 by brhajji-          #+#    #+#             */
/*   Updated: 2022/10/10 17:40:55 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub3d.h"

void	draw(t_info *info)
{
	//bzero(info->img.data, 720*1080);
	mlx_destroy_image(info->mlx, info->img.img);
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	//info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			info->img.data[y * WIDTH + x] = info->buf[y][x];
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int		get_num_tex(t_info *info, int mapX, int mapY)
{
	int texNum;

	texNum = 0;
	if (info->side == 0 && mapX - info->pos_x >= 0)
		texNum = 0;
	else if (info->side == 0 && mapX - info->pos_x < 0)
		texNum = 1;
	else if (info->side == 1 && mapY - info->pos_y < 0)
		texNum = 2;
	else if (info->side == 1 && mapY - info->pos_y >= 0)
		texNum = 3;
	return (texNum);
}

void	draw_color_texture(t_info *info, int x, int texNum, double step)
{
	double texPos;	
	int tmp = -1;
	int	y = info->draw_start -1;
	int	tex_y;
	int color;
	
	texPos = (info->draw_start - HEIGHT / 2 + info->line_height / 2) * step;
	while (++tmp < info->draw_start)
		info->buf[tmp][x] = info->all->map->c_rgb;
	tmp = info->draw_End - 1;
	while (++tmp < HEIGHT)
		info->buf[tmp][x] = info->all->map->f_rgb;
	while (++y <= info->draw_End)
	{
		tex_y = (int)texPos & (info->tex_height - 1);
		texPos += step;
		color = info->texture[texNum][info->tex_height * tex_y + info->tex_x];
		if (info->side == 1)
			color = (color >> 1) & 8355711;
		info->buf[y][x] = color;
		info->re_buf = 1;
	}
}

void	init_calc(t_info *info, int *stepX, int *stepY, int *mapX, int *mapY)
{
	info->utils.delta_distx = fabs(1 / info->utils.ray_dirx);
	info->utils.delta_disty = fabs(1 / info->utils.ray_diry);
	if (info->utils.ray_dirx < 0)
	{
		*stepX = -1;
		info->utils.side_distx = (info->pos_x - *mapX) * info->utils.delta_distx;
	}
	else
	{
		*stepX = 1;
		info->utils.side_distx = (*mapX + 1.0 - info->pos_x) * info->utils.delta_distx;
	}
	if (info->utils.ray_diry < 0)
	{
		*stepY = -1;
		info->utils.side_disty = (info->pos_y - *mapY) * info->utils.delta_disty;
	}
	else
	{
		*stepY = 1;
		info->utils.side_disty = (*mapY + 1.0 - info->pos_y) * info->utils.delta_disty;
	}
}

void	draw_utils(t_info *info, int mapX, int mapY, int stepX, int stepY)
{
		if (info->side == 0)
			info->utils.perp_wall_dist = (mapX - info->pos_x + (1 - stepX) / 2) / info->utils.ray_dirx;
		else
			info->utils.perp_wall_dist = (mapY - info->pos_y + (1 - stepY) / 2) / info->utils.ray_diry;
		info->line_height = (int)(HEIGHT / info->utils.perp_wall_dist);
		info->draw_start = -info->line_height / 2 + HEIGHT / 2;
		if(info->draw_start < 0)
			info->draw_start = 0;
		info->draw_End = info->line_height / 2 + HEIGHT / 2;
		if(info->draw_End >= HEIGHT)
			info->draw_End = HEIGHT - 1;
		if (info->side == 0)
			info->utils.wall_x = info->pos_y + info->utils.perp_wall_dist * info->utils.ray_diry;
		else
			info->utils.wall_x = info->pos_x + info->utils.perp_wall_dist * info->utils.ray_dirx;
		info->utils.wall_x -= floor(info->utils.wall_x);
		info->tex_x = (int)(info->utils.wall_x * (double)info->tex_width);
		if (info->side == 0 && info->utils.ray_dirx > 0)
			info->tex_x = info->tex_width - info->tex_x - 1;
		if (info->side == 1 && info->utils.ray_diry < 0)
			info->tex_x = info->tex_width - info->tex_x - 1;
}

void	dda(t_info *info, int *mapX, int *mapY, int stepX, int stepY)
{
	while (*mapX >= 0 && *mapY >= 0)
	{
		if (info->utils.side_distx < info->utils.side_disty)
		{
			info->utils.side_distx += info->utils.delta_distx;
			*mapX += stepX;
			info->side = 0;
		}
		else
		{
			info->utils.side_disty += info->utils.delta_disty;
			*mapY += stepY;
			info->side = 1;
		}
		if (info->all->map->map[*mapX][*mapY] && info->all->map->map[*mapX][*mapY] > '0' && info->all->map->map[*mapX][*mapY] != '*')
			break;
	}
}

void	calc(t_info *info)
{
	int	x;
	int mapX;
	int mapY;
	int stepX;
	int stepY;

	x = -1;
	while (++x < WIDTH)
	{
		mapX = (int)info->pos_x;
		mapY = (int)info->pos_y;
		
		info->utils.ray_dirx = info->dir_x + (info->plane_x * ((double)(2 * x / (double)WIDTH - 1)));
		info->utils.ray_diry = info->dir_y + (info->plane_y * ((double)(2 * x / (double)WIDTH - 1)));
		init_calc(info, &stepX, &stepY, &mapX, &mapY);
		dda(info, &mapX, &mapY, stepX, stepY);
		draw_utils(info, mapX, mapY, stepX, stepY);
		draw_color_texture(info, x, get_num_tex(info, mapX, mapY), (double)(1.0 * info->tex_height / info->line_height));
	}
}

int	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;
	
	y = -1;
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	if (!img->img)
	{
		return (0);
	}
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	if (!img->data)
	{
		mlx_destroy_image(info->mlx, img->img);
		return (0);
	}
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx, img->img);
	return (1);
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}
