/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:23:25 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/18 17:35:35 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/**
 * @brief Sorts by using the cluster size
 * First step, empty stack A
 * Second step, get the greatest from B and push to B
 */
void	ft_sort_by_cluster(t_stack **a, t_stack **b, int cluster_size)
{
	int	size;

	ft_desired_pos(*a);
	ft_from_a_to_b(a, b, cluster_size);
	ft_sort_three(a, 'a');
	ft_from_b_to_a(a, b);
	size = ft_stack_size(*a);
	while (ft_find_lowest_i(a, size) < (size / 2)
		&& ft_find_lowest_i(a, size) > 0)
		ft_rotate(a, 'a');
	while (ft_find_lowest_i(a, size) > 0)
		ft_reverse(a, 'a');
}

void	ft_sort_stack(t_stack **a, t_stack **b)
{
	int	cluster_size;
	int	stack_size;

	stack_size = ft_stack_size(*a);
	cluster_size = 0;
	if (stack_size <= 120)
		cluster_size = stack_size;
	else
		cluster_size = stack_size / 2;
	ft_sort_by_cluster(a, b, cluster_size);
}

/**
 * @brief Executes the algorithm depending on the size of the stack
 */
int	ft_execute(char **res, int len,	t_stack	*a, t_stack	*b)
{
	int		err;
	int		size;

	len--;
	while (len >= 0)
	{
		err = ft_add_front(&a, ft_atoi(res[len--]));
		if (err == -1)
			return (write(2, "Error", 6), ft_free_stack(&a), -1);
	}
	size = ft_stack_size(a);
	if (!ft_is_sorted(a))
	{	
		if (size < 3)
			ft_sort_lower_three(&a, 'a');
		else if (size == 3)
			ft_sort_three(&a, 'a');
		else if (size <= 5)
			ft_sort_up_to_five(&a, &b, size);
		else
			ft_sort_stack(&a, &b);
	}
	return (ft_free_stack(&a), ft_free_stack(&b), 0);
}

/*
* First step - Check arguments
* Second step - Cases depending on the number of elements
* Third step - Check if sorted, if not, pass what is not inside the
* largest subsequence sorted to the  stack b
* Forth step - Calculate which one takes the lowest number of moves and
* do so.
*/
int	main(int argc, char **argv)
{
	char	**res;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ft_sintax_check(argc, argv) == -1)
		return (-1);
	if (argc == 2)
	{
		res = ft_split(argv[1], ' ');
		if (res == NULL)
			return (write(2, "Error\n", 6), -1);
		ft_execute(res, ft_split_size(res), a, b);
		ft_free_split(res);
	}
	else
	{
		res = &argv[1];
		ft_execute(res, argc - 1, a, b);
	}
	return (0);
}
