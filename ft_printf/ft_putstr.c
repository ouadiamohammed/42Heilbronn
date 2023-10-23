/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:26:33 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/23 16:29:20 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *counter)
{
	if (!str)
	{
		ft_putstr("(null)", counter);
		return ;
	}
	while (*str)
	{
		ft_putchar(*str, counter);
		str++;
	}
}
