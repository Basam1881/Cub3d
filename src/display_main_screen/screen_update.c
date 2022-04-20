/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:34:00 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/19 18:22:31 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	rotation_n_movement_check(t_map *map)
{
	if (!map->full_map)
	{
		if ((map->rotate_right || map->rotate_left)
			&& (map->rot_back || map->rot_front))
		{
			map->rotate_right = 0;
			map->rotate_left = 0;
		}
		if (!map->look_back_is_active || (map->look_back_is_active
				&& (map->rot_back || map->rot_front)))
			rotate_player(map);
		if (!map->look_back_key)
			move_player(map);
	}
	if (!map->full_map && (map->look_back_is_active
			|| (!map->rotate_right && !map->rotate_left)))
		look_back(map);
}

static void	main_screen_manager(t_map *map)
{
	map->img = mlx_new_image(map->mlx, SCREENWIDTH, SCREENHEIGHT);
	map->addr = mlx_get_data_addr(map->img, &map->bpp,
			&map->line_len, &map->endian);
	check_portal(map);
	create_map(map, map->level);
	switch_door_status(map);
	create_sprites(map);
	if (!map->look_back_is_active && !map->full_map)
		draw_shooting_elements(map);
	check_collectables(map);
}

static void	display(t_map *map)
{
	t_minimap	minimap;
	t_minimap	focused_minimap;

	minimap.img = NULL;
	focused_minimap.img = NULL;
	minimap.img_player = NULL;
	if (map->full_map)
	{
		minimap = use_minimap(map);
		mlx_put_image_to_window(map->mlx, map->win, minimap.img, 0, 0);
		mlx_put_image_to_window(map->mlx, map->win, minimap.img_player,
			minimap.start_x, minimap.start_y);
		mlx_destroy_image(map->mlx, minimap.img);
		mlx_destroy_image(map->mlx, minimap.img_player);
	}
	else
	{
		focused_minimap = use_focused_minimap(map);
		mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
		mlx_put_image_to_window(map->mlx, map->win, focused_minimap.img,
			SCREENWIDTH - focused_minimap.width, 0);
		mlx_destroy_image(map->mlx, map->img);
		mlx_destroy_image(map->mlx, focused_minimap.img);
	}
}

int	redraw_frame(t_map *map)
{
	check_mouse_moving(map);
	if (!map->you_win)
	{
		map->img = NULL;
		rotation_n_movement_check(map);
		main_screen_manager(map);
		display(map);
		moving_coin_sprites(map);
		moving_exit_sprites(map);
		if (map->you_win)
			mlx_clear_window(map->mlx, map->win);
	}
	else
		display_youwin(map);
	return (0);
}
