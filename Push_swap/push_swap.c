/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:57:26 by mouadia           #+#    #+#             */
/*   Updated: 2024/02/19 19:58:15 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

void ft_exit(const char* msg, const char *type)
{
	printf("%s%s\n",msg, type);
	exit(0);
}

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
void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last_node = *lst;
		while (last_node->next != NULL)
		{
			if (last_node->nbr == new->nbr)
				ft_exit("err duplicat","");
			last_node = last_node->next;
		}
		if (last_node->nbr == new->nbr)
			ft_exit("err duplicat","");
		last_node->next = new;
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	digit;

	num = 0;
	sign = 1;
	while (white_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_exit("error in ", str);
		num *= 10;
		digit = (int)(*str - '0');
		if (digit < 0)
			digit = -digit;
		num += digit;
		str++;
	}
	return (num * sign);
}

void	ft_adv_atoi(char *str, t_stack **a)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;

	while (white_space(*str))
		str++;
	while (*str)
	{
		while (white_space(*str))
			str++;
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				sign = -1;
			str++;
		}
		if (!ft_isdigit(*str))
			ft_exit("adv_error in ", str);
		num = num * 10 + *str - '0';
		str++;
		if (*str == ' ' || *str == '\0')
		{
			ft_lstadd_back(a, ft_lstnew(num * sign));
			sign = 1;
			num = 0;
		}
	}
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c1;

	i = 0;
	c1 = (char)c;
	while (s[i])
	{
		if (s[i] == c1)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (c1 == '\0')
		return ((char *)s + i);
	return (0);
}

t_stack  *push_swap_init (int ac, char **av)
{
	t_stack *a = NULL;

    int i = 1;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
			ft_adv_atoi(av[i], &a);
		else if (av[i][0] != '\0')
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
    return a;
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

void	sort_three_int(t_stack **a)
{
	if (ft_check_sort(*a))
		return ;
	if ((*a)->nbr > (*a)->next->nbr)
	{
		rotateFirstTwo(a ,"sa");
		if (!ft_check_sort(*a))
			reverseRotateLinkedList(a ,"rra");
		if (!ft_check_sort(*a))
			rotateFirstTwo(a ,"sa");
	}
	else if ((*a)->nbr < (*a)->next->nbr)
	{
		reverseRotateLinkedList(a ,"rra");
		if (!ft_check_sort(*a))
			rotateFirstTwo(a ,"sa");
	}
}

void sort_five_int(t_stack **a, t_stack **b, int size)
{
	while (ft_lstsize(*a) > 3)
	{
		if (smallest_node(*a) == 0)
			push(a, b, "pb");
		else if (smallest_node(*a) >= 3)
			reverseRotateLinkedList(a, "rra");
		else if (smallest_node(*a) < 3)
			rotateLinkedList(a, "ra");
	}
	sort_three_int(a);
	push(b, a, "pa");
	if (size != ft_lstsize(*a))
		push(b, a, "pa");
	if ((*a)->nbr > (*a)->next->nbr)
		rotateFirstTwo(a, "ra");
}

int *sort_stack_in_array(t_stack *a, int size)
{
	int *array = malloc(sizeof(t_stack) * size);
	int i = 0;
	int j;
	int end;
	int save;
	
	if (!array)
		ft_exit("malloc failled", NULL);
	while (a)
	{
		array[i] = a->nbr;
		a = a->next;
		i++;
	}
	end = i;
	i = 0;
	while (i < end)
	{
		j = i + 1;
		while (j < end)
		{
			if (array[i] > array[j])
			{
				save = array[i];
				array[i] = array[j];
				array[j] = save;
			}
			j++;
		}
		i++;
	}
	// i = 0;
	// while (i < end)
	// {
	// 	printf("%d ", array[i++]);
	// }
	// 	printf("\n\n");
	

	return array;
}

int ft_get_index(t_stack *a, int *array, int start, int end)
{
	int index = -1;
	int i;


	// printf("start = %d\n", start);
	// printf("end = %d\n", end);

	while (a)
	{
		i = start;
		index++;
		while (i < end)
		{
			if (array[i] == a->nbr)
				return index;
			i++;
		}
		a = a->next;
	}

	return index;
}

int ft_big_index(t_stack *b, int big)
{
	int index = 0;

	while (b)
	{
		if (b->nbr == big)
			break;
		index++;
		b = b->next;
	}
	return index;
}

int ft_get_pos(t_stack *a, int nbr)
{
	int i = 0;

	while (a)
	{
		i++;
		a = a->next;
		if (a == NULL)
			break;
	}
	return i;
}


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
	{
		sort_three_int(&a);
		// sa(321) sa(312) sa(213) rra(231) rra(132)
		// rra(231) (132) 	  123	  123       sa(213)
		// 123 									123
	}
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
		// printf("%d / %d = %d\n", size, chunks, range);
		while (a)
		{
			int back = 0;
			// printf("size = %d\n", size);
			index = ft_get_index(a, sorted_array, start, range + start);
			// printf("index = %d     start = %d     end = %d\n", index, start, range + start);
			if (index >= ft_lstsize(a) / 2)
			{
				while (++index <= ft_lstsize(a))
					reverseRotateLinkedList(&a, "rra");				
			}
			else
			{
				while (--index >= 0)
					rotateLinkedList(&a, "ra");				
			}
			push(&a, &b, "pb");
			if (ft_lstsize(b) >= range + start)
			{
				while (back--)
					reverseRotateLinkedList(&b, "rrb");				
				start += range;
			}
			// ft_print_stack(b);
		}
		// printf("--------------------------------\n");
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
						rotateLinkedList(&b, "rb");
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
						reverseRotateLinkedList(&b, "rrb");
				}
			}
			push(&b, &a, "pa");
			if (sec == 1)
			{
				rotateFirstTwo(&a, "sa");
				sec = 0;
				j++;
			}
			j++;
		}
	}
	ft_print_stack(a);
}