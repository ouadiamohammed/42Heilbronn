/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:11:56 by mouadia           #+#    #+#             */
/*   Updated: 2023/11/14 21:30:06 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;
	int		i = 1;
	int		fd;

	fd = open("./test0.txt", O_RDONLY);
	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	while (i < 5)
	{
		line = get_next_line(fd);
		printf("line3-%d: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
