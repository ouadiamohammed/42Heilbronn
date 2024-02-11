/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:12:09 by mouadia           #+#    #+#             */
/*   Updated: 2024/02/11 23:02:25 by mouadia          ###   ########.fr       */
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
void	pa(t_stack **stackA, t_stack **stackB)
{
	push(stackB, stackA);
}
void	pb(t_stack **stackA, t_stack **stackB)
{
	push(stackA, stackB);
}

void rotateLinkedList(t_stack **head)
{
	t_stack *temp;
	t_stack *current;

	if(*head == NULL || (*head)->next == NULL)
		ft_exit("Not enough elemnts to rotate. \n", "");

	temp = *head;
	*head = (*head)->next;
	temp->next = NULL;

	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
}

void	ra(t_stack **stackA)
{
	rotateLinkedList(stackA);
}
void	rb(t_stack **stackB)
{
	rotateLinkedList(stackB);
}
void rr(t_stack **stackA, t_stack **stackB)
{
	ra(stackA);
    rb(stackB);
}
void	reverseRotateLinkedList(t_stack **head)
{
	t_stack *temp;
	t_stack *current;

	if (*head == NULL || (*head)->next == NULL)
		ft_exit("Not enough elelmnts to reverse rotate. \n", "");

	current = *head;
	while (current->next != NULL)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = *head;
	*head = temp;
}
void rra(t_stack **stackA)
{
    reverseRotateRight(stackA);
}

void rrb(t_stack **stackB)
{
    reverseRotateRight(stackB);
}

void rrr(t_stack **stackA, t_stack **stackB)
{
    rra(stackA);
    rrb(stackB);
}
