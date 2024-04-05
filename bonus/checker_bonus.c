/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:36:26 by absalah           #+#    #+#             */
/*   Updated: 2024/04/05 02:16:32 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit (0);
	parsing_stack(argc, argv, &a);
	indexing_stack(&a);
	checking_sort(&a, &b);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

void	do_instruction(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		do_swap(a, b, 'a', 1);
	else if (!ft_strcmp(line, "sb\n"))
		do_swap(a, b, 'b', 1);
	else if (!ft_strcmp(line, "ss\n"))
		do_swap(a, b, 'c', 1);
	else if (!ft_strcmp(line, "pa\n"))
		do_push(b, a, 'a', 1);
	else if (!ft_strcmp(line, "pb\n"))
		do_push(a, b, 'b', 1);
	else if (!ft_strcmp(line, "ra\n"))
		do_rotate(a, b, 'a', 1);
	else if (!ft_strcmp(line, "rb\n"))
		do_rotate(a, b, 'b', 1);
	else if (!ft_strcmp(line, "rr\n"))
		do_rotate(a, b, 'c', 1);
	else if (!ft_strcmp(line, "rra\n"))
		do_reverse_rotate(a, b, 'a', 1);
	else if (!ft_strcmp(line, "rrb\n"))
		do_reverse_rotate(a, b, 'b', 1);
	else if (!ft_strcmp(line, "rrr\n"))
		do_reverse_rotate(a, b, 'c', 1);
	else
		write_error();
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index != i)
			return (0);
		i++;
		stack = stack->next;
	}
	return (1);
}

void	checking_sort(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		do_instruction(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (is_sorted(*a) && !*b)
	{
		write(1, "OK\n", 3);
		exit(0);
	}
	else
	{
		write(1, "KO\n", 3);
		exit(1);
	}
}
