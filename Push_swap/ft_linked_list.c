/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:12:48 by mouadia           #+#    #+#             */
/*   Updated: 2024/03/04 12:19:24 by mouadia          ###   ########.fr       */
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
	
	if (cpy == NULL) {
		return -1; 
	}

	int smallIndex = 0;
	int currentIndex = 1;
	int minValue = cpy->nbr;

	t_stack  *current = cpy->next;

	while (current != NULL) {
		if (current->nbr < minValue) {
			minValue = current->nbr;
			smallIndex = currentIndex;
		}
		current = current->next;
		currentIndex++;
	}
	return smallIndex;
}

void ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d ", stack->nbr);
		stack = stack->next;
	}
	printf("\n");
}

int ft_check_sort(t_stack *cpy)
{
	while(cpy->next)
	{
		if (cpy->nbr > cpy->next->nbr)
			return 0;
		cpy = cpy->next;
	}
	return 1;
}