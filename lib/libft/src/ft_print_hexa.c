/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:06:09 by lmangall          #+#    #+#             */
/*   Updated: 2023/04/18 15:06:11 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_print_hexa(unsigned int nbr, char spec)
{
	int		count;
	char	*str;

	if (spec == 'x')
		str = ft_itoa_base(nbr, HEX_BASE_LOWER);
	else
		str = ft_itoa_base(nbr, HEX_BASE_UPPER);
	count = ft_putstr(str);
	ft_free(str);
	return (count);
}
