/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:08:18 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/18 17:00:15 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_find_greatest_i(t_stack	**a)
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
	return (highest_i);
}

void	ft_optimize_reverse(t_move *aux)
{
	if (aux->rra > 0 && aux->rrb > 0)
	{
		if (aux->rra > aux->rrb)
		{
			aux->rrr = aux->rrb;
			aux->rra -= aux->rrb;
			aux->rrb = 0;
		}
		else if (aux->rra < aux->rrb)
		{
			aux->rrr = aux->rra;
			aux->rrb -= aux->rra;
			aux->rra = 0;
		}
		else if (aux->rra == aux->rrb)
		{
			aux->rrr = aux->rrb;
			aux->rrb = 0;
			aux->rra = 0;
		}
	}
}
