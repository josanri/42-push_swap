/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:05:08 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/12 17:31:06 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_free_split(char **res)
{
	int	i;

	i = -1;
	while (res[++i] != NULL)
		free(res[i]);
	free(res);
}

int	ft_split_size(char **res)
{
	int	i;

	i = 0;
	if (res == NULL)
		return (0);
	while (res[i] != NULL)
		i++;
	return (i);
}
