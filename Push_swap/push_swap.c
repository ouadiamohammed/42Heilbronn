/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:57:26 by mouadia           #+#    #+#             */
/*   Updated: 2024/03/07 06:22:33 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last_node = *lst;
		while (last_node->next != NULL)
		{
			if (last_node->nbr == new->nbr)
				ft_exit("Error", "");
			last_node = last_node->next;
		}
		if (last_node->nbr == new->nbr)
			ft_exit("Error", "");
		last_node->next = new;
	}
}

t_stack	*push_swap_init(int ac, char **av)
{
	t_stack	*a;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
			ft_adv_atoi(av[i], &a);
		else if (av[i][0] != '\0')
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	return (a);
}

int	*sort_stack_in_array(t_stack *a, int size)
{
	int	*array;
	int	i;
	int	end;

	array = malloc(sizeof(t_stack) * size);
	i = 0;
	if (!array)
		ft_exit("malloc failled", NULL);
	while (a)
	{
		array[i] = a->nbr;
		a = a->next;
		i++;
	}
	end = i;
	sorting_array(array, end);
	return (array);
}

int	ft_get_index(t_stack *a, int *array, int start, int end)
{
	int	index;
	int	i;

	index = -1;
	while (a)
	{
		i = start;
		index++;
		while (i < end)
		{
			if (array[i] == a->nbr)
				return (index);
			i++;
		}
		a = a->next;
	}
	return (index);
}

int	ft_big_index(t_stack *b, int big)
{
	int	index;

	index = 0;
	while (b)
	{
		if (b->nbr == big)
			break ;
		index++;
		b = b->next;
	}
	return (index);
}
