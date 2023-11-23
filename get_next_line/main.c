/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:09:34 by mouadia           #+#    #+#             */
/*   Updated: 2023/11/23 23:10:37 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


#include <stdio.h>

int main(void)
{
    char *str;
    int file  = open("./text.txt", O_RDONLY);
    int file2  = open("./text1.txt", O_RDONLY);
    char *str1;
    
    str = get_next_line(file);
    str1 = get_next_line(file2);

    printf("%s\n%s\n", str, str1);

    str = get_next_line(file);
    str1 = get_next_line(file2);

    printf("%s\n%s\n", str, str1);
    
    str = get_next_line(file);
    str1 = get_next_line(file2);

    printf("%s\n%s\n", str, str1); 
    
    return(0);
}