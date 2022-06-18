/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmekky <mmekky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:46:36 by mmekky            #+#    #+#             */
/*   Updated: 2022/04/20 16:27:32 by mmekky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/cub3d.h"

void	check_mouse_moving(t_map *map)
{
	int	x;
	int	y;

	map->mouse_reset--;
	mlx_mouse_get_pos(map->win, &x, &y);
	if (!(x >= 0 && x <= SCREENWIDTH && y >= 0 && y <= SCREENHEIGHT))
	{
		map->mouse_rotate_left = 0;
		map->mouse_rotate_right = 0;
	}
	if (x == map->prev_mouse_x && map->mouse_reset == 0)
	{
		if (!(x >= 0 && x <= 5) && !(x >= SCREENWIDTH - 5 && x <= SCREENWIDTH))
		{
			map->mouse_rotate_left = 0;
			map->mouse_rotate_right = 0;
		}
	}
}

int	mouse_rotate(int x, int y, t_map *map)
{
	int	dif_x;

	dif_x = 0;
	map->mouse_reset = 2;
	if (map->mouse_switch && x >= 0 && x <= SCREENWIDTH
		&& y >= 0 && y <= SCREENHEIGHT)
	{
		map->mouse_rotate_right = 0;
		map->mouse_rotate_left = 0;
		if ((x >= 0 && x <= 5) || (x >= SCREENWIDTH - 5 && x <= SCREENWIDTH))
		{
			if (x >= 0 && x <= 5)
				map->mouse_rotate_left = 1;
			else if (x >= SCREENWIDTH - 5 && x <= SCREENWIDTH)
				map->mouse_rotate_right = 1;
		}
		dif_x = x - map->prev_mouse_x;
		if (dif_x > 1)
			map->mouse_rotate_right = 1;
		else if (dif_x < -1)
			map->mouse_rotate_left = 1;
	}
	map->prev_mouse_x = x;
	return (0);
}
