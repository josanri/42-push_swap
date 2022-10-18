/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:59:04 by josesanc          #+#    #+#             */
/*   Updated: 2022/10/14 19:30:46 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	counter;
	int	res;

	counter = 0;
	res = 0;
	while (!res && (s1[counter] != '\0' || s2[counter] != '\0'))
	{
		res = s1[counter] - s2[counter];
		if (!res)
			counter++;
	}
	res = s1[counter] - s2[counter];
	return (res);
}
