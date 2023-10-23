/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:26:33 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/23 13:01:05 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int i;
	int res;
	char *null;

	i = 0;
	res = 0;
	null = "(null)";
	if (str == NULL)
	{
		for (; *(null + i) != '\0'; i++)
		{
			ft_putchar(*(null + i));
			res++;
		}
	}
	else
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			ft_putchar(str[i]);
			res++;
		}
	}
	return (res);
}
