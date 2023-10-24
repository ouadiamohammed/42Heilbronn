/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:35:13 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/24 09:40:04 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_add(unsigned long nb, int *counter)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(str[nb], counter);
	if (nb >= 16)
	{
		ft_put_add(nb / 16, counter);
		ft_putchar(str[nb % 16], counter);
	}
}
