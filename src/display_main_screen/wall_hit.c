/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 07:36:47 by mmekky            #+#    #+#             */
/*   Updated: 2022/04/19 15:27:21 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_texture_is_door(t_map *map)
{
	if (map->level[map->map_y][map->map_x] == 11)
		return (map->door_first_ind);
	else if (map->level[map->map_y][map->map_x] == 10)
		return (map->door_first_ind + 1);
	else if (map->level[map->map_y][map->map_x] == 9)
		return (map->door_first_ind + 2);
	else if (map->level[map->map_y][map->map_x] == 8)
		return (map->door_first_ind + 3);
	else if (map->level[map->map_y][map->map_x] == 7)
		return (map->door_first_ind + 4);
	else if (map->level[map->map_y][map->map_x] == 6)
		return (map->door_first_ind + 5);
	else if (map->level[map->map_y][map->map_x] == 5)
		return (map->door_first_ind + 6);
	else if (map->level[map->map_y][map->map_x] == 4)
		return (map->door_first_ind + 7);
	else if (map->level[map->map_y][map->map_x] == 3)
		return (map->door_first_ind + 8);
	return (0);
}

int	check_texture_hit(t_map *map, int x)
{
	int	wall_hit;

	if (map->door_flag == -1)
	{
		wall_hit = check_texture_is_door(map);
		if (wall_hit)
			return (wall_hit);
	}
	if (map->side == 1)
	{
		if (map->ray_y <= 0)
			wall_hit = NORTH;
		else
			wall_hit = SOUTH;
	}
	else
	{
		if (map->ray_x <= 0)
			wall_hit = WEST;
		else
			wall_hit = EAST;
	}
	if (x == SCREENWIDTH / 2)
		map->portal_wall = wall_hit;
	return (wall_hit);
}

void	wall_hit_conditions(t_map *map, int **level)
{
	if (level[map->map_y][map->map_x] == 1
		|| level[map->map_y][map->map_x] == 20
		|| level[map->map_y][map->map_x] == 21)
		map->hit = 1;
	else if (map->n_doors && map->door_flag
		&& (level[map->map_y][map->map_x] >= 4
		&& level[map->map_y][map->map_x] <= 11))
		map->door_flag--;
	else if (map->n_doors && !map->door_flag
		&& (level[map->map_y][map->map_x] >= 4
		&& level[map->map_y][map->map_x] <= 11))
		map->door_flag = -1;
	else if (!map->n_doors && (level[map->map_y][map->map_x] >= 4
		&& level[map->map_y][map->map_x] <= 11))
		map->door_flag++;
	if (map->door_flag == -1 && (level[map->map_y][map->map_x] >= 4
		&& level[map->map_y][map->map_x] <= 11))
		map->hit = 1;
	else if (level[map->map_y][map->map_x] == 3
		&& map->wall_dist <= DIST_2_CLOSEST_DOOR
		&& map->wall_dist > 0.4)
	{
		map->door_x = map->map_x;
		map->door_y = map->map_y;
	}
}

void	increment_ray(t_map *map)
{
	if (map->side_dist_x < map->side_dist_y)
	{
		map->side_dist_x += map->delta_dist_x;
		map->map_x += map->step_x;
		map->side = 0;
	}
	else
	{
		map->side_dist_y += map->delta_dist_y;
		map->map_y += map->step_y;
		map->side = 1;
	}
}

void	check_wall_hit(t_map *map, int **level, int x)
{
	map->hit = 0;
	while (map->hit == 0)
	{
		increment_ray(map);
		wall_hit_conditions(map, level);
	}
	if (x == SCREENWIDTH / 2)
		set_portal_positions(map);
	if (map->side == 0)
		map->wall_dist = map->side_dist_x - map->delta_dist_x;
	else
		map->wall_dist = map->side_dist_y - map->delta_dist_y;
	if (map->wall_dist <= DIST_2_CLOSEST_DOOR
		&& map->wall_dist > 0.4 && map->door_flag == -1)
	{
		map->door_x = map->map_x;
		map->door_y = map->map_y;
	}
}
