/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:36:49 by absalah           #+#    #+#             */
/*   Updated: 2024/04/03 00:59:26 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap(t_stack **stack)
{
	if (!*stack || !((*stack)->next))
		return ;
	swap_int(&(*stack)->number, &((*stack)->next)->number);
	swap_int(&(*stack)->index, &((*stack)->next)->index);
}

void	do_swap(t_stack **list_a, t_stack **list_b, char c, int is_checker)
{
	if (c == 'a')
	{
		swap(list_a);
		if (!is_checker)
			write(1, "sa\n", 3);
	}
	else if (c == 'b')
	{
		swap(list_b);
		if (!is_checker)
			write(1, "sb\n", 3);
	}
	else if (c == 'c')
	{
		swap(list_a);
		swap(list_b);
		if (!is_checker)
			write(1, "ss\n", 3);
	}
}
