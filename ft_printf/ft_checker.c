/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:58:03 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/23 12:58:20 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int checker(const char  *format, va_list args, int *i)
{
    int res;
    char *str;

    res = 0;
    if(*(format + *i) == 'c')
        ft_putchar(va_arg(args, int)), res++;
    else if (*(format + *i) == 's')
        str = (va_arg(args, char *)), res += ft_putstr(str);
    return (res);
    
}
