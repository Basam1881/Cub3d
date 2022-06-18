/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:48:03 by mmekky            #+#    #+#             */
/*   Updated: 2022/04/01 18:45:39 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cub3d_mlx_pixel_put(t_map *map, int x, int y, __uint32_t color)
{
	char	*dst;

	if (x < SCREENWIDTH && y < SCREENHEIGHT && x >= 0 && y >= 0)
	{
		dst = map->addr + (y * map->line_len + x * (map->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

__uint32_t	choose_pixel_color(t_map *map, int ind)
{
	__uint32_t		color;
	unsigned int	j;

	color = 0;
	j = -1;
	while (++j < 4)
		map->rgba[j] = *(map->tex[ind].addr + (map->tex[ind].tex_y
					* map->tex[ind].line_len + map->tex[ind].tex_x
					* (map->tex[ind].bpp / 8)) + j);
	color = map->rgba[0]
		| map->rgba[1] << 8
		| map->rgba[2] << 16
		| map->rgba[3] << 24;
	return (color);
}

void	plot_vertical_line(t_map *map, int x, int ind)
{
	int	y;

	y = map->draw_start;
	while (y < map->draw_end)
	{
		map->tex[ind].tex_y = 1.0 * (y - map->draw_start)
			/ (map->draw_end - map->draw_start) * map->tex[ind].tex_height;
		map->color = choose_pixel_color(map, ind);
		if ((map->level[map->map_y][map->map_x] == 3
			|| map->level[map->map_y][map->map_x] == 11
			|| (map->level[map->map_y][map->map_x] >= 4
			&& map->level[map->map_y][map->map_x] <= 10))
			&& map->door_flag == -1)
		{
			if ((map->color & 0x00FFFFFF))
				cub3d_mlx_pixel_put(map, x, y, map->color);
			y++;
			continue ;
		}
		cub3d_mlx_pixel_put(map, x, y, map->color);
		if (map->level[map->map_y][map->map_x] == 20
			|| map->level[map->map_y][map->map_x] == 21)
			draw_portal(map, x, y);
		y++;
	}
}

void	plot_wall_lines(t_map *map, int x)
{
	double	wall_x;
	int		tex_index;

	tex_index = check_texture_hit(map, x);
	if (map->side == 0)
		wall_x = map->pos_y + map->wall_dist * map->ray_y;
	else
		wall_x = map->pos_x + map->wall_dist * map->ray_x;
	map->blue.wall_x = wall_x;
	map->orange.wall_x = wall_x;
	map->tex[tex_index].tex_x = round((wall_x - (int)wall_x)
			* (double)map->tex[tex_index].tex_width);
	plot_vertical_line(map, x, tex_index);
}
