/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:30:55 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/08 14:07:25 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	result;

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
		}
		i++;
	}
	return (result * sign);
}
