/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:37:01 by absalah           #+#    #+#             */
/*   Updated: 2024/04/05 02:42:28 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_index(t_stack **a)
{
	int		max_index;
	t_stack	*p;

	p = *a;
	max_index = p->index;
	p = p->next;
	while (p)
	{
		if (max_index < p->index)
			max_index = p->index;
		p = p->next;
	}
	return (max_index);
}

int	min_index(t_stack **a)
{
	int		min_index;
	t_stack	*p;

	p = *a;
	min_index = p->index;
	p = p->next;
	while (p)
	{
		if (min_index > p->index)
			min_index = p->index;
		p = p->next;
	}
	return (min_index);
}

int	is_max_index_in_first_half(t_stack **b, int max_index, int size)
{
	t_stack	*p;
	int		index;
	int		found;

	index = 0;
	found = 0;
	p = *b;
	while (p && !found)
	{
		if (p->index == max_index)
			found = 1;
		else
			index++;
		p = p->next;
	}
	if (index < size / 2 + size % 2)
		return (1);
	else
		return (0);
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max_i;

	while (*b)
	{
		max_i = max_index(b);
		if ((*b)->index != max_i
			&& is_max_index_in_first_half(b, max_i, ft_lstsize(*b)))
			do_rotate(a, b, 'b', 0);
		else if ((*b)->index != max_i
			&& !is_max_index_in_first_half(b, max_i, ft_lstsize(*b)))
			do_reverse_rotate(a, b, 'b', 0);
		else if ((*b)->index == max_i)
			do_push(b, a, 'a', 0);
	}
}
