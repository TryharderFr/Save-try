/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:01:08 by mbenhass          #+#    #+#             */
/*   Updated: 2018/07/07 17:59:20 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_calcint(char *str, int res, int i)
{
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

int		ft_atoi(char *str)
{
	int i;
	int res;
	int sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[0] == '\0')
		return (0);
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v'))
		i++;
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	return (sign * ft_calcint(str, res, i));
}
