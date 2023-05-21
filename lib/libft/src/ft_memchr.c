/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:11:32 by lmangall          #+#    #+#             */
/*   Updated: 2022/12/10 13:41:56 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			len;
	unsigned char	*str;

	len = 0;
	str = (unsigned char *)s;
	while (++len <= n)
		if (*(str++) == (unsigned char)c)
			return ((void *)--str);
	return (0);
}
/*
int main (void)

{
const char s[] = "trouve moi ca";
char c = 'm';
char *ret;
size_t n = 12;

ret = ft_memchr(s, c, n);
printf("string after '%c' is: '%s'\n\n", c, ret);
ret = memchr(s, c, n);
printf("string after '%c' is: '%s'\n", c, ret);
}
*/

/*

DESCRIPTION
       The  memchr()  function  scans  the  initial n bytes of the memory area
       pointed to by s for the first instance of c.  Both c and the  bytes  of
       the memory area pointed to by s are interpreted as unsigned char.


*/