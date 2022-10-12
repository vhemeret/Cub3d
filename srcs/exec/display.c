/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:29:50 by brhajji-          #+#    #+#             */
/*   Updated: 2022/10/11 13:01:49 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub3d.h"

void	draw(t_info *info)
{
	int	y;
	int	x;

	y = -1;
	mlx_destroy_image(info->mlx, info->img.img);
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			info->img.data[y * WIDTH + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int	get_num_tex(t_info *info)
{
	int	tex_num;

	tex_num = 0;
	if (info->side == 0 && info->map_x - info->pos_x >= 0)
		tex_num = 0;
	else if (info->side == 0 && info->map_x - info->pos_x < 0)
		tex_num = 1;
	else if (info->side == 1 && info->map_y - info->pos_y < 0)
		tex_num = 2;
	else if (info->side == 1 && info->map_y - info->pos_y >= 0)
		tex_num = 3;
	return (tex_num);
}

void	draw_color_texture(t_info *info, int x, int tex_num, double step)
{
	double	tex_pos;	
	int		tmp;
	int		y;
	int		tex_y;
	int		color;

	y = info->draw_start -1;
	tmp = -1;
	tex_pos = (info->draw_start - HEIGHT / 2 + info->line_height / 2) * step;
	while (++tmp < info->draw_start)
		info->buf[tmp][x] = info->all->map->c_rgb;
	tmp = info->draw_end - 1;
	while (++tmp < HEIGHT)
		info->buf[tmp][x] = info->all->map->f_rgb;
	while (++y <= info->draw_end)
	{
		tex_y = (int)tex_pos & (info->tex_height - 1);
		tex_pos += step;
		color = info->texture[tex_num][info->tex_height * tex_y + info->tex_x];
		if (info->side == 1)
			color = (color >> 1) & 8355711;
		info->buf[y][x] = color;
		info->re_buf = 1;
	}
}

void	draw_utils(t_info *info, int step_x, int step_y)
{
	if (info->side == 0)
		info->utils.perp_wall_dist = (info->map_x - info->pos_x
				+ (1 - step_x) / 2) / info->utils.ray_dirx;
	else
		info->utils.perp_wall_dist = (info->map_y - info->pos_y
				+ (1 - step_y) / 2) / info->utils.ray_diry;
	info->line_height = (int)(HEIGHT / info->utils.perp_wall_dist);
	info->draw_start = -info->line_height / 2 + HEIGHT / 2;
	if (info->draw_start < 0)
		info->draw_start = 0;
	info->draw_end = info->line_height / 2 + HEIGHT / 2;
	if (info->draw_end >= HEIGHT)
		info->draw_end = HEIGHT - 1;
	if (info->side == 0)
		info->utils.wall_x = info->pos_y + info->utils.perp_wall_dist
			* info->utils.ray_diry;
	else
		info->utils.wall_x = info->pos_x + info->utils.perp_wall_dist
			* info->utils.ray_dirx;
	info->utils.wall_x -= floor(info->utils.wall_x);
	info->tex_x = (int)(info->utils.wall_x * (double)info->tex_width);
	if (info->side == 0 && info->utils.ray_dirx > 0)
		info->tex_x = info->tex_width - info->tex_x - 1;
	if (info->side == 1 && info->utils.ray_diry < 0)
		info->tex_x = info->tex_width - info->tex_x - 1;
}

int	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	y = -1;
	img->img = mlx_xpm_file_to_image(info->mlx, path,
			&img->img_width, &img->img_height);
	if (!img->img)
		return (0);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_l, &img->endian);
	if (!img->data)
	{
		mlx_destroy_image(info->mlx, img->img);
		return (0);
	}
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	mlx_destroy_image(info->mlx, img->img);
	return (1);
}
