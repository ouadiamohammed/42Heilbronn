/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:26:05 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/15 19:27:20 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_str(char *string, long long int nb, int size)
{
	if (nb == 0)
		string[0] = '0';
	else if (nb < 0)
	{
		nb *= -1;
		string[0] = '-';
	}
	size--;
	while (size >= 0 && nb != 0)
	{
		string[size] = (nb % 10) + '0';
		nb = nb / 10;
		size--;
	}
}

static int	string_size(long long int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i ++;
	}
	if (nb != 0)
	{
		while (nb != 0)
		{
			nb = nb / 10;
			i++;
		}
	}
	else
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char			*string;
	long long int	nb;
	int				size;

	nb = n;
	size = string_size(nb);
	string = (char *)malloc(sizeof(char) * size + 1);
	if (!string)
		return (NULL);
	put_str(string, nb, size);
	string[size] = '\0';
	return (string);
}
