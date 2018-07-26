/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 15:48:23 by mbenhass          #+#    #+#             */
/*   Updated: 2018/07/25 22:53:05 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_fonctions.h"

char	**ft_read_file(char *filename)
{
	int		fd;
	int		ret;
	char	*buf;
	char	ch[BUFF_SIZE + 1];
	int		flag;

	flag = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, ch, BUFF_SIZE)) > 0)
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
	if (close(fd) == -1)
		return (0);
	return (ft_split_newline(buf, 0, 0));
}
