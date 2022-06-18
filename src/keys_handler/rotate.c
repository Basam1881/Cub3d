/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:37:57 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/19 16:01:40 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/cub3d.h"

void	rotate_player(t_map *map)
{
	double	dir_x;
	double	plane_x;
	double	angle;

	dir_x = map->dir_x;
	plane_x = map->plane_x;
	angle = map->angle;
	if (map->rotate_left == 1 || map->mouse_rotate_left == 1
		|| map->rotate_right == 1 || map->mouse_rotate_right == 1
		|| map->rot_back == 1 || map->rot_front == 1)
	{
		if (map->rotate_left == 1 || map->mouse_rotate_left == 1
			|| map->rot_front == 1)
			angle = map->angle * -1.0;
		map->dir_x = map->dir_x * cos(angle) - map->dir_y * sin(angle);
		map->dir_y = dir_x * sin(angle) + map->dir_y * cos(angle);
		map->plane_x = map->plane_x * cos(angle) - map->plane_y * sin(angle);
		map->plane_y = plane_x * sin(angle) + map->plane_y * cos(angle);
	}
}
