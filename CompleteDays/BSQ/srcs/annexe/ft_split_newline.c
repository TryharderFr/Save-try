/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_newline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:03:03 by mbenhass          #+#    #+#             */
/*   Updated: 2018/07/25 19:13:00 by ple-tors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fonctions.h"

int		is_delimiter(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

int		count_words(char *str)
{
	int i;
	int j;
	int words;

	i = 0;
	j = 0;
	words = 0;
	while (str[i] != '\0')
	{
		while (is_delimiter(str[i]) == 0 && str[i])
		{
			i++;
			j = 1;
		}
		if (j == 1)
		{
			words++;
			j = 0;
		}
		if (str[i] != '\0')
			i++;
	}
	return (words);
}

int		wordlen(char *str, int index)
{
	int size;

	size = 0;
	while (is_delimiter(str[index]) == 0 && str[index])
	{
		size++;
		index++;
	}
	return (size + 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	**ft_split_newline(char *str, int i, int j)
{
	int			k;
	char		**tab;

	if ((tab = malloc(sizeof(char*) * (count_words(str) + 1))) == 0)
		return (NULL);
	while (str[i] != '\0')
	{
		if (is_delimiter(str[i]) == 1)
			i++;
		if (str[i] != '\0')
		{
			k = 0;
			if ((tab[j] = malloc(sizeof(char) *
				(wordlen(str, i) + 25))) == NULL)
				return (NULL);
			while (is_delimiter(str[i]) == 0 && str[i])
				tab[j][k++] = str[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = 0;
	return (tab);
}
