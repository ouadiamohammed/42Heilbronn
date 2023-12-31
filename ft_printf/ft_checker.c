/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:58:03 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/24 09:55:59 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checker(const char	*format, va_list	args, int *counter)
{
	char	*str;

	if (*format == 'c')
		ft_putchar(va_arg(args, int), counter);
	else if (*format == 's')
	{
		str = va_arg(args, char *);
		ft_putstr(str, counter);
	}
	else if (*format == 'd' || *format == 'i')
		ft_putnbr((va_arg(args, int)), counter);
	else if (*format == 'u')
		ft_putunsigned_int((va_arg(args, unsigned int)), counter);
	else if (*format == 'x')
		ft_put_x((va_arg(args, unsigned int)), counter);
	else if (*format == 'X')
		ft_put_hexup((va_arg(args, unsigned int)), counter);
	else if (*format == '%')
		ft_putchar('%', counter);
	else if (*format == 'p')
	{
		ft_putstr("0x", counter);
		ft_put_add((va_arg(args, unsigned long)), counter);
	}
}
