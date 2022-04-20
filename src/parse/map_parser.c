/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:06:06 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/19 20:45:00 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	map_line_looper(t_map *map, int i, t_map_p *p)
{
	int				j;

	p->filled = 0;
	p->m_index = 0;
	j = -1;
	while (map->map[i][++j])
	{
		if (map->map[i][j] == '1' || map->map[i][j] == '0'
			|| map->map[i][j] == 'N' || map->map[i][j] == 'S'
			|| map->map[i][j] == 'W' || map->map[i][j] == 'E'
			|| map->map[i][j] == ' ' || map->map[i][j] == 'C'
			|| map->map[i][j] == 'T' || map->map[i][j] == 'K'
			|| map->map[i][j] == 'V' || map->map[i][j] == 'B'
			|| map->map[i][j] == 'L' || map->map[i][j] == 'R'
			|| map->map[i][j] == 'G' || map->map[i][j] == 'D')
			is_map_char_allowed(map, p, i, j);
		else
		{
			map->parse_error_row = i;
			map->parse_error_col = j;
			error(14, map);
		}
	}
	return (p->filled);
}

void	copy_back_2_sprite_arr(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->sprite_cnt)
	{
		map->sprite[i].type = map->sprite_tmp[i].type;
		map->sprite[i].x = map->sprite_tmp[i].x;
		map->sprite[i].y = map->sprite_tmp[i].y;
		map->sprite[i].texture = map->sprite_tmp[i].texture;
	}
}

void	map_parser(t_map *map)
{
	t_map_p		p;
	int			i;

	i = N_ELEMENTS - 1;
	p.player_flag = 0;
	p.exit_flag = 0;
	allocation(map);
	while (map->map[++i])
		if (!map_line_looper(map, i, &p))
			error(12, map);
	if (!p.player_flag)
		error(11, map);
	map->sprite = (t_sprite *)malloc(sizeof(t_sprite) * map->sprite_cnt);
	map->sprite_order = (int *)malloc(sizeof(int) * map->sprite_cnt);
	map->sprite_distance = (double *)malloc(sizeof(double) * map->sprite_cnt);
	if (!map->sprite || !map->sprite_order || !map->sprite_distance)
		error(3, map);
	copy_back_2_sprite_arr(map);
	free(map->sprite_tmp);
	map_checker(map);
}
