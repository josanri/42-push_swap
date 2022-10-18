/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:05:24 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/18 19:35:56 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "get_next_line/get_next_line.h"

static int	ft_exit(t_stack **a, t_stack **b, char *res)
{
	write(2, "Error\n", 6);
	free(res);
	ft_free_stack(a);
	ft_free_stack(b);
	return (-1);
}

int	ft_check(t_stack **a, t_stack **b)
{
	char	*res;

	res = get_next_line(0);
	while (res != NULL)
	{
		if (!ft_check_swap(a, b, res))
			if (!ft_check_push(a, b, res))
				if (!ft_check_rotate(a, b, res))
					if (!ft_check_reverse(a, b, res))
						return (ft_exit(a, b, res));
		free(res);
		res = get_next_line(0);
	}
	if (ft_is_sorted(*a) && ft_stack_size(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}

static int	ft_fill_stacks(char **res, int len, t_stack *a, t_stack *b)
{
	int	err;

	len--;
	while (len >= 0)
	{
		err = ft_add_front(&a, ft_atoi(res[len]));
		if (err == -1)
			return (write(2, "Error\n", 6), ft_free_stack(&a), -1);
		len--;
	}
	return (ft_check(&a, &b));
}

int	main(int argc, char **argv)
{
	char	**res;

	if (ft_sintax_check(argc, argv) == -1)
		return (-1);
	if (argc == 2)
	{
		res = ft_split(argv[1], ' ');
		if (res == NULL)
			return (write(2, "Error\n", 6), -1);
		if (*res == NULL)
			return (free(res), write(2, "Error\n", 6), -1);
		ft_fill_stacks(res, ft_split_size(res), NULL, NULL);
		ft_free_split(res);
	}
	else
	{
		res = &argv[1];
		ft_fill_stacks(res, argc - 1, NULL, NULL);
	}
	return (0);
}
