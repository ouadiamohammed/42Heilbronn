/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:47:10 by mouadia           #+#    #+#             */
/*   Updated: 2023/11/23 23:15:42 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * read_and_save: this function reads the data from fd
 *                and save it in the var save.
 * @fd: file descriptor.
 * @save: variable where the data will be saved.
 * 
 * Return: void.
 */

char	*read_and_save(int fd, char *save)
{
	char	*readed;
	int		bytes;

	bytes = 1;
	readed = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!readed)
		return (NULL);
	while (!ft_strchr(save, '\n') && bytes != 0)
	{
		bytes = read(fd, readed, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(save);
			free(readed);
			return (NULL);
		}
		readed[bytes] = '\0';
		save = ft_strjoin(save, readed);
	}
	free(readed);
	return (save);
}

char	*save_line(char *save)
{
	int		i;
	char	*str;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*rest_save(char *save)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (save[++i])
		str[j++] = save[i];
	str[j] = '\0';
	free(save);
	return (str);
}

/**
 * get_next_line: reads a line from a file descriptor.
 * @fd: file descriptor.
 * 
 * Return: returns the line has been reading.
 */

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save[fd] = read_and_save(fd, save[fd]);
	if (!save[fd])
	{
		free(line);
		return (NULL);
	}
	line = save_line(save[fd]);
	save[fd] = rest_save(save[fd]);
	return (line);
}
