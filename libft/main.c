/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:31:48 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/08 13:54:52 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int main(void)
{
    char *c;
    int number;

    c = "1245";

    number = ft_atoi(c);
    printf("this is th eresult = %d", number);
    return 0;
}