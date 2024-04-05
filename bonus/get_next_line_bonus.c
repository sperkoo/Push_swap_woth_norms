/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:48:10 by absalah           #+#    #+#             */
/*   Updated: 2024/04/05 01:55:28 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*free_mandatory(char *mandatory)
{
	free(mandatory);
	mandatory = NULL;
	return (NULL);
}

static char	*fd_to_mandatory(int fd, char *mandatory)
{
	int		char_readed;
	char	*buffer;
	char	*prev_mandatory;

	buffer = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(mandatory, '\n'))
	{
		char_readed = read(fd, buffer, BUFFER_SIZE);
		if (char_readed <= 0)
			break ;
		else
		{
			buffer[char_readed] = '\0';
			prev_mandatory = mandatory;
			mandatory = ft_strjoin(mandatory, buffer);
			free(prev_mandatory);
		}
	}
	free(buffer);
	if (char_readed == -1 || mandatory[0] == '\0')
		return (free_mandatory(mandatory));
	return (mandatory);
}

static char	*mandatory_to_line(char **mandatory)
{
	char	*line;
	char	*prev_mandatory;
	int		i;

	i = 0;
	while ((*mandatory)[i] != '\n' && (*mandatory)[i] != '\0')
		i++;
	if ((*mandatory)[i] == '\n')
	{
		line = ft_substr(*mandatory, 0, i + 1);
		prev_mandatory = *mandatory;
		*mandatory = ft_strdup(*mandatory + i + 1);
		free(prev_mandatory);
	}
	else
	{
		line = ft_strdup(*mandatory);
		free(*mandatory);
		*mandatory = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*mandatory;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!mandatory)
		mandatory = ft_strdup("");
	mandatory = fd_to_mandatory(fd, mandatory);
	if (!mandatory)
		return (NULL);
	line = mandatory_to_line(&mandatory);
	return (line);
}
