/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:29:50 by brhajji-          #+#    #+#             */
/*   Updated: 2022/09/24 04:31:52 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub3d.h"


void	my_mlx_pixel_put(t_data_engine *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->line_l + x * (data->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_pixel(t_data_engine *engine, void *img)
{
	int	i;
	int	j;
	(void)(img);
	i = -1;
	while (++i < 1080)
	{
		j = -1;
		while (++j < 1920)
		{
			if (i <= engine->player->vue_y)
				my_mlx_pixel_put(engine, j,
					i, 0x000000FF);
			else
				my_mlx_pixel_put(engine, j,
					i, 0x00FF0000);	
		}
	}
}

void	display_map(t_data_engine	*engine)
{
	engine->init->mlx = mlx_init();
	//engine->img->img = mlx_new_image(engine->init->mlx, 1920, 1080);
	//engine->img->addr = mlx_get_data_addr(engine->img->img, &engine->img->bpp,
	//		&engine->img->line_l, &engine->img->endian);
	engine->init->window = mlx_new_window(engine->init->mlx,  1920, 1080,
			"CUB3D");
	//put_pixel(engine, NULL);
	//insert_sprite(engine);
	//set_element_on_display(engine);
}