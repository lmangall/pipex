/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:50:27 by lmangall          #+#    #+#             */
/*   Updated: 2023/01/08 22:18:09 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tdst;
	const unsigned char	*tsrc;

	if (!dst && !src)
		return (0);
	tdst = (unsigned char *) dst;
	tsrc = (const unsigned char *) src;
	while (n-- > 0)
		*(tdst++) = *(tsrc++);
	return (dst);
}
/*
int main(void)
{
    char			src[] = "Pleaseletmebe";
    unsigned char	dest[] = "I will get you";
    size_t			n = 10;

	char	*s1 = memcpy(dest, src, n);
	char	*s2 = ft_memcpy(dest, src, n);
	printf ("memcpy: %s\nft_memcpy: %s\n", s1, s2);
}
*/
/*

DESCRIPTION
     The memcpy() function copies n bytes from memory area src to memory area
     dst.  If dst and src overlap, behavior is undefined.  Applications in
     which dst and src might overlap should use memmove(3) instead.

RETURN VALUES
     The memcpy() function returns the original value of dst.


*/