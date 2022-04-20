/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:58:09 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 12:38:16 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_res_size(const char *str, char c)
{
	int	i;
	int	size;

	size = 0;
	i = 1;
	if (ft_strlen(str) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c)
			size++;
		i++;
	}
	if (str[i - 1] == c)
		size--;
	return (size + 1);
}

static	void	ft_fill_str(char **res, char const *string, char ch)
{
	int		start;
	int		end;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (string[i])
	{
		while (string[i] == ch)
			i++;
		if (string[i] == '\0')
			break ;
		start = i;
		while (string[i] != ch && string[i] != '\0')
			i++;
		end = i;
		res[j] = ft_substr(string, start, end - start);
		j++;
	}
	res[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		size;
	int		i;

	if (s == NULL)
	{
		res = (char **)malloc(sizeof(char *) * 1);
		res[0] = 0;
		return (res);
	}
	size = ft_res_size(s, c);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i <= size)
		res[i] = NULL;
	ft_fill_str(res, s, c);
	return (res);
}
