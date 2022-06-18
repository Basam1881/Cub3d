/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm_rays_sender.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:10:42 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 21:51:44 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	go_to_next_pos(t_map *map)
{
	if (map->side_dist_x < map->side_dist_y)
	{
		map->side_dist_x += map->delta_dist_x;
		map->d_map_x += map->step_x;
		map->side = 0;
	}
	else
	{
		map->side_dist_y += map->delta_dist_y;
		map->d_map_y += map->step_y;
		map->side = 1;
	}
}

void	store_n_check_4_wall(t_map *map)
{
	if ((map->level[(int)map->d_map_y][(int)map->d_map_x] == 1
		&& !map->door_flag)
		|| map->level[(int)map->d_map_y][(int)map->d_map_x] == 20
		|| map->level[(int)map->d_map_y][(int)map->d_map_x] == 21
		|| (!map->door_flag
		&& (map->level[(int)map->d_map_y][(int)map->d_map_x] >= 4
		&& map->level[(int)map->d_map_y][(int)map->d_map_x] <= 11)))
	{
		map->map_xs[map->map_xy_cnt] = map->d_map_x;
		map->map_ys[map->map_xy_cnt] = map->d_map_y;
		map->map_xy_cnt++;
	}
	if (map->level[(int)map->d_map_y][(int)map->d_map_x] == 1
	|| map->level[(int)map->d_map_y][(int)map->d_map_x] == 20
	|| map->level[(int)map->d_map_y][(int)map->d_map_x] == 21)
		map->hit = 1;
	else if (map->level[(int)map->d_map_y][(int)map->d_map_x] >= 4
		&& map->level[(int)map->d_map_y][(int)map->d_map_x] <= 11)
		map->door_flag = 1;
}

void	fm_check_wall_hit(t_map *map)
{
	map->hit = 0;
	map->door_flag = 0;
	while (!map->hit)
	{
		go_to_next_pos(map);
		store_n_check_4_wall(map);
	}
}

void	fm_check_ray_direction(t_map *map)
{
	double	scale;

	scale = FOCUSED_MINIMAP_RAYS_NUM;
	if (map->ray_x < 0)
	{
		map->step_x = -scale;
		map->side_dist_x = (map->pos_x - map->d_map_x) * map->delta_dist_x;
	}
	else
	{
		map->step_x = scale;
		map->side_dist_x = (map->d_map_x + scale - map->pos_x)
			* map->delta_dist_x;
	}
	if (map->ray_y < 0)
	{
		map->step_y = -scale;
		map->side_dist_y = (map->pos_y - map->d_map_y) * map->delta_dist_y;
	}
	else
	{
		map->step_y = scale;
		map->side_dist_y = (map->d_map_y + scale - map->pos_y)
			* map->delta_dist_y;
	}
}

void	fm_init_ray(t_map *map)
{
	map->cam_x = 2 * map->fmm.x / (double)SCREENWIDTH - 1;
	map->ray_x = map->dir_x + map->plane_x * map->cam_x;
	map->ray_y = map->dir_y + map->plane_y * map->cam_x;
	map->d_map_x = map->pos_x;
	map->d_map_y = map->pos_y;
	if (map->ray_x == 0)
		map->delta_dist_x = 10000000000;
	else
		map->delta_dist_x = fabs(1 / map->ray_x);
	if (map->ray_y == 0)
		map->delta_dist_y = 10000000000;
	else
		map->delta_dist_y = fabs(1 / map->ray_y);
}
