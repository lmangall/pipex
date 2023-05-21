/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:51:17 by lmangall          #+#    #+#             */
/*   Updated: 2023/04/18 15:11:21 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	absolute_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = get_len(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	if (n < 0)
		result[0] = '-';
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		--len;
		result[len] = absolute_value(n % 10) + '0';
		n = n / 10;
	}
	return (result);
}
