/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:12:09 by mouadia           #+#    #+#             */
/*   Updated: 2024/02/16 20:14:58 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_putstr(const char *str)
{
	while (*str)
		write(1, &*str++, 1);
	write(1, "\n", 1);
}

// rotate the first two elements in the linked list (sa|sb)
void	rotateFirstTwo(t_stack **head, const char *inst)
{
	t_stack *temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;

	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	ft_putstr(inst);
}

// void	sa(t_stack **stackA)
// {
// 	rotateFirstTwo(stackA);
// }

// void	sb(t_stack **stackB)
// {
// 	rotateFirstTwo(stackB);
// }

void	ss(t_stack **stackA, t_stack **stackB)
{
	rotateFirstTwo(stackA, "s");
	rotateFirstTwo(stackB, "s\n");
}

void	push(t_stack **source, t_stack **destination, const char *inst)
{
	t_stack *temp;

	if (*source == NULL)
		return ;

	temp = *source;
	*source = (*source)->next;
	temp->next = *destination;
	*destination = temp;
	ft_putstr(inst);
}
// void	pa(t_stack **stackA, t_stack **stackB)
// {
// 	push(stackB, stackA);
// }
// void	pb(t_stack **stackA, t_stack **stackB)
// {
// 	push(stackA, stackB);
// }

void rotateLinkedList(t_stack **head, const char *inst)
{
	t_stack *temp;
	t_stack *current;

	if(*head == NULL || (*head)->next == NULL)
		return ;

	temp = *head;
	*head = (*head)->next;
	temp->next = NULL;

	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	ft_putstr(inst);
}

// void	ra(t_stack **stackA)
// {
// 	rotateLinkedList(stackA);
// }
// void	rb(t_stack **stackB)
// {
// 	rotateLinkedList(stackB);
// }
void rr(t_stack **stackA, t_stack **stackB)
{
	rotateLinkedList(stackA, "r");
    rotateLinkedList(stackB, "r\n");
}
void	reverseRotateLinkedList(t_stack **head, const char *inst)
{
	t_stack *temp;
	t_stack *current;

	if (*head == NULL || (*head)->next == NULL)
		return ;

	current = *head;
	while (current->next->next != NULL)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = *head;
	*head = temp;
	ft_putstr(inst);
}
// void rra(t_stack **stackA)
// {
//     reverseRotateRight(stackA);
// }

// void rrb(t_stack **stackB)
// {
//     reverseRotateRight(stackB);
// }

void rrr(t_stack **stackA, t_stack **stackB)
{
    reverseRotateLinkedList(stackA, "r");
    reverseRotateLinkedList(stackB, "rr\n");
}
