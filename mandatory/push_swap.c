/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:37:10 by absalah           #+#    #+#             */
/*   Updated: 2024/04/03 02:28:20 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (2 <= size && size <= 5)
	{
		if (size == 2)
			sort_2_numbers(a, b);
		else if (size == 3)
			sort_3_numbers(a, b);
		else if (size == 4)
			sort_4_numbers(a, b);
		else if (size == 5)
			sort_5_numbers(a, b);
	}
	if (size >= 6)
	{
		if (6 <= size && size <= 100)
			sort_large_numbers(a, b, 15);
		else
			sort_large_numbers(a, b, 30);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(0);
	parsing_stack(argc, argv, &a);
	indexing_stack(&a);
	if (!is_sorted(a))
		sort(&a, &b);
	free_stack(&a);
	return (0);
}
