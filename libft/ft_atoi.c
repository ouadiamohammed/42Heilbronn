/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:30:55 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/15 09:12:21 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(char *s)
{
	int					i;
	int					sign;
	unsigned long long	result;

	sign = -1;
	result = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (result < 0)
				result = (result * 10) - (s[i] - '0');
			else
				result = (s[i] - '0') * -1;
			if (s[i + 1] < 48 || s[i + 1] > 57)
				break ;
			if (result > LONG_MAX && sign > 0)
				return (-1);
			if (result > LONG_MAX && sign < 0)
				return (0);
		}
		i++;
	}
	return (result * sign);
}
