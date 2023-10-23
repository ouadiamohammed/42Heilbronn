/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_HEX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:29:40 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/23 20:30:13 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_HEX(unsigned int nb, int *counter)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (nb < 16)
		ft_putchar(str[nb], counter);
	if (nb >= 16)
	{
		ft_put_x(nb / 16, counter);
		ft_putchar(str[nb % 16], counter);
	}
}