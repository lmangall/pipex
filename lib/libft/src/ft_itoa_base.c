/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:04:36 by lmangall          #+#    #+#             */
/*   Updated: 2023/04/18 15:11:25 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static	size_t	ft_inttobaselen(unsigned long long nbr, char *base)
{
	size_t				len;
	unsigned long long	baselen;

	len = 1;
	baselen = ft_strlen(base);
	while (nbr >= baselen)
	{
		nbr = nbr / baselen;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long long nbr, char *base)
{
	char	*result;
	int		i;
	int		sizeofbase;

	i = ft_inttobaselen(nbr, base);
	sizeofbase = ft_strlen(base);
	result = malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[i] = '\0';
	while (i > 0)
	{
		i--;
		result[i] = base[nbr % sizeofbase];
		nbr = (nbr / sizeofbase);
	}
	return (result);
}
