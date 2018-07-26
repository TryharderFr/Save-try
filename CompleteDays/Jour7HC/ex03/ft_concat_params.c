/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-tors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:01:15 by ple-tors          #+#    #+#             */
/*   Updated: 2018/07/21 18:25:40 by ple-tors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*args;
	int		i;
	int		j;
	int		n;
	int		memory;

	memory = 0;
	i = 1;
	while (i < argc)
		memory += ft_strlen(argv[i++]) + 1;
	args = (char*)malloc(sizeof(char) * memory);
	if (args == NULL)
		return (NULL);
	i = 0;
	n = 0;
	while (i < argc)
		j = 0;
	while (argv[i][j])
	{
		args[n++] = argv[i][j++];
		if (i++ == argc - 1)
			args[n++] = '\0';
		else
			args[n++] = '\n';
	}
}
