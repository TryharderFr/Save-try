/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 15:59:41 by mbenhass          #+#    #+#             */
/*   Updated: 2018/07/25 22:48:49 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FONCTIONS_H
# define FT_FONCTIONS_H
# include <unistd.h>
# define BUFF_SIZE 4096
# include <stdlib.h>

typedef struct		s_carre
{
	int		x;
	int		y;
	int		size;
}					t_carre;
char				**ft_split_newline(char *str, int i, int j);
char				**ft_split_with_newline(char *str);
void				ft_print_words_tables(char **tab);
int					**ft_create_tab(char **tab, int lin, int col);
int					ft_atoi(char *str);
int					ft_strlen(char *str);
int					ft_putchar(char c);
void				ft_putstr(char *str);
char				*ft_strcat1(char *str, char c);
char				*ft_strcat(char *str, char *c);
char				*ft_get3last(char *str, char *file);
char				**ft_read_file(char *filename);
char				**ft_read_stdin(void);
int					*ft_get_size(int *size, char **file);
void				ft_disp_sol(t_carre sol, char **file);
t_carre				ft_find_biggest_square(int **plat, int lin, int col);
int					ft_is_map_valid(char **tab);
int					ft_get_line_number(char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_realloc(char *src, char *prev, int bsize);
int					ft_strcmp(char *s1, char *s2);
void				ft_strnbr(char *str, int nb);
int					ft_check_printable(char *ch);
#endif
