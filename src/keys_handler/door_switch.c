/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_switch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:06:53 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 19:40:44 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/cub3d.h"

static void	is_fully_closed_or_opened(t_map *map)
{
	if (map->level[map->door_y][map->door_x] == 3)
	{
		map->door_index = 3;
		map->door_f_cnt_flag = 1;
		map->door_ind_flag = 1;
	}
	else if (map->level[map->door_y][map->door_x] == 11)
	{
		map->door_index = 11;
		map->door_f_cnt_flag = 1;
		map->door_ind_flag = -1;
	}
}

static void	is_closing_or_opening(t_map *map)
{
	if (map->door_f_cnt_flag == 1)
	{
		map->door_f_cnt++;
		map->door_f_cnt_flag = -1;
	}
	else if (map->door_f_cnt_flag == -1)
	{
		map->door_f_cnt--;
		map->door_f_cnt_flag = 1;
	}
	if (map->door_ind_flag == 1)
		map->door_ind_flag = -1;
	else if (map->door_ind_flag == -1)
		map->door_ind_flag = 1;
}

static void	check_door_status(t_map *map)
{
	if (!map->door_switch_key && map->door_switch == 1)
	{
		map->door_switch_key = 1;
		if (map->door_x && map->door_y && (!map->door_f_cnt
				|| (map->door_f_cnt && map->door_pos_x == map->door_x
					&& map->door_pos_y == map->door_y)))
		{
			if (map->level[map->door_y][map->door_x] == 3
				|| map->level[map->door_y][map->door_x] == 11)
				is_fully_closed_or_opened(map);
			else if (map->door_ind_flag == 1 || map->door_ind_flag == -1)
				is_closing_or_opening(map);
			map->door_pos_y = map->door_y;
			map->door_pos_x = map->door_x;
		}
	}
}

static void	run_door_sprites(t_map *map)
{
	int			fps;

	if (map->door_f_cnt_flag == 1
		&& map->door_f_cnt < DOORSPEED * DOOR_N_IMGS)
		map->door_f_cnt++;
	else if (map->door_f_cnt_flag == -1 && map->door_f_cnt > 0)
		map->door_f_cnt--;
	fps = DOORSPEED;
	while (fps < DOORSPEED * DOOR_N_IMGS)
	{
		if (map->door_f_cnt == fps && map->door_ind_flag == 1
			&& map->door_index < 11)
			map->door_index++;
		else if (map->door_f_cnt == fps && map->door_ind_flag == -1
			&& map->door_index > 3)
			map->door_index--;
		fps += DOORSPEED;
	}
	map->level[map->door_pos_y][map->door_pos_x] = map->door_index;
	if (!map->door_f_cnt || map->door_f_cnt == DOORSPEED * DOOR_N_IMGS)
	{
		map->door_ind_flag = 0;
		map->door_f_cnt = 0;
	}
}

void	switch_door_status(t_map *map)
{
	check_door_status(map);
	if (map->door_ind_flag)
		run_door_sprites(map);
}
