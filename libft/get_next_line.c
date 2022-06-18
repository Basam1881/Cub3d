/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:25:31 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/18 18:02:56 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_me(char *strget, int fd, int *len)
{
	strget = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	*len = read(fd, strget, BUFFER_SIZE);
	if (*len == -1)
	{
		free (strget);
		return (NULL);
	}
	strget[*len] = 0;
	return (strget);
}

static char	*free_me(char *str)
{
	free (str);
	str = NULL;
	return (str);
}

static char	*allocate_me_plz(char *buffer)
{
	buffer = (char *)malloc(sizeof(char));
	*buffer = 0;
	return (buffer);
}

static char	*return_strline(char *buffer, char **strline,
	int len, char **strget)
{
	char	*tmp;
	char	*n;

	free(*strget);
	n = ft_strchr(buffer, '\n');
	if (n)
	{
		*strline = ft_substr(buffer, 0, n - buffer + 1);
		tmp = ft_substr(buffer, n - buffer + 1, ft_strlen(n + 1));
		buffer = free_me(buffer);
		buffer = ft_strdup(tmp);
		tmp = free_me(tmp);
		return (buffer);
	}
	else
	{
		if (len < BUFFER_SIZE)
		{
			*strline = ft_strdup(buffer);
			buffer = free_me(buffer);
		}
		return (buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*strline;
	int			len;
	char		*strget;

	strline = NULL;
	if (fd < 0 || fd > 255 || BUFFER_SIZE < 0)
		return (NULL);
	while (!strline)
	{
		strget = read_me(strget, fd, &len);
		if (!buffer)
			buffer = allocate_me_plz(buffer);
		if (!strget)
			return (NULL);
		if (!*strget && !*buffer)
		{
			buffer = free_me(buffer);
			strget = free_me(strget);
			break ;
		}
		buffer = ft_strjoin(buffer, strget);
		buffer = return_strline(buffer, &strline, len, &strget);
	}
	return (strline);
}
