/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_sol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 00:57:53 by mbenhass          #+#    #+#             */
/*   Updated: 2018/07/25 19:28:57 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fonctions.h"

void	ft_disp_sol(t_carre sol, char **file)
{
	int		i;
	int		j;
	int		lin;
	int		col;
	char	charstr[4];

	i = 0;
	lin = ft_get_line_number(file[0]);
	col = ft_strlen(file[1]);
	ft_get3last(charstr, file[0]);
	while (i < lin)
	{
		j = 0;
		while (j < col)
		{
			if (j >= sol.y && j <= (sol.y + sol.size) &&
				i >= sol.x && i <= (sol.x + sol.size) && (sol.size != -1))
				file[i + 1][j] = charstr[2];
			ft_putchar(file[i + 1][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
