/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:14:04 by mouadia           #+#    #+#             */
/*   Updated: 2024/03/04 12:23:42 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(const char *str)
{
	while (*str)
		write(1, &*str++, 1);
	write(1, "\n", 1);
}

void	push(t_stack **source, t_stack **destination, const char *inst)
{
	t_stack	*temp;

	if (*source == NULL)
		return ;
	temp = *source;
	*source = (*source)->next;
	temp->next = *destination;
	*destination = temp;
	ft_putstr(inst);
}

void	rotate_first_two(t_stack **head, const char *inst)
{
	t_stack	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	ft_putstr(inst);
}
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c1;

	i = 0;
	c1 = (char)c;
	while (s[i])
	{
		if (s[i] == c1)
			return ((char *)s + i);
		i++;
	}
	if (c1 == '\0')
		return ((char *)s + i);
	return (0);
}

