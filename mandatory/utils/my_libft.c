/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:36:57 by absalah           #+#    #+#             */
/*   Updated: 2024/04/03 01:00:14 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	write_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_splited_nums(char **splited_nums)
{
	int	i;

	i = 0;
	while (splited_nums[i])
	{
		free(splited_nums[i]);
		i++;
	}
	free(splited_nums);
}

int	is_number(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	sign_spaces(const char *str, int *i, int *sign)
{
	while (str[*i] == 32)
		(*i)++;
	if (str[*i] == '-')
	{
		*sign *= -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
}

long	ft_atoi(const char *str)
{
	long	result;
	int		i;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	sign_spaces(str, &i, &sign);
	if (str[i] < '0' || str[i] > '9')
		write_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > 2147483647)
			|| (sign == -1 && result > 2147483648))
			return (sign * result);
		i++;
	}
	return (sign * result);
}
