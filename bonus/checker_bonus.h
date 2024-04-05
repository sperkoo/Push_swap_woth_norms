/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:36:29 by absalah           #+#    #+#             */
/*   Updated: 2024/04/05 02:23:52 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line_bonus.h"

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	checking_sort(t_stack **a, t_stack **b);
void	do_instruction(t_stack **a, t_stack **b, char *line);
void	free_stack(t_stack **stack);
void	do_reverse_rotate(t_stack **list_a,
			t_stack **list_b, char c, int is_checker);
void	do_rotate(t_stack **list_a, t_stack **list_b, char c, int is_checker);
void	do_push(t_stack **src, t_stack **dest, char c, int is_checker);
void	do_swap(t_stack **list_a, t_stack **list_b, char c, int is_checker);
void	parsing_stack(int argc, char **argv, t_stack **a);
void	write_error(void);
void	indexing_stack(t_stack **stack_a);
t_stack	*ft_lstlast(t_stack *lst);
int		lst_size(t_stack **list);
void	free_stack(t_stack **stack);
char	**ft_split(char const *s, char c);
int		is_number(char *nbr);
int		not_duplicated(t_stack *a, int num);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content, t_stack *next);
long	ft_atoi(const char *c);
void	free_splited_nums(char **splited_nums);

#endif