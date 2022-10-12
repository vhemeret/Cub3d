/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:30:31 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/11 18:53:27 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*##################### LIBRARIES #####################*/

# include "minilibx_linux/mlx.h"
# include "srcs/get_next_line/get_next_line.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <string.h>

/*###################### DEFINE #######################*/

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define WIDTH 1080
# define HEIGHT 720

/*###################### STRUCT #######################*/

typedef struct s_mem
{
	struct s_mem	*next;
	void			*addr;
	struct s_mem	*back;
}				t_mem;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;
typedef struct s_face
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
	int	data;
}	t_face;

typedef struct s_map
{
	char	*path_texture_no;
	char	*path_texture_so;
	char	*path_texture_we;
	char	*path_texture_ea;
	int		f_rgb;
	int		c_rgb;
	int		width;
	int		first_line;
	int		last_line;
	int		start_line;
	int		end_line;
	char	**map_full;
	char	**map;
}	t_map;

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_all
{
	t_map	*map;
	t_pos	*pos;
	t_mem	*mem;
}	t_all;

typedef struct s_calc_utils
{
	double	ray_dirx;
	double	ray_diry;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	double	wall_x;
	double	perp_wall_dist;
}	t_calc_utils;

typedef struct s_info
{
	int				map_x;
	int				map_y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	int				tex_width;
	int				tex_height;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			plane_x;
	double			plane_y;
	void			*mlx;
	void			*win;
	int				buf[HEIGHT + 1][WIDTH + 1];
	int				**texture;
	int				side;
	int				tex_x;
	double			move_speed;
	double			rot_speed;
	int				re_buf;
	int				t_width;
	t_img			img;
	t_all			*all;
	t_calc_utils	utils;
}				t_info;

/*##################### PARSING #####################*/

int		manage_parsing(char *path, t_all *all);
int		check_fd(char *path);
char	**get_map(char *path, t_mem **mem);
int		check_map(char **map, t_all *all);
int		check_data(char **map, t_face face, t_all *all);
int		wich_data(char *data, t_face face);
int		check_path_texture(char *line, t_all *all);
int		check_value(char **rgb, t_all *all);
void	put_rgb_data(char c, char **rgb, t_map *data, t_all *all);
void	put_path_data(char **arr, t_all *all);
int		check_body_map(t_all *all);
char	**create_square(t_all *all, int last_line);
void	size_map(t_all *all, char *line);
void	replace_space(char **square);

/*##################### DISPLAY #####################*/

int		exec(t_all *all);
int		get_position_player(char **map, t_info *info);
int		load_image(t_info *info, int *texture, char *path, t_img *img);
void	draw_color_texture(t_info *info, int x, int tex_num, double step);
void	init_calc(t_info *info, int *step_x, int *step_y);
void	draw_utils(t_info *info, int step_x, int step_y);
void	dda(t_info *info, int step_x, int step_y);
void	draw(t_info *info);
int		get_num_tex(t_info *info);
void	calc(t_info *info);
int		main_loop(t_info *info);
int		key_press(int key, t_info *info);
int		key_press_suite(int key, t_info *info);
int		key_press_move_camera_right(int key, t_info *info);
int		key_press_move_camera_left(int key, t_info *info);

/*##################### CLEANING #####################*/

int		info_free(t_info *info);
void	*ft_malloc(size_t size, t_mem **mem);
void	ft_free(void *addr, t_mem **mem);
void	free_all(t_mem **mem);

/*##################### UTILS #####################*/

char	**ft_split(char const *s, char c, t_all *all);
char	*remove_wspace(char *str, t_all *all);
int		ft_atoi(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		first_line(char **map, t_all *all);
void	last_line(char **map, t_all *all);
char	*rm_all_wspace(char *str, t_all *all);

#endif