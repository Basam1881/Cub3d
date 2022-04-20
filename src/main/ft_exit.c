/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:04:41 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/20 11:20:38 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	putnum_fd(t_map *map, int fd)
{
	char	*tmp;

	tmp = ft_itoa(map->parse_error_row);
	ft_putstr_fd(tmp, fd);
	free(tmp);
}

static void	map_error_msgs(int n, t_map *map)
{
	ft_putstr_fd("Invalid Map: ", 2);
	if (n == 10)
		ft_putendl_fd("Map has more the one player", 2);
	else if (n == 11)
		ft_putendl_fd("Map has no player", 2);
	else if (n == 12)
		ft_putendl_fd("Map does not exist in the file!!!", 2);
	else if (n == 13)
		ft_putendl_fd("Map has lines in between", 2);
	else if (n == 14 || n == 15)
	{
		if (n == 14)
			ft_putstr_fd("Undefined character appers on [row: ", 2);
		else if (n == 15)
			ft_putstr_fd("An element in the map is exposed! (Hint: all characters \
including '0' except character '1' should not adjoin Spaces) [row: ", 2);
		putnum_fd(map, 2);
		ft_putstr_fd(", col: ", 2);
		putnum_fd(map, 2);
		ft_putendl_fd("]", 2);
	}
	else if (n == 16)
		ft_putendl_fd("Map size has exceed the max (rows: 100, cols: 100)", 2);
}

int	error(int n, t_map *map)
{
	ft_putendl_fd("Error", 2);
	if (n == 1)
		ft_putendl_fd("Invalid number of arguments", 2);
	else if (n == 2)
		ft_putendl_fd(strerror(errno), 2);
	else if (n == 3)
		ft_putendl_fd("Failed Malloc", 2);
	else if (n == 4)
		ft_putendl_fd("Invalid Elements", 2);
	else if (n == 5)
		ft_putendl_fd("Null path is passed for check!!", 2);
	else if (n == 6)
		ft_putendl_fd("Invalid Argument", 2);
	else if (n == 7)
		ft_putendl_fd("Invalid xpm path", 2);
	else if (n == 8)
		ft_putendl_fd("Invalid txt file path", 2);
	else if (n == 9)
		ft_putendl_fd("Invalid number of textures in filenames.txt", 2);
	else if ((n >= 10 && n <= 16))
		map_error_msgs(n, map);
	if (map)
		free_all(map);
	exit (n);
}

void	free_all(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 6)
		free(map->fixed_files[i]);
	if (map->sprite)
		free(map->sprite);
	if (map->sprite_distance)
		free(map->sprite_distance);
	if (map->sprite_order)
		free(map->sprite_order);
	if (map->level)
	{	
		i = 0;
		while (map->level[i])
			free(map->level[i++]);
		free(map->level);
	}
	if (map->map)
	{	
		i = 0;
		while (map->map[i])
			free(map->map[i++]);
		free(map->map);
	}
}

int	ft_exit(t_map *map)
{
	free_all(map);
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
}
