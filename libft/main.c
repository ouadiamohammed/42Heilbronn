/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:31:48 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/09 15:28:15 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main ()
{
	const char *largestring = "Foo Bar hello Baz";
	const char *smallstring = "Bar";
	char *ptr, *ptr1;
 
	ptr = strnstr(largestring, smallstring, 8);
	ptr1 = ft_strnstr(largestring, smallstring, 8);

	printf("%s\n%s\n", ptr, ptr1);
	return 0;
}