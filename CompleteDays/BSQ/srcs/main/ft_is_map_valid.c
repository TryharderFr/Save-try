/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-tors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:59:03 by ple-tors          #+#    #+#             */
/*   Updated: 2018/07/25 23:38:28 by ple-tors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fonctions.h"

int		char_is_valid(char **tab, int lin, int col)
{
	int		x;
	int		y;
	int		i;
	char	c[4];

	i = 1;
	x = 1;
	ft_get3last(c, tab[0]);
	while (x <= lin)
	{
		y = 0;
		while (y < col)
		{
			if ((tab[x][y] != c[0]) && (tab[x][y] != c[1]))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int		ft_get_line_number(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i])
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (tmp == NULL)
		return (0);
	i = 0;
	while (str[i + 3])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (ft_atoi(tmp));
}

int		ft_test_firstline(char **tab, int lin)
{
	char *nbstr;
	char end[4];

	nbstr = (char *)malloc(sizeof(char) * (ft_strlen(tab[0]) + 1));
	ft_strnbr(nbstr, lin);
	ft_get3last(end, tab[0]);
	ft_strcat(nbstr, end);
	if (ft_strcmp(nbstr, tab[0]) != 0)
		return (0);
	return (1);
}

int		ft_is_map_valid(char **tab)
{
	int i;
	int j;
	int col;
	int lin;

	i = 1;
	j = 0;
	while (tab[j])
		j++;
	j--;
	if ((lin = ft_get_line_number(tab[0])) == 0)
		return (0);
	if (ft_test_firstline(tab, lin) == 0)
		return (0);
	if (j != lin)
		return (0);
	if (tab[1][0] == '\0')
		return (0);
	col = ft_strlen(tab[1]);
	while (i <= lin)
	{
		if (ft_strlen(tab[i]) != col)
			return (0);
		i++;
	}
	return (char_is_valid(tab, lin, col));
}
