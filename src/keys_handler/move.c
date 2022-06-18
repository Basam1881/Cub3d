/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:05:22 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 17:59:47 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/cub3d.h"

void	init_lookup_table(t_lookup_table *table)
{
	int		i;
	double	dist_sq;
	double	x_sq;

	dist_sq = DIST_2_WALL * DIST_2_WALL;
	table->size = (DIST_2_WALL / STEP_SIZE) * 2;
	i = -1;
	while (++i < table->size)
	{
		table->c_x[i] = -DIST_2_WALL + (i * STEP_SIZE);
		x_sq = table->c_x[i] * table->c_x[i];
		table->c_y[i] = sqrt(dist_sq - x_sq);
		table->c_y_neg[i] = -table->c_y[i];
	}
}

int	is_walkable(t_map *map, double x, double y)
{
	int		pos_type;
	double	temp_x;
	double	temp_y;
	int		i;

	i = -1;
	while (++i < map->table.size)
	{
		temp_x = x + map->table.c_x[i];
		temp_y = y + map->table.c_y[i];
		pos_type = map->level[(int)temp_y][(int)temp_x];
		if (!(pos_type == 0 || pos_type == 3
				|| (map->portal_active && (pos_type == 20 || pos_type == 21))))
			return (0);
		temp_y = y + map->table.c_y_neg[i];
		pos_type = map->level[(int)temp_y][(int)temp_x];
		if (!(pos_type == 0 || pos_type == 3
				|| (map->portal_active && (pos_type == 20 || pos_type == 21))))
			return (0);
	}
	return (1);
}

void	move_direction(t_map *map, int flag)
{
	if (flag == 0)
	{
		map->new_x = map->pos_x + (map->dir_x * SPEED);
		map->new_y = map->pos_y + (map->dir_y * SPEED);
	}
	if (flag == 1)
	{
		map->new_x = map->pos_x - (map->dir_x * SPEED);
		map->new_y = map->pos_y - (map->dir_y * SPEED);
	}
	if (flag == 2)
	{
		map->new_x = map->pos_x - (map->perp_x * SPEED);
		map->new_y = map->pos_y - (map->perp_y * SPEED);
	}
	if (flag == 3)
	{
		map->new_x = map->pos_x + (map->perp_x * SPEED);
		map->new_y = map->pos_y + (map->perp_y * SPEED);
	}
	if (is_walkable(map, map->new_x, map->pos_y))
		map->pos_x = map->new_x;
	if (is_walkable(map, map->pos_x, map->new_y))
		map->pos_y = map->new_y;
}

void	move_player(t_map *map)
{
	map->perp_x = -map->dir_y;
	map->perp_y = map->dir_x;
	if (map->move_front == 1)
		move_direction(map, 0);
	if (map->move_back == 1)
		move_direction(map, 1);
	if (map->move_left == 1)
		move_direction(map, 2);
	if (map->move_right == 1)
		move_direction(map, 3);
}
