/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_char_allowed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:14:45 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/19 22:42:31 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	is_east_or_west(t_map *map, char c)
{
	if (c == 'E')
	{
		map->dir_x = 1;
		map->dir_y = 0;
		map->plane_x = 0.0;
		map->plane_y = 0.66;
	}
	else if (c == 'W')
	{
		map->dir_x = -1;
		map->dir_y = 0;
		map->plane_x = 0.0;
		map->plane_y = -0.66;
	}
}

static void	is_north_or_south(t_map *map, char c)
{
	if (c == 'N')
	{
		map->dir_x = 0;
		map->dir_y = -1;
		map->plane_x = 0.66;
		map->plane_y = 0.0;
	}
	else if (c == 'S')
	{
		map->dir_x = 0;
		map->dir_y = 1;
		map->plane_x = -0.66;
		map->plane_y = 0.0;
	}
}

void	store_sprite_texture(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'C')
		map->sprite_tmp[map->sprite_cnt].texture = map->coin_index;
	else if (map->map[i][j] == 'T')
		map->sprite_tmp[map->sprite_cnt].texture = map->tree_index;
	else if (map->map[i][j] == 'K')
		map->sprite_tmp[map->sprite_cnt].texture = map->skeleton_index;
	else if (map->map[i][j] == 'V')
		map->sprite_tmp[map->sprite_cnt].texture = map->tombstone_index;
	else if (map->map[i][j] == 'B')
		map->sprite_tmp[map->sprite_cnt].texture = map->deadbush_index;
	else if (map->map[i][j] == 'L')
		map->sprite_tmp[map->sprite_cnt].texture = map->left_arrow_index;
	else if (map->map[i][j] == 'R')
		map->sprite_tmp[map->sprite_cnt].texture = map->right_arrow_index;
	else if (map->map[i][j] == 'G')
		map->sprite_tmp[map->sprite_cnt].texture = map->exit_first_ind;
}

void	store_sprites(t_map *map, t_map_p *p, int i, int j)
{
	map->sprite_tmp[map->sprite_cnt].type = map->map[i][j];
	map->sprite_tmp[map->sprite_cnt].x = p->m_index + 0.5;
	map->sprite_tmp[map->sprite_cnt].y = i - N_ELEMENTS + 0.5;
	if (map->map[i][j] == 'C')
		map->coin_cnt++;
	else if (map->map[i][j] == 'G')
		p->exit_flag = 1;
	store_sprite_texture(map, i, j);
	map->sprite_cnt++;
	if (map->map[i][j] == 'C' || map->map[i][j] == 'B')
		map->level[i - N_ELEMENTS][p->m_index++] = 0;
	else
		map->level[i - N_ELEMENTS][p->m_index++] = 2;
}

void	is_map_char_allowed(t_map *map, t_map_p *p, int i, int j)
{
	p->filled = 1;
	if (p->player_flag && (map->map[i][j] == 'N' || map->map[i][j] == 'S'
		|| map->map[i][j] == 'E' || map->map[i][j] == 'W'))
		error(10, map);
	if (map->map[i][j] == '1')
		map->level[i - N_ELEMENTS][p->m_index++] = 1;
	else if (map->map[i][j] == '0')
		map->level[i - N_ELEMENTS][p->m_index++] = 0;
	else if (map->map[i][j] == ' ')
		map->level[i - N_ELEMENTS][p->m_index++] = -1;
	else if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
		|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
	{
		p->player_flag = 1;
		map->pos_x = p->m_index + 0.5;
		map->pos_y = i - N_ELEMENTS + 0.5;
		is_north_or_south(map, map->map[i][j]);
		is_east_or_west(map, map->map[i][j]);
		map->level[i - N_ELEMENTS][p->m_index++] = 0;
	}
	else if (map->map[i][j] == 'D')
		map->level[i - N_ELEMENTS][p->m_index++] = 11;
	else
		store_sprites(map, p, i, j);
}
