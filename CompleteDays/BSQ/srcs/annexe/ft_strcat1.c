/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:54:02 by mbenhass          #+#    #+#             */
/*   Updated: 2018/07/23 19:54:14 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat1(char *dest, char src)
{
	int i;

	i = 0;
	while (dest[i++])
		;
	i--;
	dest[i] = src;
	dest[i + 1] = '\0';
	return (dest);
}