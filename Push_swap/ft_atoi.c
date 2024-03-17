/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:59:49 by mouadia           #+#    #+#             */
/*   Updated: 2024/03/07 06:23:30 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

void	atoi_boucle(char *str, int *num)
{
	int	digit;

	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_exit("Error", str);
		*num *= 10;
		digit = (int)(*str - '0');
		if (digit < 0)
			digit = -digit;
		*num += digit;
		str++;
	}
}

int	ft_atoi(char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (white_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	atoi_boucle(str, &num);
	return (num * sign);
}

void	adv_atoi_cond(t_stack **a, char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		ft_exit("Error", str);
	num = num * 10 + *str - '0';
	str++;
	if (*str == ' ' || *str == '\0')
	{
		ft_lstadd_back(a, ft_lstnew(num * sign));
		sign = 1;
		num = 0;
	}
}

void	ft_adv_atoi(char *str, t_stack **a)
{
	while (white_space(*str))
		str++;
	while (*str)
	{
		while (white_space(*str))
			str++;
		adv_atoi_cond(a, str);
	}
}
