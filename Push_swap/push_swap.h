/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:02:41 by mouadia           #+#    #+#             */
/*   Updated: 2024/02/22 21:15:26 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct push_swap
{
    int nbr;
    struct push_swap *next;
}t_stack;


void ft_exit(const char* msg, const char *type);

void	rotateFirstTwo(t_stack **head, const char *inst);
void	ss(t_stack **stackA, t_stack **stackB);
void	push(t_stack **source, t_stack **destination, const char *inst);
void    rotateLinkedList(t_stack **head, const char *inst);
void    rr(t_stack **stackA, t_stack **stackB);
void	reverseRotateLinkedList(t_stack **head, const char *inst);
void    rrr(t_stack **stackA, t_stack **stackB);
void    ft_putstr(const char *str);
int	    ft_lstsize(t_stack *lst);

#endif