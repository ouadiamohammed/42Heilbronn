/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:11:56 by mouadia           #+#    #+#             */
/*   Updated: 2023/11/20 23:36:22 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char	*line;
	int		fd;

	fd = open("./test0.txt", O_RDONLY);
	
	line = get_next_line(fd);
	if (line != NULL)
		printf("%s\n", line);
		free(line);
	close(fd);
	return (0);
}
