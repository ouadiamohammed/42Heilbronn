/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsined_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:42:12 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/23 16:44:03 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned_int(unsigned int nb, int *counter)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10, counter);
		ft_putnbr(nb % 10, counter);
	}
	else
		ft_putchar(nb + '0', counter);
}
