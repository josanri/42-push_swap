/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:47:33 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/18 17:31:54 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_is_empty_stack(t_stack **stack)
{
	if (stack == NULL)
		return (1);
	if (*stack == NULL)
		return (1);
	else
		return (0);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*nxt;

	if (stack != NULL)
	{
		aux = *stack;
		while (aux != NULL)
		{
			nxt = aux;
			aux = aux->nxt;
			free(nxt);
			nxt = NULL;
		}
		*stack = NULL;
	}
}

void	ft_desired_pos(t_stack *stack)
{
	t_stack	*aux;
	t_stack	*top;
	int		i;

	if (stack != NULL)
	{
		aux = stack;
		while (aux != NULL)
		{
			top = stack;
			i = 0;
			while (top != NULL)
			{
				if (aux->num > top->num)
					i++;
				top = top -> nxt;
			}
			aux->finalpos = i;
			aux = aux->nxt;
		}
	}
}

int	ft_find_lowest_i(t_stack	**a, int size)
{
	t_stack	*stack;
	int		lowest_i;
	int		i;
	int		lowest_final;

	if (a == NULL)
		return (-1);
	stack = *a;
	lowest_final = size;
	i = 0;
	while (stack != NULL)
	{
		if (stack->finalpos < lowest_final)
		{
			lowest_final = stack->finalpos;
			lowest_i = i;
		}
		stack = stack -> nxt;
		i++;
	}
	return (lowest_i);
}

int	ft_find_greatest_if(t_stack	**a)
{
	t_stack	*stack;
	int		highest_i;
	int		highest_final;
	int		i;

	if (a == NULL)
		return (-1);
	stack = *a;
	highest_final = -1;
	highest_i = -1;
	i = 0;
	while (stack != NULL)
	{
		if (stack->finalpos > highest_final)
		{
			highest_final = stack->finalpos;
			highest_i = i;
		}
		stack = stack -> nxt;
		i++;
	}
	return (highest_final);
}
