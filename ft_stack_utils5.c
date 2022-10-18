/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:00:32 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/17 20:00:47 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_get_last_i_below_range(t_stack **a, int cluster_range)
{
	int		i;
	int		res;
	t_stack	*aux;

	i = 0;
	res = i;
	if (a == NULL)
		return (-1);
	aux = *a;
	while (aux != NULL)
	{
		if (aux->finalpos < cluster_range)
			res = i;
		i++;
		aux = aux->nxt;
	}
	return (res);
}

/**
 * @brief Gets two (or one) node from the same cluster
 * Returns i moves to do or -(size - j) reverse to do
 */
int	ft_rotate_or_reverse(t_stack **a, int cluster_range)
{
	int	i;
	int	j;
	int	size;

	i = ft_get_first_i_below_range(a, cluster_range);
	j = ft_get_last_i_below_range(a, cluster_range);
	size = ft_stack_size(*a);
	if (i == -1)
		return (CONTINUE);
	if (i < size - j)
		return (i);
	else
		return (-(size - j));
}

/**
 * @brief Empties the stack by pushing from a to b elements by stack
 */
void	ft_from_a_to_b(t_stack **a, t_stack **b, int cluster_size)
{
	int	i;
	int	moves;

	i = 1;
	while (ft_stack_size(*a) > 3)
	{
		moves = ft_rotate_or_reverse(a, i * cluster_size);
		if (moves == CONTINUE)
			i++;
		else
		{
			while (moves > 0)
			{
				ft_rotate(a, 'a');
				moves--;
			}
			while (moves < 0)
			{
				ft_reverse(a, 'a');
				moves++;
			}
			ft_push(b, a, 'b');
		}
	}
}

/**
 * @brief Goes from b to a inserting each element where it fits the best
 * in less moves. Takes into account rr and rrr to reduce the number of
 * moves
 * For example:
 *   2    5   6    7   8 
 *      ^
 *      |
 *      3
 */
void	ft_from_b_to_a(t_stack **a, t_stack **b)
{
	t_move	moves;

	while (!ft_is_empty_stack(b))
	{
		ft_find_best_i(a, b, &moves);
		while (moves.ra-- > 0)
			ft_rotate(a, 'a');
		while (moves.rb-- > 0)
			ft_rotate(b, 'b');
		while (moves.rr-- > 0)
		{
			ft_rotate(a, 'r');
			ft_rotate(b, 0);
		}
		while (moves.rra-- > 0)
			ft_reverse(a, 'a');
		while (moves.rrb-- > 0)
			ft_reverse(b, 'b');
		while (moves.rrr-- > 0)
		{
			ft_reverse(a, 'r');
			ft_reverse(b, 0);
		}
		ft_push(a, b, 'a');
	}
}
