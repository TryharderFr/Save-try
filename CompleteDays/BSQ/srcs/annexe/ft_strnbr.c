/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 18:57:52 by mbenhass          #+#    #+#             */
/*   Updated: 2018/07/25 18:58:57 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fonctions.h"

void	ft_strnbr(char *str, int nb)
{
	if (nb == -2147483648)
	{
		ft_strnbr(str, -21474);
		ft_strnbr(str, 83648);
	}
	else
	{
		if (nb < 0)
		{
			ft_strcat1(str, '-');
			nb = -nb;
		}
		if (nb >= 10)
		{
			ft_strnbr(str, nb / 10);
			ft_strnbr(str, nb % 10);
		}
		else
		{
			ft_strcat1(str, '0' + nb);
		}
	}
}
