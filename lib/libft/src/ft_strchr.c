/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:35:39 by lmangall          #+#    #+#             */
/*   Updated: 2023/01/10 21:36:45 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*sbis;
	char	cbis;

	sbis = (char *)s;
	cbis = (char)c;
	while (*sbis)
	{
		if (*sbis == cbis)
			return ((char *)sbis);
		sbis++;
	}
	if (*sbis == cbis)
		return ((char *)sbis);
	return (NULL);
}

/*
int    main (void)
{
		const char s[] = "trouve moi ca";
		char c = 'm';
		char *ret;
		ret = ft_strchr(s, c);

       printf("string after '%c' is: '%s'\n", c, ret);
}
*/