/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:58:03 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/23 16:45:50 by mouadia          ###   ########.fr       */
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
		
}