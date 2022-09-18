/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:30:31 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/18 17:15:39 by vahemere         ###   ########.fr       */
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

/*##################### STRUCTURES #####################*/

// typedef struct s_mem
// {
// 	struct s_mem	*next;
// 	void			*addr;
// }				t_mem;

typedef struct s_face
{
	int	NO;
	int SO;
	int	WE;
	int	EA;
	int	F;
	int C;
	int data;
}	t_face;

typedef struct s_map
{
	char	*path_texture_no;
	char	*path_texture_so;
	char	*path_texture_we;
	char	*path_texture_ea;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	char	**map_full;
	char	**map;
	int		nb_line;
}	t_map;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_all
{
	t_map	*map;
	t_pos	*pos;
} t_all;

/*##################### PARSING #####################*/

int		manage_parsing(char *path, t_all *all);
int		check_fd(char *path);
char	**get_map(char *path);
int		check_map(char **map, t_all *all);
int		check_data(char **map, t_face face, t_map *data);
int		wich_data(char *data, t_face face);
int		check_path_texture(char *line);
int		check_value(char **rgb);
void	put_rgb_data(char **arr, char **rgb, t_map *data);
void	put_path_data(char **arr, t_map *data);
int		check_body_map(t_all *all);

/*##################### EXEC #####################*/

int		get_position_player(char **map, t_pos *pos);

/*##################### CLEANING #####################*/

void	free_double_arr(char **arr);

/*##################### UTILS #####################*/

char	**ft_split(char const *s, char c);
char	*remove_wspace(char *str);
int		ft_atoi(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif