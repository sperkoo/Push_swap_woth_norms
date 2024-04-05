/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:37:15 by absalah           #+#    #+#             */
/*   Updated: 2024/04/05 02:23:07 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_numbers(t_stack **a, t_stack **b)
{
	if ((*a)->number > (*a)->next->number)
		do_swap(a, b, 'a', 0);
}

void	sort_3_numbers(t_stack **a, t_stack **b)
{
	int		max_i;

	max_i = max_index(a);
	if ((*a)->index == max_i)
		do_rotate(a, b, 'a', 0);
	else if ((*a)->next->index == max_i)
		do_reverse_rotate(a, b, 'a', 0);
	if ((*a)->number > (*a)->next->number)
		do_swap(a, b, 'a', 0);
}

void	sort_4_numbers(t_stack **a, t_stack **b)
{
	int		min_i;

	min_i = min_index(a);
	while ((*a)->index != min_i)
		do_rotate(a, b, 'a', 0);
	do_push(a, b, 'b', 0);
	sort_3_numbers(a, b);
	do_push(b, a, 'a', 0);
}

void	sort_5_numbers(t_stack **a, t_stack **b)
{
	int		min_i;

	min_i = min_index(a);
	while ((*a)->index != min_i)
		do_rotate(a, b, 'a', 0);
	do_push(a, b, 'b', 0);
	sort_4_numbers(a, b);
	do_push(b, a, 'a', 0);
}

void	sort_large_numbers(t_stack **a, t_stack **b, int chunk)
{
	int	i;

	i = 0;
	while ((*a) != NULL)
	{
		if (i >= 1 && (*a)->index < i)
		{
			do_push(a, b, 'b', 0);
			do_rotate(a, b, 'b', 0);
			i++;
		}
		else if ((*a)->index < i + chunk)
		{
			do_push(a, b, 'b', 0);
			i++;
		}
		else if ((*a)->index >= i + chunk)
			do_rotate(a, b, 'a', 0);
	}
	push_back_to_a(a, b);
}
