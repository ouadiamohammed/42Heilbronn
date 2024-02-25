/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:38:28 by mouadia           #+#    #+#             */
/*   Updated: 2024/02/25 14:21:25 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_main_variables vars;

	if (ac == 1)
		return (0);
	vars.a = push_swap_init(ac, av);
	vars.size = ft_lstsize(vars.a);
	if (vars.size <= 3 && !ft_check_sort(vars.a))
		sort_three_int(&vars.a);
	else if (vars.size <= 5 && !ft_check_sort(vars.a))
		sort_five_int(&vars.a, &vars.b, vars.size);
	else if (vars.size > 5 && !ft_check_sort(vars.a))
	{
		vars.size = ft_lstsize(vars.a);
		vars.sorted_array = sort_stack_in_array(vars.a, vars.size);
		vars.sec = 0;
		vars.start = 0;
		
		if (vars.size <= 100)
			vars.chunks = 6;
		else
			vars.chunks = 11;
		vars.range = vars.size / vars.chunks;
		while (vars.a)
		{
			int back = 0;
			vars.index = ft_get_index(vars.a, vars.sorted_array, vars.start, vars.range + vars.start);
			if (vars.index >= ft_lstsize(vars.a) / 2)
			{
				while (++vars.index <= ft_lstsize(vars.a))
					reverse_rotate_linked_list(&vars.a, "rra");				
			}
			else
			{
				while (--vars.index >= 0)
					rotate_linked_list(&vars.a, "ra");				
			}
			push(&vars.a, &vars.b, "pb");
			if (ft_lstsize(vars.b) >= vars.range + vars.start)
			{				
				vars.start += vars.range;
			}
		}
		int j = 0;
		while (vars.b)
		{
			vars.big = vars.sorted_array[vars.size - 1 - j];
			vars.sec_big = vars.sorted_array[vars.size - 2 - j];
			vars.index = ft_big_index(vars.b, vars.big);
			if (vars.index < ft_lstsize(vars.b) / 2)
			{
				while (vars.b->nbr != vars.big)
				{
					if (vars.b->nbr == vars.sec_big)
					{
						push(&vars.b, &vars.a, "pa");
						vars.sec = 1;
					}
					else
						rotate_linked_list(&vars.b, "rb");
				}
			}
			else
			{
				while (vars.b->nbr != vars.big)
				{
					if (vars.b->nbr == vars.sec_big)
					{
						push(&vars.b, &vars.a, "pa");
						vars.sec = 1;
					}
					else
						reverse_rotate_linked_list(&vars.b, "rrb");
				}
			}
			push(&vars.b, &vars.a, "pa");
			if (vars.sec == 1)
			{
				rotate_first_two(&vars.a, "sa");
				vars.sec = 0;
				j++;
			}
			j++;
		}
		free(vars.sorted_array);
	}
	// ft_print_stack(vars.a);
}
