/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmekky <mmekky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 06:29:29 by mmekky            #+#    #+#             */
/*   Updated: 2022/04/02 15:15:04 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-macos/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <errno.h>

# if MOUSE_FLAG
#  define MOUSE_POS map->mlx, map->win, &x, &y
# else
#  define MOUSE_POS map->win,&x,&y
# endif
# define SCREENWIDTH 720
# define SCREENHEIGHT 552
# define DIST_2_WALL 0.35
# define STEP_SIZE 0.05
# define SLIDE_DIST 0.3
# define DIST_2_CLOSEST_DOOR 1.5
# define NUM_SPRITE 1
# define YOUWIN_FIRST_INDEX 38
# define YOUWIN_LAST_INDEX 77
# define YOUWIN_N_IMGS 40
# define FLOOR_INDEX 4
# define CEILING_INDEX 5
# define COIN_FIRST_INDEX 6
# define COIN_LAST_INDEX 11
# define COIN_WIDTH_SCALER 3
# define COIN_HEIGHT_SCALER 3
# define COIN_MOV 200.0
# define COINSPEED 2
# define COIN_N_IMGS 6
# define EXIT_FIRST_INDEX 27
# define EXIT_LAST_INDEX 37
# define EXIT_WIDTH_SCALER 1
# define EXIT_HEIGHT_SCALER 1
# define EXIT_MOV 0.0
# define EXITSPEED 1
# define EXIT_N_IMGS 11
# define TREE_INDEX 12
# define TREE_WIDTH_SCALER 1.5
# define TREE_HEIGHT_SCALER 1.5
# define TREE_MOV 90.0
# define SKELETON_INDEX 13
# define SKELETON_WIDTH_SCALER 2
# define SKELETON_HEIGHT_SCALER 2
# define SKELETON_MOV 150.0
# define TOMBSTON_INDEX 14
# define TOMBSTONE_WIDTH_SCALER 2
# define TOMBSTONE_HEIGHT_SCALER 2
# define TOMBSTONE_MOV 150.0
# define DEADBUSH_INDEX 15
# define DEADBUSH_WIDTH_SCALER 2.5
# define DEADBUSH_HEIGHT_SCALER 2.5
# define DEADBUSH_MOV 200.0
# define LEFTARROWSIGN_INDEX 16
# define LEFTARROWSIGN_WIDTH_SCALER 1.5
# define LEFTARROWSIGN_HEIGHT_SCALER 1.5
# define LEFTARROWSIGN_MOV 90.0
# define RIGHTARROWSIGN_INDEX 17
# define RIGHTARROWSIGN_WIDTH_SCALER 1.5
# define RIGHTARROWSIGN_HEIGHT_SCALER 1.5
# define RIGHTARROWSIGN_MOV 90.0
# define DOORSPEED 2
# define DOOR_N_IMGS 9
# define OTHER_SPRITES_N_IMGS 6
# define SPRITES_NUMS 73
# define N_PATHS 75
# define FOCUSED_MINIMAP_SIZE 23
# define N_ELEMENTS 8
# define T_FLOOR 1
# define T_CEILING 1
# define FILENAMES_PATH "./pics/filenames.txt"
# define MAP_WIDTH_MAX 100
# define MAP_HEIGHT_MAX 100

//The smaller the number is the more number of rays will be sent
# define FOCUSED_MINIMAP_RAYS_NUM 0.2 

# define VISIBLEWALLCOLOR 0x33313131
# define VISIBLEEMPTYCOLOR 0x33cccccc
# define VISIBLECOINCOLOR 0x33DDAB16
# define VISIBLECLOSEDDOORCOLOR 0x330929D0
# define VISIBLEOPENEDDOORCOLOR 0x332CA2F4
# define VISIBLEPORTALCOLOR 0x33B10EDE
# define VISIBLEEXITCOLOR 0x339809C0
# define VISIBLESPRITESCOLOR 0x3384663F
# define VISIBLEPLAYERCOLOR 0x00FF0000

# define INVISIBLEWALLCOLOR 0x33000000
# define INVISIBLEEMPTYCOLOR 0x339C9C9C
# define INVISIBLECOINCOLOR 0x33AE8713
# define INVISIBLECLOSEDDOORCOLOR 0x33081F9A
# define INVISIBLEOPENEDDOORCOLOR 0x33207BBB
# define INVISIBLEPORTALCOLOR 0x33A30D84
# define INVISIBLEEXITCOLOR 0x337B089B
# define INVISIBLESPRITESCOLOR 0x33513E25
# define INVISIBLEPLAYERCOLOR 0x00FF0000
# define INVISIBLENOTHINGCOLOR 0x33595959

/**	Map Symbols**/
/**
 * * SPACE: Nothing
 * * 0: 		Empty
 * * 1:			Wall
 * * C: 		Collectables (Coins)
 * * N:			Player facing north
 * * S:			Player facing south
 * * E:			Player facing east
 * * W:			Player facing west
 * * D: 		Door
 * * G:			Goal (Exit)
 * * T:			Tree
 * * K:			Skeleton
 * * V:			Tomb stone (Grave)
 * * B:			Dead bush
 * * L:			Left arrow sign
 * * R:			Right arrow sign
**/

