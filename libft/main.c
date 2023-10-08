/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:31:48 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/08 14:46:06 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int main(void)
{
    char *c;
    int number1, number2;

    c = "1245";


    number1 = ft_atoi(c);
    number2 = ft_strlen(c);
    printf("this is th eresult = %d\n and th elen of it is %d\n", number1, number2);
    return 0;
}