/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:05:27 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/19 17:26:08 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_all_sprites(t_map *map, char type, int index)
{
	int	i;

	i = 0;
	while (i < map->sprite_cnt)
	{
		if (map->sprite[map->sprite_order[i]].type == type)
			map->sprite[map->sprite_order[i]].texture = index;
		i++;
	}
}

void	moving_coin_sprites(t_map *map)
{
	if (map->coin_f_cnt == COINSPEED * COIN_N_IMGS)
	{
		map->coin_index = map->coin_first_ind;
		map->coin_f_cnt = 0;
	}
	map->coin_fps = COINSPEED;
	while (map->coin_fps < COINSPEED * COIN_N_IMGS)
	{
		if (map->coin_f_cnt == map->coin_fps
			&& map->coin_index < map->coin_last_ind)
		{
			map->coin_index++;
			map->coin_flag = 1;
		}
		map->coin_fps += COINSPEED;
	}
	if (map->coin_flag)
	{
		set_all_sprites(map, 'C', map->coin_index);
		map->coin_flag = 0;
	}
	map->coin_f_cnt++;
}

void	moving_exit_sprites(t_map *map)
{
	if (map->exit_is_open)
	{
		if (map->exit_f_cnt == EXITSPEED * EXIT_N_IMGS)
		{
			map->exit_index = map->exit_first_ind + 1;
			map->exit_f_cnt = 0;
		}
		map->exit_fps = EXITSPEED;
		while (map->exit_fps < EXITSPEED * EXIT_N_IMGS)
		{
			if (map->exit_f_cnt == map->exit_fps
				&& map->exit_index < map->exit_last_ind)
			{
				map->exit_index++;
				map->exit_flag = 1;
			}
			map->exit_fps += EXITSPEED;
		}
		if (map->exit_flag)
		{
			set_all_sprites(map, 'G', map->exit_index);
			map->exit_flag = 0;
		}
		map->exit_f_cnt++;
	}
}

void	init_youwin_sprites(t_map *map)
{
	if (!map->youwin_flag)
		map->youwin_flag = 1;
	if (map->youwin_f_cnt == YOUWINSPEED * YOUWIN_N_IMGS)
	{
		if (map->youwin_flag == 1)
			map->youwin_flag = -1;
		else if (map->youwin_flag == -1)
			map->youwin_flag = 1;
		map->youwin_f_cnt = 0;
	}
}

void	moving_youwin_sprites(t_map *map)
{
	init_youwin_sprites(map);
	map->youwin_fps = YOUWINSPEED;
	while (map->youwin_fps < YOUWINSPEED * YOUWIN_N_IMGS)
	{
		if (map->youwin_f_cnt == map->youwin_fps
			&& map->youwin_flag == 1
			&& map->youwin_index < map->youwin_last_ind)
			map->youwin_index++;
		else if (map->youwin_f_cnt == map->youwin_fps
			&& map->youwin_flag == -1
			&& map->youwin_index > map->youwin_first_ind)
			map->youwin_index--;
		map->youwin_fps += YOUWINSPEED;
	}
	if (map->youwin_f_cnt == YOUWINSPEED * YOUWIN_N_IMGS)
		map->youwin_f_cnt = 0;
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	map->youwin_f_cnt++;
}
