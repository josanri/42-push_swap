/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:23:47 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/17 20:12:21 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

static int	ft_check_num(char *s, int negative)
{
	if (*s == '\0')
		return (0);
	while (*s == '0')
		s++;
	if (ft_strlen(s) > 10)
		return (0);
	if (ft_strlen(s) == 10)
	{
		if (negative && s[0] <= '2' && s[1] <= '1' && s[2] <= '4' && s[3] <= '7'
			&& s[4] <= '4' && s[5] <= '8' && s[6] <= '3'
			&& s[7] <= '6' && s[8] <= '4' && s[9] <= '8')
			return (1);
		else if (s[0] <= '2' && s[1] <= '1' && s[2] <= '4' && s[3] <= '7'
			&& s[4] <= '4' && s[5] <= '8' && s[6] <= '3'
			&& s[7] <= '6' && s[8] <= '4' && s[9] <= '7')
			return (1);
		else
			return (0);
	}
	while (*s++ != '\0')
		if (*(s - 1) < '0' || *(s - 1) > '9')
			return (0);
	return (1);
}

static int	ft_is_num(char *s)
{
	int	i;

	i = 0;
	if (*s == '\0')
		return (0);
	if (*s == '-' || *s == '+')
		return (ft_check_num(s + 1, *s == '-'));
	else
		return (ft_check_num(s, 0));
}

static int	ft_two_args(int i, char **argv)
{
	char	**res;

	res = ft_split(argv[1], ' ');
	if (res == NULL)
		return (write(2, "Error\n", 6), -1);
	if (res[0] == NULL)
		return (free(res), write(2, "Error\n", 6), -1);
	i = -1;
	while (res[++i] != NULL)
	{
		if (ft_is_num(res[i]) == 0)
			return (ft_free_split(res), write(2, "Error\n", 6), -1);
	}
	ft_free_split(res);
	return (0);
}

int	ft_sintax_check(int argc, char **argv)
{
	int		i;

	if (argc <= 1)
		return (-1);
	if (argc == 2)
		return (ft_two_args(0, argv));
	else
	{
		i = 1;
		while (i < argc)
		{
			if (ft_is_num(argv[i]) == 0)
				return (write(2, "Error\n", 6), -1);
			i++;
		}
		return (0);
	}
}
