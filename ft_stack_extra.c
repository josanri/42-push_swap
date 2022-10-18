/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:00:56 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/14 19:09:14 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

void	ft_print_stack(t_stack	*stack)
{
	while (stack != NULL)
	{
		printf("%d ", stack->num);
		stack = stack->nxt;
	}
	printf("(null)\n");
}

void	ft_print_stack_extra(t_stack	*stack)
{
	while (stack != NULL)
	{
		printf("X: %d , Pos: %d", stack->num, stack->finalpos);
		stack = stack->nxt;
	}
	printf("(null)\n");
}
