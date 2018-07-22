#ifndef HELPER_H
# define HELPER_H

char	*ft_space(char *str);
int	ft_parenthes(char **str);
int	ft_first_expr(char **str);
int	ft_multiplicate(char **str);
int	eval_expr(char *str);
int	ft_div_and_else(int nb, int nb1, char op);
void	ft_putnbr(int nbr);
int	ft_strlen(char *str);
void	ft_putchar(char c);

#endif 
