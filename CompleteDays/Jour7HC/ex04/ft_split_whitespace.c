/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-tors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:51:29 by ple-tors          #+#    #+#             */
/*   Updated: 2018/07/22 19:55:26 by ple-tors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		word_len(char *str, int i)
{
	int	cmp;

	cmp = 0;
	while (str[i] && str[i] != ' ')
	{
		cmp++;
		i++;
	}
	return (cmp);
}

int		word_count(char *str)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = 1;
	while (str[i])
	{
		if (str[i] == ' ')
			cmp++;
		i++;
	}
	return (cmp);
}

char	**ft_split_whitespace(char *str)
{
	char	**tab;
	char	*s;
	int		*pos;
	int		i;
	int		j;
	int		k;

//	i = *s;
		i = *pos;
	j = 0;
	tab = malloc((word_count(s) + 1) * sizeof(char *));
	while (s[i] && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
	{
		k = 0;
		tab[j] = malloc((word_len(s, i) + 1) * sizeof(char));
		while (s[i] && s[i] != ' ')
			tab[j][k++] = s[i++];
		while (s[i] == ' ')
			i++;
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = 0;
//	*s = i + 1;
		*pos = i + 1;
	return (tab);
}
void    ft_putchar(char c)
{
	write (1, &c, 1)
}

void    ft_print_words_tables(char **tab)
{
	int i;
	int n;

	i = 0;
	while (tab[i])
	{
		n = 0;
		while (tab[i][n])
		{
			ft_putchar(tab[i][n]);
			n++;
		}
		ft_putchar('\n');
		i++;
	}
}
int	main()
{
	printf("%d\n", ft_print_words_tables("awdhawd  wdijawd awdjadwaw awlkjawdj awdadw"));
	return (0);
}
