void	ft_putchar(char c);

void	ft_print_words_tables(char **tab)
{
	int i;
	int n;

	i = 0;
	while (tab[i])
	{
		n = 0;
		while (tab[i][n])
		{
			ft_putchar(tab[i][n]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
