/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:12:48 by mouadia           #+#    #+#             */
/*   Updated: 2024/03/07 05:51:56 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int nbr)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->nbr = nbr;
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	smallest_node(t_stack *cpy)
{
	int		small_index;
	int		current_index;
	int		min_value;
	t_stack	*current;

	small_index = 0;
	current_index = 1;
	min_value = cpy->nbr;
	current = cpy->next;
	if (cpy == NULL)
		return (-1);
	while (current != NULL)
	{
		if (current->nbr < min_value)
		{
			min_value = current->nbr;
			small_index = current_index;
		}
		current = current->next;
		current_index++;
	}
	return (small_index);
}

void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d ", stack->nbr);
		stack = stack->next;
	}
	printf("\n");
}

int	ft_check_sort(t_stack *cpy)
{
	while (cpy->next)
	{
		if (cpy->nbr > cpy->next->nbr)
			return (0);
		cpy = cpy->next;
	}
	return (1);
}
