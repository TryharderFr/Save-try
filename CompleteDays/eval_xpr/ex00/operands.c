#include "helper.h"


int	ft_div_and_else(int nb, int nb1, char op)
{
	if (op == '+')
		return (nb + nb1);
	else if (op == '-')
		return (nb - nb1);
	else if (op == '/')
	{
		if (nb != 0)
			return (nb / nb1);
		else
			return (1);
	}
	else if (op == '*')
		return (nb * nb1);
	else if (op == '%')
		return (nb % nb1);
	return (0);
}
