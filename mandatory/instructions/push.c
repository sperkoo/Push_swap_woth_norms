/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:36:41 by absalah           #+#    #+#             */
/*   Updated: 2024/04/03 00:58:49 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_pointers(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!(*src))
		return ;
	tmp = (*src);
	*src = tmp->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	push(t_stack **src, t_stack **dest)
{
	if (*src == NULL)
		return ;
	swap_pointers(src, dest);
}

void	do_push(t_stack **src, t_stack **dest, char c, int is_checker)
{
	if (c == 'a')
	{
		swap_pointers(src, dest);
		if (!is_checker)
			write(1, "pa\n", 3);
	}
	else if (c == 'b')
	{
		swap_pointers(src, dest);
		if (!is_checker)
			write(1, "pb\n", 3);
	}
	else if (c == 'c')
	{
		swap_pointers(src, dest);
		swap_pointers(dest, src);
		if (!is_checker)
			write(1, "ss\n", 3);
	}
}
