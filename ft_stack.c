/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:32:15 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/14 19:29:18 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(t_stack **stack, char c)
{
	t_stack	*aux;

	if (c != 0)
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	if (stack != NULL)
	{
		if (*stack != NULL && (*stack)->nxt != NULL)
		{
			aux = *stack;
			*stack = (*stack)->nxt;
			aux->nxt = (*stack)->nxt;
			(*stack)->nxt = aux;
		}
	}
}

void	ft_push(t_stack **stack_a, t_stack **stack_b, char c)
{
	t_stack	*aux;

	if (c != 0)
	{
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	if (stack_b != NULL)
	{
		if (*stack_b != NULL)
		{
			aux = *stack_b;
			*stack_b = aux -> nxt;
			aux ->nxt = *stack_a;
			*stack_a = aux;
		}
	}
}

void	ft_rotate(t_stack	**stack, char c)
{
	t_stack	*aux;

	if (c != 0)
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	if (stack != NULL)
	{
		if (*stack != NULL && (*stack)->nxt != NULL)
		{
			aux = *stack;
			ft_get_last(*stack)->nxt = *stack;
			*stack = (*stack)->nxt;
			aux->nxt = NULL;
		}
	}
}

void	ft_reverse(t_stack **stack, char c)
{
	t_stack	*pivot;
	t_stack	*aux;

	if (c != 0)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	if (stack == NULL || *stack == NULL || (*stack)->nxt == NULL)
		return ;
	pivot = *stack;
	while (pivot->nxt->nxt != NULL)
		pivot = pivot->nxt;
	aux = pivot->nxt;
	pivot->nxt = NULL;
	aux->nxt = *stack;
	*stack = aux;
}
