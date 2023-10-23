/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:09:57 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/23 13:43:51 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb, int *counter)
{
	long long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		counter++;
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, counter);
		ft_putchar((n % 10) + '0');
		counter++;
	}
	else
	{
		ft_putchar(n + '0');
		counter++;
	}
	return (0);
}
