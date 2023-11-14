/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:11:56 by mouadia           #+#    #+#             */
/*   Updated: 2023/11/14 18:17:15 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_compat.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int		fd;
    char	*line;

	fd = open("tests/text.txt", O_RDONLY);

	while (1)
	{
		line = get_next_line(fd);
		if (line = 0)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}