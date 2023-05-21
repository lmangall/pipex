/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:59:47 by lmangall          #+#    #+#             */
/*   Updated: 2023/01/10 21:36:56 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	int		i;
	char	*sbis;
	char	cbis;

	ret = NULL;
	i = 0;
	sbis = (char *)s;
	cbis = (char) c;
	while (sbis[i])
	{
		if (sbis[i] == (char)cbis)
			ret = &((char *)sbis)[i];
		i++;
	}
	if (cbis == '\0')
		ret = &((char *)sbis)[i];
	return (ret);
}
/*
int    main (void)
{
    const char s[] = "trouve moi ca, ca, et ca finalement";
    char c = 'c';
    char *ret;

    ret = ft_strchr(s, c);

    printf("string after last '%c' is: '%s'\n", c, ret);
}
*/
