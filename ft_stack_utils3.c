/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:47:33 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/18 17:00:23 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_part_b(t_stack **b, t_move *moves, int i)
{
	if (i < ft_stack_size(*b) / 2 || ft_stack_size(*b) == 1)
		moves->rb = i;
	else
		moves->rrb = ft_stack_size(*b) - i;
}

void	ft_part_a(t_stack **a, t_move *moves, int i_lower)
{
	if (i_lower < ft_stack_size(*a) / 2 || ft_stack_size(*a) == 1)
		moves->ra = i_lower;
	else
		moves->rra = ft_stack_size(*a) - i_lower;
}

int	ft_loop(t_stack **a, int x)
{
	int		a_lower;
	int		i_lower;
	int		cont;
	t_stack	*stck;

	cont = 0;
	a_lower = 2147483647;
	stck = *a;
	while (stck != NULL)
	{
		if (stck->finalpos > x && a_lower >= stck->finalpos)
		{
			a_lower = stck->finalpos;
			i_lower = cont;
		}
		stck = stck ->nxt;
		cont++;
	}
	return (i_lower);
}

void	ft_find_best_moves(t_stack **a, t_stack **b, int i, t_move *moves)
{
	int		x;
	int		i_lower;

	i_lower = 0;
	ft_part_b(b, moves, i);
	x = ft_get_i_num(b, i);
	if (ft_find_greatest_if(a) < x)
		i_lower = ft_find_lowest_i(a, ft_stack_size(*a) + ft_stack_size(*b));
	else
		i_lower = ft_loop(a, x);
	ft_part_a(a, moves, i_lower);
}

void	ft_find_best_i(t_stack **a, t_stack **b, t_move *moves)
{
	int		i;
	t_stack	*stck;
	t_move	aux;

	ft_restart_moves(moves);
	stck = *b;
	i = 0;
	while (i < ft_stack_size(*b))
	{
		ft_init_moves(&aux);
		ft_find_best_moves(a, b, i, &aux);
		ft_optimize_rotate(&aux);
		ft_optimize_reverse(&aux);
		if (ft_totalcost(moves) > ft_totalcost(&aux))
			ft_copy(moves, &aux);
		stck = stck -> nxt;
		i++;
	}
}
