/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:57:54 by mbenhass          #+#    #+#             */
/*   Updated: 2018/07/25 23:39:14 by ple-tors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fonctions.h"

void	free_int_array(int **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
}

char	**ft_test_map(int argc, char **argv, int i)
{
	char **tab;

	if (i != argc && i != 1 && i != 0)
		ft_putchar('\n');
	if (i != 0)
	{
		if ((tab = ft_read_file(argv[i])) == 0)
		{
			ft_putstr("map error\n");
			return (NULL);
		}
	}
	else if ((tab = ft_read_stdin()) == 0)
	{
		ft_putstr("map error\n");
		return (NULL);
	}
	if (ft_is_map_valid(tab) == 0)
	{
		ft_putstr("map error\n");
		return (NULL);
	}
	return (tab);
}

int		main(int argc, char **argv)
{
	int		i;
	int		size[2];
	char	**tab;
	int		**plat;
	t_carre carre;

	i = 0;
	if (argc == 1)
		i--;
	while (++i < argc)
	{
		if ((tab = ft_test_map(argc, argv, i)) == NULL)
			continue ;
		ft_get_size(size, tab);
		if ((plat = ft_create_tab(tab, size[0], size[1])) != 0)
		{
			carre = ft_find_biggest_square(plat, size[0], size[1]);
			if (carre.size == -1)
			{
				ft_putstr("map error\n");
				continue;
			}
			ft_disp_sol(carre, tab);
			free_int_array(plat, size[0]);
		}
	}
	return (0);
}
