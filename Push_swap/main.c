/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:38:28 by mouadia           #+#    #+#             */
/*   Updated: 2024/02/25 12:39:07 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	int size;
	int index;

    if (ac == 1)
        return (0);
	a = push_swap_init(ac, av);
	size = ft_lstsize(a);
	if (size <= 3 && !ft_check_sort(a))
		sort_three_int(&a);
	else if (size <= 5 && !ft_check_sort(a))
		sort_five_int(&a, &b, size);
	else if (size > 5 && !ft_check_sort(a))
	{
		int size = ft_lstsize(a);
		int *sorted_array = sort_stack_in_array(a, size);
		int chunks;
		int range;
		int sec = 0;
		int start = 0;
		
		if (size <= 100)
			chunks = 6;
		else
			chunks = 11;
		range = size / chunks;
		while (a)
		{
			int back = 0;
			index = ft_get_index(a, sorted_array, start, range + start);
			if (index >= ft_lstsize(a) / 2)
			{
				while (++index <= ft_lstsize(a))
					reverse_rotate_linked_list(&a, "rra");				
			}
			else
			{
				while (--index >= 0)
					rotate_linked_list(&a, "ra");				
			}
			push(&a, &b, "pb");
			if (ft_lstsize(b) >= range + start)
			{				
				start += range;
			}
		}
		int j = 0;
		while (b)
		{
			int big = sorted_array[size - 1 - j];
			int sec_big = sorted_array[size - 2 - j];
			index = ft_big_index(b, big);
			if (index < ft_lstsize(b) / 2)
			{
				while (b->nbr != big)
				{
					if (b->nbr == sec_big)
					{
						push(&b, &a, "pa");
						sec = 1;
					}
					else
						rotate_linked_list(&b, "rb");
				}
			}
			else
			{
				while (b->nbr != big)
				{
					if (b->nbr == sec_big)
					{
						push(&b, &a, "pa");
						sec = 1;
					}
					else
						reverse_rotate_linked_list(&b, "rrb");
				}
			}
			push(&b, &a, "pa");
			if (sec == 1)
			{
				rotate_first_two(&a, "sa");
				sec = 0;
				j++;
			}
			j++;
		}
		free(sorted_array);
	}
	ft_print_stack(a);
}
