/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_plat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 03:00:45 by mbenhass          #+#    #+#             */
/*   Updated: 2018/07/25 19:24:38 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fonctions.h"

int g_lin = 0;
int g_col = 0;

int		**ft_tab_plus_1(int **tab, int x, int y)
{
	int i;
	int j;

	i = x;
	while (i < g_lin)
	{
		j = y;
		while (j < g_col)
			tab[i][j++]++;
		i++;
	}
	return (tab);
}

char	*ft_get3last(char *dest, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	i -= 3;
	while (str[i])
		dest[j++] = str[i++];
	dest[j] = '\0';
	return (dest);
}

int		*ft_get_size(int *size, char **file)
{
	size[0] = ft_get_line_number(file[0]);
	size[1] = ft_strlen(file[1]);
	return (size);
}

int		**ft_create_tab(char **file, int lin, int col)
{
	int		i;
	int		j;
	char	charstr[4];
	int		**plat;

	i = -1;
	g_lin = lin;
	g_col = col;
	ft_get3last(charstr, file[0]);
	if ((plat = (int **)malloc(sizeof(int *) * g_lin)) == NULL)
		return (0);
	while (i < g_lin)
		plat[i++] = (int *)malloc(sizeof(int) * g_col);
	i = 0;
	while (i < g_lin)
	{
		j = -1;
		while (++j < g_col)
		{
			if (file[i + 1][j] == charstr[1])
				ft_tab_plus_1(plat, i, j);
		}
		i++;
	}
	return (plat);
}
