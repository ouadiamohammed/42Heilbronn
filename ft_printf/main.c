/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:41:30 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/23 21:12:26 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{

    int len1 = 0;
    int len2 = 0;
    char c = 'c';
    char *str = "hellow world";
    int number = 11452;
    int number1 = 1;
    int hex = 1540;
    int *ptr = &hex;

    
    printf("===========TEST 1============\n");
    len1 = printf("");
    printf("len1 = [%d]\n", len1);
    printf("=======================\n");
    len2 = ft_printf("");
    printf("len2 = [%d]\n", len2);
    
    printf("\n");
    
    printf("===========TEST 2============\n");
    len1 = printf("this is my char c : %c\n", c);
    printf("len1 = [%d]\n", len1);
    printf("=======================\n");
    len2 = ft_printf("this is my char c : %c\n", c);
    printf("len2 = [%d]\n", len2);

    printf("\n");
    
    printf("===========TEST 3============\n");
    len1 = printf("this is my str : %s\n", str);
    printf("len1 = [%d]\n", len1);
    printf("=======================\n");
    len2 = ft_printf("this is my str : %s\n", str);
    printf("len2 = [%d]\n", len2);

    printf("\n");

    printf("===========TEST 4============\n");
    len1 = printf("this is my number : %d\n", number);
    printf("len1 = [%d]\n", len1);
    printf("=======================\n");
    len2 = ft_printf("this is my number : %d\n", number);
    printf("len2 = [%d]\n", len2);

    printf("\n");
    
    printf("===========TEST 5============\n");
    len1 = printf("this is my unsigned number : %u\n", number1);
    printf("len1 = [%d]\n", len1);
    printf("=======================\n");
    len2 = ft_printf("this is my unsigned number : %u\n", number1);
    printf("len2 = [%d]\n", len2);

    printf("\n");
    
    printf("===========TEST 6============\n");
    len1 = printf("this is my hex : %x\n", hex);
    printf("len1 = [%d]\n", len1);
    printf("=======================\n");
    len2 = ft_printf("this is my hex : %x\n", hex);
    printf("len2 = [%d]\n", len2);

    printf("\n");
    
    printf("===========TEST 7============\n");
    len1 = printf("this is my HEX : %X\n", hex);
    printf("len1 = [%d]\n", len1);
    printf("=======================\n");
    len2 = ft_printf("this is my HEX : %X\n", hex);
    printf("len2 = [%d]\n", len2);

    printf("\n");
    
    printf("===========TEST 7============\n");
    len1 = printf("this is my percent : %%\n");
    printf("len1 = [%d]\n", len1);
    printf("=======================\n");
    len2 = ft_printf("this is my percent : %%\n");
    printf("len2 = [%d]\n", len2);

    printf("\n");
    
    printf("===========TEST 7============\n");
    len1 = printf("this is my percent : %p\n", (void *)ptr);
    printf("len1 = [%d]\n", len1);
    printf("=======================\n");
   
    
    return (0);
}