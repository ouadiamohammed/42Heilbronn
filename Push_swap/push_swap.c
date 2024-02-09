/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:57:26 by mouadia           #+#    #+#             */
/*   Updated: 2024/02/09 21:37:31 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stuc	*ft_lstnew(void *content)
{
	t_stuc	*new_node;

	new_node = malloc(sizeof(t_stuc));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
void	ft_lstadd_back(t_stuc **lst, t_stuc *new)
{
	t_stuc	*last_node;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last_node = *lst;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new;
	}
}

t_stuc  push_swap_init (int ac, char **av)
{
    int i = 0;
    int j;
       while (i < ac)
       {
        j = 0;
            while (av[i][j] != '/0')
            {
                /* code */
            }
            
            i++;
       }
       
}

int main (int ac, char **av)
{
    if (ac == 1)
        return (0);
    
}