/* FOR MAC*/
// # define KEY_LEFT 0
// # define KEY_RIGHT 2
// # define KEY_UP 13
// # define KEY_DN 1
// # define ROT_LEFT 123
// # define ROT_RIGHT 124
// # define ESC 53
// # define MOUSE_SWITCH 42
// # define DOOR_SWITCH 49
// # define DISPLAY_FULL_MAP 40
// # define SPEED 0.3
// # define ANGLE 0.1
// # define LOOK_BACK 44
// # define YOUWINSPEED 6
// # define LEFT_BUTTON 1
// # define RIGHT_BUTTON 2

/* FOR LINUX*/
# define KEY_LEFT 97
# define KEY_RIGHT 100
# define KEY_UP 119
# define KEY_DN 115
# define ROT_LEFT 65361
# define ROT_RIGHT 65363
# define ESC 65307
# define MOUSE_SWITCH 92
# define DOOR_SWITCH 32
# define DISPLAY_FULL_MAP 65514
# define SPEED 0.3
# define ANGLE 0.15
# define LOOK_BACK 47
# define YOUWINSPEED 2
# define LEFT_BUTTON 1
# define RIGHT_BUTTON 3

typedef enum FACE
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	FLOOR,
	CEILING,
}	t_FACE;

typedef struct s_sprite
{
	int			texture;
	char		type;
	double		x;
	double		y;
}				t_sprite;

/**				Focused Minimap			**/
typedef struct s_fmm
{
	int			x;
	int			i;
	int			j;
	int			k;
	int			l;
	int			exit_flag;
	int			exit_cnt;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			sx;
	int			sy;
	int			error;
	int			e2;
	double		kk;
	double		ll;
	double		dx;
	double		dy;
	double		m;
	double		p_dx;
	double		p_dy;
	double		p_m;
}				t_fmm;

/**  Sprites Container  **/
typedef struct s_sc
{
	int			sprite_screen_x;
	int			sprite_height;
	int			draw_start_y;
	int			draw_end_y;
	int			sprite_width;
	int			draw_start_x;
	int			draw_end_x;
	int			move;
	double		sprite_x;
	double		sprite_y;
	double		invdet;
	double		transform_x;
	double		transform_y;
}				t_sc;

typedef struct s_map_p
{
	int	player_flag;
	int	exit_flag;
	int	filled;
	int	m_index;
}	t_map_p;

typedef struct s_minimap
{
	int				flag;
	int				width;
	int				height;
	int				block_width;
	int				block_height;
	int				map_width;
	int				map_height;
	int				bpp;
	int				line_len;
	int				endian;
	int				width_player;
	int				height_player;
	int				bpp_player;
	int				line_len_player;
	int				endian_player;
	char			*addr;
	char			*addr_player;
	void			*mlx;
	void			*win;
	void			*img;
	void			*img_player;
	double			pos_x;
	double			pos_y;
	double			p_pos_x;
	double			p_pos_y;
	double			start_x;
	double			start_y;
	double			r;

}	t_minimap;

/**  Floor Ceiling  **/
typedef struct s_fc
{
	int		pf;
	int		pc;
	int		cellx;
	int		celly;
	float	raydirx0;
	float	raydiry0;
	float	raydirx1;
	float	raydiry1;
	float	posf_z;
	float	row_distf;
	float	floor_stepx;
	float	floor_stepy;
	float	floorx;
	float	floory;
	float	posc_z;
	float	row_distc;
	float	ceiling_stepx;
	float	ceiling_stepy;
	float	ceilingx;
	float	ceilingy;
}	t_fc;

