/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimaps_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:05:10 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/15 21:40:40 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player(t_minimap *minimap)
{
	minimap->width_player = minimap->block_width;
	minimap->height_player = minimap->block_height;
	minimap->img_player = mlx_new_image(minimap->mlx, minimap->width_player - 1,
			minimap->height_player - 1);
	minimap->addr_player = mlx_get_data_addr(minimap->img_player,
			&minimap->bpp_player, &minimap->line_len_player,
			&minimap->endian_player);
	minimap->start_x = minimap->pos_x * minimap->block_width
		- minimap->block_width / 2 + 1
		+ (SCREENWIDTH / 2 - minimap->width / 2);
	minimap->start_y = minimap->pos_y * minimap->block_height
		- minimap->block_height / 2 + 1
		+ (SCREENHEIGHT / 2 - minimap->height / 2);
}

void	draw_player(t_minimap *minimap)
{
	int				i;
	int				j;
	int				color;
	char			*dst;	

	color = 0x00FF0000;
	j = -1;
	while (++j < minimap->height_player - 1)
	{
		i = -1;
		while (++i < minimap->width_player - 1)
		{
			dst = minimap->addr_player + (j * minimap->line_len_player
					+ i * (minimap->bpp_player / 8));
			*(unsigned int *)dst = color;
		}
	}
}

void	draw_fm_player(t_minimap *minimap)
{
	int			i;
	int			j;
	double		r;

	r = minimap->block_height / 4;
	i = -1;
	while (++i < minimap->block_height / 2)
	{
		j = -1;
		while (++j < minimap->block_height / 2)
			draw_minimap_pixel(minimap, minimap->p_pos_x - r
				+ i, minimap->p_pos_y - r + j, -2);
	}
}
