/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmekky <mmekky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 07:41:13 by mmekky            #+#    #+#             */
/*   Updated: 2022/04/02 15:14:15 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_filenames_length(t_map *map)
{
	int		fd;
	int		i;
	char	*tmp;

	i = 0;
	fd = open(FILENAMES_PATH, O_RDONLY);
	if (fd == -1)
		error(7, map);
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	close(fd);
	if (i != N_PATHS)
		return (0);
	return (1);
}

void	read_textures_from_txt(t_map *map, int i)
{
	char	*filename;

	filename = get_next_line(map->fd);
	if (filename[ft_strlen(filename) - 1] == '\n')
		filename[ft_strlen(filename) - 1] = 0;
	map->tex[i].img = mlx_xpm_file_to_image(map->mlx,
			filename, &map->tex[i].tex_width, &map->tex[i].tex_height);
	if (!map->tex[i].img)
	{
		free(filename);
		error(7, map);
	}
	free(filename);
}

void	init_textures(t_map *map)
{
	int		i;

	i = -1;
	if (!check_filenames_length(map))
		error(9, map);
	map->fd = open(FILENAMES_PATH, O_RDONLY);
	if (map->fd == -1)
		error(7, map);
	while (++i < N_ELEMENTS - 2 + SPRITES_NUMS + 2)
	{
		if (i <= N_ELEMENTS - 3)
		{
			map->tex[i].img = mlx_xpm_file_to_image(map->mlx,
					map->fixed_files[i], &map->tex[i].tex_width,
					&map->tex[i].tex_height);
		}
		if (i > N_ELEMENTS - 3)
			read_textures_from_txt(map, i);
		map->tex[i].addr = mlx_get_data_addr(map->tex[i].img,
				&map->tex[i].bpp, &map->tex[i].line_len, &map->tex[i].endian);
	}
	close(map->fd);
}	

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		error(1, NULL);
	init(&map);
	check_file(av[1], 0, &map);
	parser(map.fd, &map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, SCREENWIDTH, SCREENHEIGHT, "CubMB");
	init_textures(&map);
	mlx_hook(map.win, 2, 1L << 0, &keyhooks_press, &map);
	mlx_hook(map.win, 3, 1L << 1, &keyhooks_release, &map);
	mlx_hook(map.win, 6, 1L << 6, &mouse_rotate, &map);
	mlx_hook (map.win, 17, 0, ft_exit, &map);
	mlx_hook(map.win, 4, 1L << 2, &portal, &map);
	mlx_loop_hook(map.mlx, &redraw_frame, &map);
	mlx_loop(map.mlx);
	return (0);
}
