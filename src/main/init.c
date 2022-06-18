/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmekky <mmekky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:04:54 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 08:14:34 by mmekky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_sprite_indexes(t_map *map)
{
	map->first_path_ind = N_ELEMENTS - 3;
	map->door_index = 3;
	map->door_first_ind = map->first_path_ind + 13;
	map->coin_index = map->first_path_ind + 1;
	map->coin_first_ind = map->first_path_ind + 1;
	map->coin_last_ind = map->first_path_ind + 6;
	map->youwin_index = map->first_path_ind + 33;
	map->youwin_first_ind = map->first_path_ind + 33;
	map->youwin_last_ind = map->first_path_ind + 72;
	map->exit_index = map->first_path_ind + 22;
	map->exit_first_ind = map->first_path_ind + 22;
	map->exit_last_ind = map->first_path_ind + 32;
	map->tree_index = map->first_path_ind + 7;
	map->skeleton_index = map->first_path_ind + 8;
	map->tombstone_index = map->first_path_ind + 9;
	map->deadbush_index = map->first_path_ind + 10;
	map->left_arrow_index = map->first_path_ind + 11;
	map->right_arrow_index = map->first_path_ind + 12;
	map->blue_portal_index = map->first_path_ind + 73;
	map->orange_portal_index = map->first_path_ind + 74;
	map->portal_gun_index = map->first_path_ind + 75;
}

void	init_sprites(t_map *map)
{
	map->sprite = NULL;
	map->sprite_tmp = NULL;
	map->sprite_distance = NULL;
	map->sprite_order = NULL;
	map->sprite_cnt = 0;
	map->coin_cnt = 0;
	map->you_win = 0;
	map->coin_fps = 0;
	map->coin_f_cnt = 0;
	map->coin_flag = 0;
	map->exit_fps = 0;
	map->exit_f_cnt = 0;
	map->exit_flag = 0;
	map->youwin_f_cnt = 0;
	map->youwin_fps = 0;
	map->youwin_flag = 0;
	map->fmm.exit_flag = 0;
	map->fmm.exit_cnt = 0;
	map->door_f_cnt = 0;
	map->door_f_cnt_flag = 0;
	map->door_ind_flag = 0;
	map->door_flag = 0;
	map->door_pos_x = 0;
	map->door_x = 0;
	map->door_y = 0;
}

static void	init_rotation(t_map *map)
{
	map->opp_dir_x = 0;
	map->opp_dir_y = 0;
	map->org_dir_x = 0;
	map->org_dir_y = 0;
	map->region = 0;
	map->rot_back = 0;
	map->rot_front = 0;
	map->rotate_to_back = 0;
	map->look_back_is_active = 0;
	map->mouse_rotate_right = 0;
	map->mouse_rotate_left = 0;
	map->prev_mouse_x = -1;
	map->rotate_left = 0;
	map->rotate_right = 0;
	map->look_back_key = 0;
	map->look_back_key_prev = 0;
}

void	init_flags(t_map *map)
{
	map->level = NULL;
	map->map = NULL;
	map->map_xy_cnt = 0;
	map->pos_x = 0;
	map->pos_y = 0;
	map->mouse_switch = 0;
	map->blue.active = 0;
	map->orange.active = 0;
	map->portal_active = 0;
	map->door_switch_key = 0;
	map->door_switch = 0;
	map->exit_is_open = 0;
	map->full_map = 0;
	map->move_front = 0;
	map->move_back = 0;
	map->move_left = 0;
	map->move_right = 0;
	map->angle = ANGLE;
	init_rotation(map);
}

void	init(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 6)
		map->fixed_files[i] = NULL;
	i = -1;
	while (++i < SCREENHEIGHT)
	{
		map->map_xs[i] = -1;
		map->map_ys[i] = -1;
	}
	init_sprites(map);
	init_sprite_indexes(map);
	init_flags(map);
	init_lookup_table(&(map->table));
}
