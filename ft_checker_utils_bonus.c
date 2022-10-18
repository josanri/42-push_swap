/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:45:29 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/15 10:50:50 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_swap(t_stack **a, t_stack **b, char *res)
{
	if (ft_strcmp(res, "sa\n") == 0)
		return (ft_swap(a, 0), 1);
	else if (ft_strcmp(res, "sb\n") == 0)
		return (ft_swap(b, 0), 1);
	else
		return (0);
}

int	ft_check_push(t_stack **a, t_stack **b, char *res)
{
	if (ft_strcmp(res, "pa\n") == 0)
		return (ft_push(a, b, 0), 1);
	else if (ft_strcmp(res, "pb\n") == 0)
		return (ft_push(b, a, 0), 1);
	else
		return (0);
}

int	ft_check_rotate(t_stack **a, t_stack **b, char *res)
{
	if (ft_strcmp(res, "ra\n") == 0)
		return (ft_rotate(a, 0), 1);
	else if (ft_strcmp(res, "rb\n") == 0)
		return (ft_rotate(b, 0), 1);
	else if (ft_strcmp(res, "rr\n") == 0)
		return (ft_rotate(a, 0), ft_rotate(b, 0), 1);
	else
		return (0);
}

int	ft_check_reverse(t_stack **a, t_stack **b, char *res)
{
	if (ft_strcmp(res, "rra\n") == 0)
		return (ft_reverse(a, 0), 1);
	else if (ft_strcmp(res, "rrb\n") == 0)
		return (ft_reverse(b, 0), 1);
	else if (ft_strcmp(res, "rrr\n") == 0)
		return (ft_reverse(a, 0), ft_reverse(b, 0), 1);
	else
		return (0);
}
