/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:05:38 by lmangall          #+#    #+#             */
/*   Updated: 2023/04/18 15:11:43 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = STR_NULL;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
