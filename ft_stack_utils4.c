/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:41:03 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/17 20:00:20 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_get_i_num(t_stack **a, int indx)
{
	int		i;
	t_stack	*stck;

	i = 0;
	stck = *a;
	while (i < indx)
	{
		stck = stck->nxt;
		i++;
	}
	return (stck->finalpos);
}

/**
 * @brief 
 * If the stack is sorted like 2 1 3, swap is needed
 * If the stack is sorted like 3 1 2, rotate is needed
 * If the stack is sorted like 2 3 1, reverse is needed
 * If the stack is sorted like 1 3 2, swap and rotate is needed
 * If the stack is sorted like 3 2 1, swap and reverse is needed
 * If the stack is sorted like 1 2 3, no move is needed
 * The conditions are treated comparing where the 2nd position.
 */
void	ft_sort_three(t_stack	**stack, char c)
{
	t_stack	*a;

	a = *stack;
	if (a->num > a->nxt->num && a->num < a->nxt->nxt->num)
		ft_swap(stack, c);
	else if (a->nxt->nxt->num < a->num && a->nxt->nxt->num > a->nxt->num)
		ft_rotate(stack, c);
	else if (a->num < a->nxt->num && a->num > a->nxt->nxt->num)
		ft_reverse(stack, c);
	else if (a->nxt->nxt->num < a->nxt->num && a->nxt->nxt->num > a->num)
	{
		ft_swap(stack, c);
		ft_rotate(stack, c);
	}
	else if (a->nxt->num < a->num && a->nxt->num > a->nxt->nxt->num)
	{
		ft_swap(stack, c);
		ft_reverse(stack, c);
	}
}

/**
 * @brief If the size of the stack is lower than 3 check if it is sorted.
 * If not, swaps.
 */
void	ft_sort_lower_three(t_stack	**a, char c)
{
	if (!ft_is_sorted(*a))
		ft_swap(a, c);
}

/**
 * @brief Up to five, it get the elements with lowest desired position and
 * push them to stack b, sorts stack a and push back to a.
 */
void	ft_sort_up_to_five(t_stack **a, t_stack **b, int size)
{
	int	a_size;
	int	i;

	ft_desired_pos(*a);
	a_size = size;
	while (a_size > 3)
	{
		i = ft_find_lowest_i(a, a_size);
		if (i < size / 2)
			while (i-- > 0)
				ft_rotate(a, 'a');
		else
			while (i++ < a_size)
				ft_reverse(a, 'a');
		ft_push(b, a, 'b');
		a_size--;
	}
	ft_sort_three(a, 'a');
	if (size == 5)
		ft_push(a, b, 'a');
	ft_push(a, b, 'a');
}

int	ft_get_first_i_below_range(t_stack **a, int cluster_range)
{
	int		i;
	t_stack	*aux;

	i = 0;
	if (a == NULL)
		return (-1);
	aux = *a;
	while (aux != NULL)
	{
		if (aux->finalpos < cluster_range)
			break ;
		i++;
		aux = aux->nxt;
	}
	if (aux == NULL)
		return (-1);
	return (i);
}
