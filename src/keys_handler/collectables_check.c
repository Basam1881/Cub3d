/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectables_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:12:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 17:59:02 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/cub3d.h"

void	remove_collectable(t_map *map, int i)
{
	int		x;
	int		y;
	int		texture;
	char	type;

	map->sprite_cnt--;
	x = map->sprite[map->sprite_order[i]].x;
	y = map->sprite[map->sprite_order[i]].y;
	type = map->sprite[map->sprite_order[i]].type;
	texture = map->sprite[map->sprite_order[i]].texture;
	map->sprite[map->sprite_order[i]].x = map->sprite[map->sprite_cnt].x;
	map->sprite[map->sprite_order[i]].y = map->sprite[map->sprite_cnt].y;
	map->sprite[map->sprite_order[i]].type = map->sprite[map->sprite_cnt].type;
	map->sprite[map->sprite_order[i]].texture
		= map->sprite[map->sprite_cnt].texture;
	map->sprite[map->sprite_cnt].x = x;
	map->sprite[map->sprite_cnt].y = y;
	map->sprite[map->sprite_cnt].type = type;
	map->sprite[map->sprite_cnt].texture = texture;
}

void	check_collectables(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->sprite_cnt)
	{
		if ((int)map->sprite[map->sprite_order[i]].x == (int)map->pos_x
			&& (int)map->sprite[map->sprite_order[i]].y == (int)map->pos_y
			&& map->sprite[map->sprite_order[i]].type == 'C')
		{
			remove_collectable(map, i);
			map->coin_cnt--;
			break ;
		}
		if ((int)map->sprite[map->sprite_order[i]].x == (int)map->pos_x
			&& (int)map->sprite[map->sprite_order[i]].y == (int)map->pos_y
			&& map->sprite[map->sprite_order[i]].type == 'G')
			map->you_win = 1;
		if (!map->coin_cnt)
		{
			map->level[(int)map->sprite[map->sprite_order[i]].y]
			[(int)map->sprite[map->sprite_order[i]].x] = 0;
			map->exit_is_open = 1;
		}
	}
}
