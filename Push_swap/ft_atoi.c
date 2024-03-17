/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:59:49 by mouadia           #+#    #+#             */
/*   Updated: 2024/03/17 13:58:28 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

void	atoi_boucle(char *str, long int *num, int sign)
{
	int	digit;

	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_exit("Error\n");
		*num *= 10;
		digit = (int)(*str - '0');
		*num += digit;
		if (*num * sign > INT_MAX || *num * sign < INT_MIN)
			ft_exit("Error\n");
		str++;
	}
}

int	ft_atoi(char *str)
{
	long int	num;
	int			sign;

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
	atoi_boucle(str, &num, sign);
	return (num * sign);
}

void	adv_atoi_cond(t_stack **a, char *str, long int *num, int *sign)
{
	if (!ft_isdigit(*str))
		ft_exit("Error\n");
	*num = *num * 10 + *str - '0';
	if (*num * *sign > INT_MAX || *num * *sign < INT_MIN)
			ft_exit("Error\n");
	if (*(str + 1) == ' ' || *(str + 1) == '\0')
	{
		ft_lstadd_back(a, ft_lstnew(*num * *sign));
		*sign = 1;
		*num = 0;
	}
}

void	ft_adv_atoi(char *str, t_stack **a)
{
	long int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (white_space(*str))
		str++;
	while (*str)
	{
		while (white_space(*str))
			str++;
		if ((*str == '-' || *str == '+') && num == 0)
		{
			if (*str == '-')
				sign = -1;
			str++;
		}
		adv_atoi_cond(a, str, &num, &sign);
		str++;
	}
}
