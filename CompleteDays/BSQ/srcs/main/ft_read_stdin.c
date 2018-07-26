/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:07:09 by mbenhass          #+#    #+#             */
/*   Updated: 2018/07/25 23:40:59 by ple-tors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fonctions.h"

char	*ft_realloc(char *src, char *prev, int bsize)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(prev) + bsize + 1));
	if (tmp == NULL)
		return (NULL);
	while (prev[i])
	{
		tmp[i] = prev[i];
		i++;
	}
	free(prev);
	while (src[j])
		tmp[i++] = src[j++];
	tmp[i] = '\0';
	return (tmp);
}

int		ft_check_printable(char *ch)
{
	int i;
	char *tmp;

	tmp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	i = 0;

	while (ch[i] != '\n')
	{
		tmp[i] = ch[i];
		if (ft_strlen(tmp) > 13 || (ft_strlen(tmp) < 4))
			return ();
	}
	while (ch[i])
	{
		if (ch[i] > 126)
			return (1);
		i++;
	}
	return (0);
}

char	**ft_read_stdin(void)
{
	char	*buf;
	char	ch[BUFF_SIZE + 1];
	int		ret;
	int		flag;

	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	flag = 0;
	while ((ret = read(0, ch, BUFF_SIZE)) > 0)
	{
		ch[ret] = '\0';
		buf = ft_realloc(ch, buf, ret);
		if (flag < 5)
		{
			flag++;
			if (ft_check_printable(ch))
				return (NULL);
		}
		ch[0] = '\0';
	}
	if (*buf == '\0')
		return (0);
	return (ft_split_newline(buf, 0, 0));
}
