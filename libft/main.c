/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:31:48 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/09 16:45:14 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main ()
{
	char src[] = "Foo Bar hello Baz";
	char dest[4];
	size_t result;
 
	result = ft_strlcpy(dest, src, 10);

	if (result >= sizeof(dest))
		printf("copy failed\n");
	else{
		printf("copied string: %s\n", dest);
	}
	return 0;
}