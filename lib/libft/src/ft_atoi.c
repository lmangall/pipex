/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:08:23 by lmangall          #+#    #+#             */
/*   Updated: 2023/01/10 13:49:54 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	base;
	int	i;

	sign = 1;
	base = 0;
	i = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	while (*str == '\n' || *str == '\f' || *str == '\r')
		str++;
	if (!str)
		return (0);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		base = (str[i] - '0') + (base * 10);
		i++;
	}
	return (base * sign);
}
/*
int main(void)
{
	char *str;
	str = "985";
	
	int i1 = atoi(str);
	int i2 = ft_atoi(str);
	
	printf("atoi: %d\nft_atoi: %d\n", i1, i2);
}
*/

/*

SYNOPSIS
     #include <stdlib.h>

     int
     atoi(const char *str);

     #include <xlocale.h>

     int
     atoi_l(const char *str, locale_t loc);

DESCRIPTION
     The atoi() function converts the initial portion of the string pointed
     to by str to int representation.

     It is equivalent to:

           (int)strtol(str, (char **)NULL, 10);

     While the atoi() function uses the current locale, the atoi_l()
     function may be passed a locale directly. See xlocale(3) for more
     information.

*/