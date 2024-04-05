/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:37:13 by absalah           #+#    #+#             */
/*   Updated: 2024/04/05 02:34:29 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	parsing_stack(int argc, char **argv, t_stack **a);
void	indexing_stack(t_stack **stack_a);
void	free_splited_nums(char **splited_nums);
void	do_reverse_rotate(t_stack **list_a,
			t_stack **list_b, char c, int is_checker);
void	do_rotate(t_stack **list_a, t_stack **list_b, char c, int is_checker);
void	do_push(t_stack **src, t_stack **dest, char c, int is_checker);
void	do_swap(t_stack **list_a, t_stack **list_b, char c, int is_checker);
void	write_error(void);
void	sort_3_numbers(t_stack **a, t_stack **b);
void	sort_2_numbers(t_stack **a, t_stack **b);
void	sort_4_numbers(t_stack **a, t_stack **b);
void	sort_5_numbers(t_stack **a, t_stack **b);
void	indexing_stack(t_stack **stack_a);
void	push_back_to_a(t_stack **a, t_stack **b);
void	sort_large_numbers(t_stack **a, t_stack **b, int chunk);
void	sort(t_stack **a, t_stack **b);
int		max_index(t_stack **a);
int		min_index(t_stack **a);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
char	**ft_split(char const *s, char c);
int		is_number(char *nbr);
int		not_duplicated(t_stack *a, int num);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content, t_stack *next);
long	ft_atoi(const char *c);
int		ft_lstsize(t_stack *stack);
t_stack	*ft_lstlast(t_stack *lst);

#endif
