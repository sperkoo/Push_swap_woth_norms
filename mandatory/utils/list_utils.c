/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:36:52 by absalah           #+#    #+#             */
/*   Updated: 2024/04/03 01:55:21 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	ft_lstsize(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*tmp;

	if (!lst || !new_node)
		return ;
	if (*lst)
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new_node;
	}
	else
		*lst = new_node;
}

t_stack	*ft_lstnew(int content, t_stack *next)
{
	t_stack	*new_list;

	(void)next;
	new_list = malloc(sizeof(t_stack));
	if (!new_list)
		return (NULL);
	new_list->number = content;
	new_list->next = NULL;
	return (new_list);
}
