/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmekky <mmekky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:35:13 by mmekky            #+#    #+#             */
/*   Updated: 2022/04/02 15:28:44 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/cub3d.h"

static void	keyhooks_press_helper(int key, t_map *map)
{
	if (key == MOUSE_SWITCH)
		map->mouse_switch_key = 1;
	else if (key == DISPLAY_FULL_MAP)
		map->full_map = 1;
	else if (key == LOOK_BACK)
		map->look_back_key = 1;
	else if (key == DOOR_SWITCH)
	{
		if (!map->door_switch_key)
		{
			if (!map->door_switch)
				map->door_switch = 1;
			else
				map->door_switch = 0;
		}
	}
	else if (key == ESC)
		ft_exit(map);
}

int	keyhooks_press(int key, t_map *map)
{
	if (key == KEY_LEFT)
		map->move_left = 1;
	else if (key == KEY_UP)
		map->move_front = 1;
	else if (key == KEY_RIGHT)
		map->move_right = 1;
	else if (key == KEY_DN)
		map->move_back = 1;
	else if (key == ROT_LEFT)
		map->rotate_left = 1;
	else if (key == ROT_RIGHT)
		map->rotate_right = 1;
	else
		keyhooks_press_helper(key, map);
	return (0);
}

static void	keyhooks_release_helper(int key, t_map *map)
{
	if (key == MOUSE_SWITCH)
	{
		map->mouse_switch_key = 0;
		if (!map->mouse_switch)
			map->mouse_switch = 1;
		else
			map->mouse_switch = 0;
	}
	else if (key == LOOK_BACK)
		map->look_back_key = 0;
	else if (key == DOOR_SWITCH)
		map->door_switch_key = 0;
}

int	keyhooks_release(int key, t_map *map)
{
	if (key == KEY_LEFT)
		map->move_left = 0;
	else if (key == KEY_UP)
		map->move_front = 0;
	else if (key == KEY_RIGHT)
		map->move_right = 0;
	else if (key == KEY_DN)
		map->move_back = 0;
	else if (key == ROT_LEFT)
		map->rotate_left = 0;
	else if (key == ROT_RIGHT)
		map->rotate_right = 0;
	else if (key == DISPLAY_FULL_MAP)
		map->full_map = 0;
	else
		keyhooks_release_helper(key, map);
	return (0);
}
