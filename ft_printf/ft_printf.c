/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:34:55 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/23 16:18:50 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int counter;
	va_list agrs;
	
	counter = 0;
	va_start(agrs, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			if (*format == '\0')
				return (-1);
			ft_checker(++format, agrs, &counter);
		}
		else
		{
			ft_putchar(*format, &counter);
		}
		format++;      
	}
	va_end(agrs);
	return (counter);
}