typedef struct s_coin
{
	double	pos_x;
	double	pos_y;
}				t_coin;

typedef struct s_texture
{
	int		bpp;
	int		line_len;
	int		endian;
	int		tex_width;
	int		tex_height;
	int		tex_x;
	int		tex_y;
	char	*addr;
	void	*mlx;
	void	*img;
	double	tex_pos;
}	t_texture;

typedef struct s_portal
{
	int		active;
	int		center_x;
	int		center_y;
	int		wall_tex;
	int		dir_x;
	int		dir_y;
	double	pos_x;
	double	pos_y;
	double	wall_x;
}	t_portal;

typedef struct s_lookup_table
{
	double	c_x[50];
	double	c_y[50];
	double	c_y_neg[50];
	int		size;
}	t_lookup_table;

typedef struct s_map
{
	char			**map;
	char			*fixed_files[6];
	int				parse_error_row;
	int				parse_error_col;
	int				coin_fps;
	int				coin_f_cnt;
	int				coin_flag;
	int				coin_first_ind;
	int				coin_last_ind;
	int				tree_index;
	int				skeleton_index;
	int				deadbush_index;
	int				tombstone_index;
	int				left_arrow_index;
	int				right_arrow_index;
	int				blue_portal_index;
	int				orange_portal_index;
	int				portal_gun_index;
	int				exit_fps;
	int				exit_f_cnt;
	int				exit_flag;
	int				exit_first_ind;
	int				exit_last_ind;
	int				youwin_f_cnt;
	int				youwin_fps;
	int				youwin_flag;
	int				youwin_first_ind;
	int				youwin_last_ind;
	t_coin			coin;
	int				door_ind_flag;
	int				door_switch;
	int				door_switch_key;
	int				door_flag;
	int				door_pos_x;
	int				door_pos_y;
	int				door_f_cnt;
	int				door_f_cnt_flag;
	int				door_first_ind;
	int				door_last_ind;
	int				look_back_key;
	int				look_back_key_prev;
	double			angle;
	int				prev_dirx;
	int				prev_diry;
	int				full_map;
	int				n_doors;
	int				door_x;
	int				door_y;
	int				door_index;
	int				exit_index;
	int				n_paths;
	int				first_path_ind;
	int				exit_is_open;
	int				you_win;
	int				youwin_index;
	double			hf_y;
	double			hf_x;
	double			perp_x;
	double			perp_y;
	int				fr;
	int				fg;
	int				fb;
	int				cr;
	int				cg;
	int				cb;
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			opp_dir_x;
	double			opp_dir_y;
	double			opp_plane_x;
	double			opp_plane_y;
	double			org_dir_x;
	double			org_dir_y;
	double			org_plane_x;
	double			org_plane_y;
	int				rotate_to_back;
	int				region;
	int				rot_back;
	int				rot_front;
	int				look_back_is_active;
	double			cam_x;
	double			cam_y;
	double			ray_x;
	double			ray_y;
	int				map_x;
	int				map_y;
	double			map_xs[SCREENWIDTH];
	double			map_ys[SCREENWIDTH];
	double			d_map_x;
	double			d_map_y;
	int				map_xy_cnt;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			step_x;
	double			step_y;
	double			wall_dist;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			time;
	double			prev_time;
	int				width;
	int				height;
	int				block_width;
	int				block_height;
	t_texture		tex[N_ELEMENTS - 2 + SPRITES_NUMS + 2];
	t_fc			fc;
	t_sc			sc;
	t_fmm			fmm;
	t_sprite		*sprite;
	t_sprite		*sprite_tmp;
	__uint32_t		buffer[SCREENHEIGHT][SCREENWIDTH];
	double			zbuffer[SCREENWIDTH];
	int				*sprite_order;
	double			*sprite_distance;
	int				sprite_cnt;
	int				coin_index;
	int				coin_cnt;
	int				**level;
	unsigned char	rgba[5];
	int				move_front;
	int				move_back;
	int				move_left;
	int				move_right;
	int				rotate_left;
	int				rotate_right;
	int				mouse_rotate_left;
	int				mouse_rotate_right;
	int				mouse_switch;
	int				mouse_switch_key;
	int				prev_mouse_x;
	t_portal		blue;
	t_portal		orange;
	int				portal_active;
	int				dir_vector[4][2];
	int				portal_wall;
	t_lookup_table	table;
	int				fd;
	double			new_x;
	double			new_y;
	unsigned int	color;
	int				mouse_reset;
}	t_map;

