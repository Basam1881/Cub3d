/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:08:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 18:33:41 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_ray_direction(t_map *map)
{
	if (map->ray_x < 0)
	{
		map->step_x = -1;
		map->side_dist_x = (map->pos_x - map->map_x) * map->delta_dist_x;
	}
	else
	{
		map->step_x = 1;
		map->side_dist_x = (map->map_x + 1.0 - map->pos_x) * map->delta_dist_x;
	}
	if (map->ray_y < 0)
	{
		map->step_y = -1;
		map->side_dist_y = (map->pos_y - map->map_y) * map->delta_dist_y;
	}
	else
	{
		map->step_y = 1;
		map->side_dist_y = (map->map_y + 1.0 - map->pos_y) * map->delta_dist_y;
	}
}

void	calculate_wall_height(t_map *map)
{
	map->line_height = (int) SCREENHEIGHT / map->wall_dist;
	map->draw_start = -(map->line_height / 2) + (SCREENHEIGHT / 2);
	map->draw_end = (map->line_height / 2) + (SCREENHEIGHT / 2);
}

void	init_ray(t_map *map, int x)
{
	map->cam_x = 2 * x / (double)SCREENWIDTH - 1;
	map->ray_x = map->dir_x + map->plane_x * map->cam_x;
	map->ray_y = map->dir_y + map->plane_y * map->cam_x;
	map->map_x = (int) map->pos_x;
	map->map_y = (int) map->pos_y;
	if (map->ray_x == 0)
		map->delta_dist_x = 10000000000;
	else
		map->delta_dist_x = fabs(1 / map->ray_x);
	if (map->ray_y == 0)
		map->delta_dist_y = 10000000000;
	else
		map->delta_dist_y = fabs(1 / map->ray_y);
}

void	create_doors(t_map *map, int **level, int x)
{
	int	i;

	i = 1;
	while (i <= map->n_doors)
	{
		map->door_flag = map->n_doors - i;
		init_ray(map, x);
		check_ray_direction(map);
		check_wall_hit(map, level, x);
		calculate_wall_height(map);
		plot_wall_lines(map, x);
		if (level[map->map_y][map->map_x] >= 7
			&& level[map->map_y][map->map_x] <= 11)
			map->zbuffer[x] = map->wall_dist;
		i++;
	}
}

void	create_map(t_map *map, int **level)
{
	int	x;

	draw_fc(map);
	x = -1;
	map->door_x = 0;
	map->door_y = 0;
	while (++x < SCREENWIDTH)
	{
		map->door_flag = 0;
		map->n_doors = 0;
		init_ray(map, x);
		check_ray_direction(map);
		check_wall_hit(map, level, x);
		calculate_wall_height(map);
		plot_wall_lines(map, x);
		map->zbuffer[x] = map->wall_dist;
		map->n_doors = map->door_flag;
		create_doors(map, level, x);
	}
}
