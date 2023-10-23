/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:34:55 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/23 13:00:47 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int i;
	int counter;
	va_list agrs;
	
	i = 0;
	counter = 0;
	va_start(agrs, format);
	if (format == NULL)
		return (-1);
	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			counter += checker(format, agrs, &i);
		}
		else
		{
			ft_putchar(*(format + i));
			counter++;
		}
		i++;       
	}
	va_end(agrs);
	return (counter);
}