t_minimap		use_minimap(t_map *map);
t_minimap		use_focused_minimap(t_map *map);
void			draw_minimap_pixel(t_minimap *minimap, int x, int y, int flag);
void			create_map(t_map *map, int **level);
void			draw_player(t_minimap *minimap);
void			init_player(t_minimap *minimap);
void			plot_wall_lines(t_map *map, int x);
int				keyhooks_press(int key, t_map *map);
int				keyhooks_release(int key, t_map *map);
int				mouse_rotate(int x, int y, t_map *map);
int				redraw_frame(t_map *map);
int				error(int n, t_map *map);
void			parser(int fd, t_map *map);
void			skipper(t_map *map, int i, int *j, int flag);
int				elements_checker(t_map *map, int i, int *j);
void			allocation(t_map *map);
int				check_map_lines(char *m);
void			map_checker(t_map *map);
int				ft_file_pos_atoi(char *str);
char			*ft_strdup_2_space(const char *src);
void			map_parser(t_map *map);
void			elements_parser(t_map *map);
void			init(t_map *map);
void			free_all(t_map *map);
void			cub3d_mlx_pixel_put(t_map *map, int x, int y, __uint32_t color);
void			draw_fc(t_map *map);
int				ft_exit(t_map *map);
void			check_file(char *s, int flag, t_map *map);
void			create_sprites(t_map *map);
void			init_sprite(t_map *map, int i);
int				switches(int keycode, t_map *map);
int				portal(int key, int x, int y, t_map *map);
int				check_texture_hit(t_map *map, int x);
void			check_portal(t_map *map);
int				valid_portal(t_map *map, t_portal *p);
void			draw_portal(t_map *map, int x, int y);
__uint32_t		choose_pixel_color(t_map *map, int ind);
void			init_textures(t_map *map);
void			move_player(t_map *map);
void			slide_along_wall(t_map *map, char key);
int				is_walkable(t_map *map, double x, double y);
int				full_walkable_check(t_map *map, double y, double x, char flag);
void			moving_coin_sprites(t_map *map);
void			moving_exit_sprites(t_map *map);
void			moving_youwin_sprites(t_map *map);
void			display_youwin(t_map *map);
void			init_ray(t_map *map, int x);
void			check_ray_direction(t_map *map);
void			check_wall_hit(t_map *map, int **level, int x);
void			sprite_order_manager(t_map *map);
void			sprite_minimap_exit(t_map *map);
void			print_visible_area(char *dst);
int				is_visible(char *dst);
int				print_visibal_rays(t_minimap *minimap, char *dst, t_map *map);
void			draw_player_vision(t_minimap *minimap, t_map *map);
void			cover_visible_area(t_minimap *minimap, t_map *map);
void			draw_focused_minimap(t_minimap *minimap, t_map *map);
void			draw_fm_player(t_minimap *minimap);
void			fm_init_ray(t_map *map);
void			fm_check_ray_direction(t_map *map);
void			fm_check_wall_hit(t_map *map);
void			is_map_char_allowed(t_map *map, t_map_p *p, int i, int j);
void			draw_shooting_elements(t_map *map);
void			look_back(t_map *map);
void			init_lookup_table(t_lookup_table *table);
void			check_mouse_moving(t_map *map);
void			set_portal_positions(t_map *map);
void			rot_180(t_map *map, char flag);
int				get_region(t_map *map, int flag);
void			plot_fc(t_map *map, int y);
void			choose_sprite_height(t_map *map, int i);
void			choose_moving_sprite_width(t_map *map, int i);
void			choose_fixed_sprite_width(t_map *map, int i);
void			choos_sprite_pos(t_map *map, int i);
void			switch_door_status(t_map *map);
void			check_collectables(t_map *map);
void			rotate_player(t_map *map);
void			putnum_fd(t_map *map, int fd);

#endif
