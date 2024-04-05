/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:36:46 by absalah           #+#    #+#             */
/*   Updated: 2024/04/03 00:59:13 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack **list_b)
{
	t_stack	*last;
	t_stack	*before_last;

	last = *list_b;
	before_last = *list_b;
	if (last == NULL || last->next == NULL)
		return ;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	last->next = *list_b;
	*list_b = last;
	before_last->next = NULL;
}

void	do_reverse_rotate(t_stack **list_a, t_stack **list_b
		, char c, int is_checker)
{
	if (c == 'a')
	{
		reverse_rotate(list_a);
		if (!is_checker)
			write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		reverse_rotate(list_b);
		if (!is_checker)
			write(1, "rrb\n", 4);
	}
	else if (c == 'c')
	{
		reverse_rotate(list_a);
		reverse_rotate(list_b);
		if (!is_checker)
			write(1, "rrr\n", 4);
	}
}
