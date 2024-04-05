/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_indexing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:37:08 by absalah           #+#    #+#             */
/*   Updated: 2024/04/05 01:42:22 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	parsing_stack(int argc, char **argv, t_stack **a)
{
	int		i;
	int		j;
	char	**splited_nums;

	i = 1;
	while (i < argc)
	{
		splited_nums = ft_split(argv[i], ' ');
		if (!splited_nums || !splited_nums[0])
			write_error();
		j = -1;
		while (splited_nums[++j])
		{
			if (!is_number(splited_nums[j])
				|| ft_atoi(splited_nums[j]) < -2147483648
				|| ft_atoi(splited_nums[j]) > 2147483647)
				(free_splited_nums(splited_nums), free_stack(a), write_error());
			if (not_duplicated(*a, ft_atoi(splited_nums[j])))
				(ft_lstadd_back(a, ft_lstnew(ft_atoi(splited_nums[j]), *a)));
			else if (!not_duplicated(*a, ft_atoi(splited_nums[j])))
				(free_splited_nums(splited_nums), free_stack(a), write_error());
		}
		free_splited_nums(splited_nums);
		i++;
	}
}

void	indexing_stack(t_stack **stack_a)
{
	t_stack	*curr;
	t_stack	*tmp;
	int		index;

	curr = *stack_a;
	while (curr)
	{
		index = 0;
		tmp = *stack_a;
		while (tmp)
		{
			if (tmp->number < curr->number)
				index++;
			tmp = tmp->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}
