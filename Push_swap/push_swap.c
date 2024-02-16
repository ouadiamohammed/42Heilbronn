/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:57:26 by mouadia           #+#    #+#             */
/*   Updated: 2024/02/16 21:17:59 by mouadia          ###   ########.fr       */
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
			return 1;
		cpy = cpy->next;
	}
	return 0;
}
int	smallest_node(t_stack *cpy)
{
	
    if (cpy == NULL) {
        return -1; 
    }

    int smallestIndex = 0;
    int currentIndex = 0;
    int minValue = cpy->nbr;

    t_stack  *current = cpy->next;

    while (current != NULL) {
        if (current->nbr < minValue) {
            minValue = current->nbr;
            smallestIndex = currentIndex;
        }
        current = current->next;
        currentIndex++;
    }
	printf("%d\n", smallestIndex);
    return smallestIndex;
}

void	sort_three_int(t_stack **a)
{
	if ((*a)->nbr > (*a)->next->nbr)
	{
		rotateFirstTwo(a ,"sa");
		if (ft_check_sort(*a))
			reverseRotateLinkedList(a ,"rra");
		if (ft_check_sort(*a))
			rotateFirstTwo(a ,"sa");
	}
	else if ((*a)->nbr < (*a)->next->nbr)
	{
		reverseRotateLinkedList(a ,"rra");
		if (ft_check_sort(*a))
			rotateFirstTwo(a ,"sa");
	}
}

int main (int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	int size;

    if (ac == 1)
        return (0);
	a = push_swap_init(ac, av);
	size = ft_lstsize(a);
	if (size <= 3 && ft_check_sort(a))
	{
		sort_three_int(&a);
		// sa(321) sa(312) sa(213) rra(231) rra(132)
		// rra(231) (132) 	  123	  123       sa(213)
		// 123 									123
	}
	else if (size <= 5 && ft_check_sort(a))
	{
		while (ft_lstsize(a) > 3)
		{
			printf("##################\n");
			if (smallest_node(a) == 0)
				push(&a, &b, "pb");
			if (smallest_node(a) > 3)
				reverseRotateLinkedList(&a, "rra");
			else if (smallest_node(a) <= 3)
				rotateLinkedList(&a, "ra");
		}
		sort_three_int(&a);
	}
	
	while (a)
	{
		printf("%d ", a->nbr);
		a = a->next;
	}
	printf("\n");
	while (b)
	{
		printf("%d ", b->nbr);
		b = b->next;
	}
	printf("\n");
}