/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:41:30 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/23 12:28:16 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{

    int len1 = 0;
    int len2 = 0;
    char c = 'c';


    printf("/*=============== format = "" ==========*/\n");
    
    printf("===========TEST============\n");
    len1 = printf("");
    printf("len1 = [%d]\n", len1);
    printf("=======================\n");
    len2 = ft_printf("");
    printf("len2 = [%d]\n", len2);

    /*=============== %c ====================*/
    
    printf("===========TEST============\n");
    len1 = printf("this is my char %c\n", c);
    printf("len1 = [%d]\n", len1);
    printf("=======================\n");
    len2 = printf("this is my char %c\n", c);
    printf("len2 = [%d]\n", len2);

    /*================ %s ===================*/
    
    
    return (0);
}