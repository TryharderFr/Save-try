#include <stdlib.h>
#include "helper.h"

int	ft_parenthes(char **str)
{
	int n;
	int oper;

	n = 0;
	oper = 1;
	if ((*str)[0] == '+' || (*str)[0] == '-')
	{
		if ((*str)[0] == '-')
			oper = -1;
		*str = *str + 1;
	}
	if ((*str)[0] == '(')
	{
		*str = *str + 1;
		n = ft_first_expr(str);
		if ((*str)[0] == ')')
			*str = *str + 1;
		return (oper * n);
	}
	while ('0' <= (*str)[0] && (*str)[0] <= '9')
	{
		n = (n * 10) + (*str)[0] - '0';
		*str = *str + 1;
	}
	return (oper * n);
}

int	ft_multiplicate(char **str)
{
	int nb;
	int nb1;
	char op;

	nb = ft_parenthes(str);
	while ((*str)[0] == '*' || (*str)[0] == '/' || (*str)[0] == '%')
	{
		op = (*str)[0];
		*str = *str + 1;
		nb1 = ft_parenthes(str);
		nb = ft_div_and_else(nb, nb1, op);
	}
	return (nb);
}

int	ft_first_expr(char **str)
{
	int nb;
	int nb1;
	char op;

	nb = ft_parenthes(str);
	while ((*str)[0] != '\0' && (*str)[0] != ')')
	{
		op = (*str)[0];
		*str = *str + 1;
		if (op == '+' || op == '-')
			nb1 = ft_multiplicate(str);
		else
			nb1 = ft_parenthes(str);
		nb = ft_div_and_else(nb, nb1, op);
	}
	return (nb);
}

char	*ft_space(char *str)
{
	int i;
	int p;
	char *strstr;

	i = 0;
	p = 0;
	strstr = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{		
		if (str[i] != ' ')
		{
			strstr[p] = str[i];
			p++;
		}
		i++;
	}
	strstr[p] = '\0';
	return (strstr);
}

int	eval_expr(char *str)
{
	str = ft_space(str);
	if (str[0] == '\0')
		return (0);
	return (ft_first_expr(&str));
}
