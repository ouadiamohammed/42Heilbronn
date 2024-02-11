/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:12:09 by mouadia           #+#    #+#             */
/*   Updated: 2024/02/11 22:16:28 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate the first two elements in the linked list
void	rotateFirstTwo(t_stack **head)
{
	t_stack *temp;

	if (*head == NULL || (*head)->next == NULL)
		ft_exit("Not enough elements to rotate. \n", "");

	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	
}

void	sa(t_stack **stackA)
{
	rotateFirstTwo(stackA);
}

void	sb(t_stack **stackB)
{
	rotateFirstTwo(stackB);
}

void	ss(t_stack **stackA, t_stack **stackB)
{
	sa(stackA);
	sb(stackB);
}

void	push(t_stack **source, t_stack **destination)
{
	t_stack *temp;

	if (*source == NULL)
		ft_exit("Cannot push from an empty stack. \n", "");

	temp = *source;
	*source = (*source)->next;
	temp->next = *destination;
	*destination = temp;
}
void	pb(t_stack **stackA, t_stack **stackB)
{
	push(stackA, stackB);
}