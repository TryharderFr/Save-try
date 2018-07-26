#include <stdio.h>
#include <stdlib.h>

int		check_word(char c, char d)
{
	return (((c >= '0' && c <= '9') ||
		(c >= 'A' && c <= 'Z') ||
		(c >= 'a' && c <= 'z'))
		&& (d == ' ' || d == '\n' || d == '\t'));
}

int		count_words(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (check_word(str[i], str[i - 1]) || (str[i] != ' ' && str[i] != '\n' &&
					str[i] != '\t' && i == 0))
			count++;
		i++;
	}
	return (count);
}

int		n_string(int i, char *str)
{
	return (i > 0 && str[i - 1] != ' ' && str[i - 1] != '\n' &&
			str[i - 1] != '\t');
}

int		*size_of_words(char *str)
{
	int	j;
	int	i;
	int	word_count;
	int	*size;

	i = 0;
	word_count = count_words(str);
	size = malloc(word_count * sizeof(int));
	while (i <= word_count)
	{
		size[i] = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			size[j]++;
		else if (n_string(i, str))
			j++;
		i++;
	}
	return (size);
}

char	**ft_split_whitespaces(char *str)
{
	char	**w;
	int		i;
	int		j;
	int		k;
	int		*size;

	w = malloc((count_words(str) + 1) * sizeof(char*));
	size = size_of_words(str);
	k = 0;
	j = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			if (i == 0 || check_word(str[i], str[i - 1]))
				w[k] = malloc(size[k] * sizeof(char));
			w[k][j] = str[i];
			w[k][++j] = '\0';
		}
		else if (n_string(i, str) && ++k)
			j = 0;
	}
	w[count_words(str)] = 0;
	return (w);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_words_tables(char **tab)
{
	int	index;
	int	i;

	index = 0;
	while (tab[index])
	{
		i = 0;
		while (tab[index][i])
		{
			ft_putchar(tab[index][i]);
			++i;
		}
		ft_putchar('\n');
		index++;
	}
}
