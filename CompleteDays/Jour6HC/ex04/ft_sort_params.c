/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-tors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:43:00 by ple-tors          #+#    #+#             */
/*   Updated: 2018/07/18 19:08:44 by ple-tors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_argc = 0;

int		ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_strstrtri(char str[g_argc][100], int size)
{
	int		i;
	int		j;
	int		max;
	char	tmp[100];

	i = 1;
	max = 0;
	if (size > 2)
	{
		while (i < size)
		{
			if (ft_strcmp(str[i], str[max]) > 0)
				max = i;
			i++;
		}
		j = 0;
		while (str[max][j] != '\0')
			j++;
		ft_strcpy(tmp, str[max]);
		ft_strcpy(str[max], str[size - 1]);
		ft_strcpy(str[size - 1], tmp);
		ft_strstrtri(str, size - 1);
	}
	return ;
}

int		main(int argc, char **argv)
{
	char	temp[argc][100];
	int		i;
	int		j;

	i = 1;
	g_argc = argc;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_strcpy(temp[i], argv[i]);
			j++;
		}
		i++;
	}
	ft_strstrtri(temp, argc);
	i = 1;
	while (i < argc)
	{
		ft_putstr(temp[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
