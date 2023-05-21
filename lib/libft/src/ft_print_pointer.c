/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:07:13 by lmangall          #+#    #+#             */
/*   Updated: 2023/04/18 15:07:16 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_print_pointer(void *ptr)
{
	int				bytes;
	char			*str;
	unsigned long	address;

	if (!ptr)
	{
		bytes = ft_putstr(PTR_NULL);
		return (bytes);
	}
	address = (unsigned long)ptr;
	bytes = ft_putstr(INI_PTR);
	str = ft_itoa_base(address, HEX_BASE_LOWER);
	bytes += ft_putstr(str);
	ft_free(str);
	return (bytes);
}
