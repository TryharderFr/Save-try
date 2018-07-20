#include <stdlib.h>
#include <stdio.h>

int	word_len(char *str, int i)
{
	int	cmp;

	cmp = 0;
	while (str[i] && str[i] != ' ')
	{
		cmp++;
		i++;
	}
	return (cmp);
}

int	word_count(char *str)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = 1;
	while (str[i])
	{
		if (str[i] == ' ')
			cmp++;
		i++;
	}
	return (cmp);
}

char  **ft_split_whitespace(char *str)
{
	char	**tab;
	char *s;
	int *pos;
	int	i;
	int	j;
	int	k;

	i = *pos;
	j = 0;
	tab = malloc((word_count(s) + 1) * sizeof(char *));
	while (s[i] && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
	{
		k = 0;
		tab[j] = malloc((word_len(s, i) + 1) * sizeof(char));
		while (s[i] && s[i] != ' ')
			tab[j][k++] = s[i++];
		while (s[i] == ' ')
			i++;
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = '\0';
	*pos = i + 1;
	return (tab);
}
