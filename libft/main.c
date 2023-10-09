/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:31:48 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/09 10:36:27 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    const char c;
    char *str1;
    const char str[] = "this is just a test";


    str1 = strchr(str, c);
    printf("this is just a test %s\n", str1);
    return 0;
}