/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:36:43 by absalah           #+#    #+#             */
/*   Updated: 2024/04/03 00:59:03 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **list_a)
{
	t_stack	*last_node;
	t_stack	*first_node;

	if (!(*list_a))
		return ;
	first_node = *list_a;
	last_node = ft_lstlast(*list_a);
	*list_a = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
}

void	do_rotate(t_stack **list_a, t_stack **list_b, char c, int is_checker)
{
	if (c == 'a')
	{
		rotate(list_a);
		if (!is_checker)
			write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		rotate(list_b);
		if (!is_checker)
			write(1, "rb\n", 3);
	}
	else if (c == 'c')
	{
		rotate(list_a);
		rotate(list_b);
		if (!is_checker)
			write(1, "rr\n", 3);
	}
}
