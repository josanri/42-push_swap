/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:11:35 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/14 19:03:29 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_is_in_stack(t_stack *stack, int element)
{
	while (stack != NULL)
	{
		if (stack->num == element)
			return (1);
		stack = stack->nxt;
	}
	return (0);
}

int	ft_is_sorted(t_stack *stack)
{
	int	last;

	if (stack == NULL)
		return (-1);
	last = stack->num;
	stack = stack->nxt;
	while (stack != NULL)
	{
		if (last > stack->num)
			return (0);
		last = stack->num;
		stack = stack->nxt;
	}
	return (1);
}

int	ft_stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		count++;
		stack = stack->nxt;
	}
	return (count);
}

t_stack	*ft_get_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->nxt != NULL)
		stack = stack->nxt;
	return (stack);
}

int	ft_add_front(t_stack **stack, int element)
{
	t_stack	*new;

	if (ft_is_in_stack(*stack, element))
		return (-1);
	if (stack != NULL)
	{
		new = (t_stack *) malloc(sizeof(t_stack));
		if (new == NULL)
			return (-1);
		new->nxt = *stack;
		new->num = element;
		*stack = new;
		return (0);
	}
	return (-1);
}
