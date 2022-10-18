/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:07:05 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/17 20:07:18 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_restart_moves(t_move *aux)
{
	aux->ra = 0;
	aux->rb = 0;
	aux->rr = 0;
	aux->rra = 0;
	aux->rrb = 0;
	aux->rrr = 2147483647;
}

void	ft_init_moves(t_move *aux)
{
	aux->ra = 0;
	aux->rb = 0;
	aux->rr = 0;
	aux->rra = 0;
	aux->rrb = 0;
	aux->rrr = 0;
}

void	ft_copy(t_move *moves, t_move *aux)
{
	moves->ra = aux->ra;
	moves->rb = aux->rb;
	moves->rr = aux->rr;
	moves->rra = aux->rra;
	moves->rrb = aux->rrb;
	moves->rrr = aux->rrr;
}

int	ft_totalcost(t_move *moves)
{
	return (moves->ra + moves->rb + moves->rr
		+ moves->rra + moves->rrb + moves->rrr);
}

void	ft_optimize_rotate(t_move *aux)
{
	if (aux->rra > 0 && aux->rrb > 0)
	{
		if (aux->ra > aux->rb)
		{
			aux->rr = aux->rb;
			aux->ra = aux->ra - aux->rb;
			aux->rb = 0;
		}
		else if (aux->ra < aux->rb)
		{
			aux->rr = aux->ra;
			aux->rb = aux->rb - aux->ra;
			aux->ra = 0;
		}
		else if (aux->ra == aux->rb)
		{
			aux->rr = aux->rb;
			aux->rb = 0;
			aux->rb = 0;
		}
	}
}
