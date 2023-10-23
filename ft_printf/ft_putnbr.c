/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:09:57 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/23 11:58:45 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb, int *counter)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		*counter += 2;
		ft_putnbr(147483648, counter);
		return (0);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		*counter += 1;
		nb *= (-1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, counter);
		ft_putchar((nb % 10) + '0');
		*counter += 1;
	}
	else if (nb < 10)
	{
		ft_putchar(nb + '0');
		*counter += 1;
	}
	return (0);
}