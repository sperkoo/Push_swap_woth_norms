/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:36:59 by absalah           #+#    #+#             */
/*   Updated: 2024/04/05 01:44:35 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

char	**free_arrays(char **ptr, int iter_w)
{
	int	i;

	i = 0;
	if (iter_w > 0)
	{
		while (iter_w > 0)
		{
			iter_w--;
			free(ptr[iter_w]);
		}
	}
	else
	{
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
	}
	free(ptr);
	ptr = NULL;
	return (ptr);
}

int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

void	ft_remplissage(char *curr_word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		curr_word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	curr_word[j] = '\0';
}

char	**ft_split_words(char const *s, char c, char **strs, int num_words)
{
	int	i;
	int	iter_words;
	int	word_len;

	i = 0;
	iter_words = 0;
	word_len = 0;
	while (iter_words < num_words)
	{
		word_len = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		strs[iter_words] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!strs[iter_words])
			return (free_arrays(strs, iter_words));
		ft_remplissage(strs[iter_words], s, i, word_len);
		iter_words++;
	}
	strs[iter_words] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**s2;
	int		num_words;

	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (0);
	s2 = ft_split_words(s, c, s2, num_words);
	return (s2);
}
