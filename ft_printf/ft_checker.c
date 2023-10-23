/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:58:03 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/23 13:53:16 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(const char	*format, va_list	args, int	*i)
{
	int		res;
	char	*str;
	int		num;

	res = 0;
	res = 0;
	if (*(format + *i) == 'c')
	{
		ft_putchar(va_arg(args, int));
		res++;
	}
	else if (*(format + *i) == 's')
	{
		str = va_arg(args, char *);
		res += ft_putstr(str);
	}
	else if (*(format + *i) == 'd' || (*(format + *i) == 'i'))
	{
		num = va_arg(args, int);
		if (num == 0)
		{
			
		}
			
	}
	return (res);
}
