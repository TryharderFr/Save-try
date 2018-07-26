/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-tors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:55:28 by ple-tors          #+#    #+#             */
/*   Updated: 2018/07/20 13:46:35 by ple-tors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_range(int min, int max)
{
	int *array;
	int i;

	if (min >= max)
		return (0);
	array = (int*)malloc(sizeof(int) * (max - min));
	if (array == NULL)
		return (array);
	i = 0;
	while (min < max)
	{
		array[i] = min;
		i++;
		min++;
	}
	return (array);
}
