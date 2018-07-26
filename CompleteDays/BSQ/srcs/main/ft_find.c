/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:24:33 by mbenhass          #+#    #+#             */
/*   Updated: 2018/07/25 19:36:19 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fonctions.h"

int g_lin2 = 0;
int g_col2 = 0;

void		init(t_carre *carre)
{
	carre->x = 0;
	carre->y = 0;
	carre->size = -1;
}

int			is_empty(int **plat, int i, int j, int size)
{
	if ((i + size >= g_lin2) || (j + size >= g_col2))
		return (0);
	if (i == 0 && j == 0)
		return (plat[size][size] == 0);
	else if (i == 0)
		return ((plat[size][j + size] - plat[size][j - 1]) == 0);
	else if (j == 0)
		return ((plat[i + size][size] - plat[i - 1][size]) == 0);
	else
	{
		if ((plat[i + size][j + size] - plat[i - 1][j + size]
					- plat[i + size][j - 1] + plat[i - 1][j - 1]) == 0)
			return (1);
		return (0);
	}
}

t_carre		ft_find_biggest_square(int **plat, int lin, int col)
{
	t_carre	carre;
	int		i;
	int		j;

	i = 0;
	init(&carre);
	g_lin2 = lin;
	g_col2 = col;
	while (i < lin)
	{
		j = 0;
		while (j < col)
		{
			while (is_empty(plat, i, j, carre.size + 1))
			{
				carre.x = i;
				carre.y = j;
				carre.size += 1;
			}
			j++;
		}
		i++;
	}
	return (carre);
}
