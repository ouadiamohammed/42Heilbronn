/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:12:09 by mouadia           #+#    #+#             */
/*   Updated: 2024/02/22 21:19:42 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **stackA, t_stack **stackB)
{
	rotateFirstTwo(stackA, "s");
	rotateFirstTwo(stackB, "s\n");
}

void	rotateLinkedList(t_stack **head, const char *inst)
{
	t_stack	*temp;
	t_stack	*current;

	if (*head == NULL || (*head)->next == NULL)
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

void	rr(t_stack **stackA, t_stack **stackB)
{
	rotateLinkedList(stackA, "r");
	rotateLinkedList(stackB, "r\n");
}

void	reverseRotateLinkedList(t_stack **head, const char *inst)
{
	t_stack	*temp;
	t_stack	*current;

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

void	rrr(t_stack **stackA, t_stack **stackB)
{
	reverseRotateLinkedList(stackA, "r");
	reverseRotateLinkedList(stackB, "rr\n");
}
