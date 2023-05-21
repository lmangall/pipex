/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:40:42 by lmangall          #+#    #+#             */
/*   Updated: 2023/01/08 22:18:24 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tempdest;
	const unsigned char	*tempsrc;
	size_t				i;

	if (!dest && !src)
		return (0);
	tempdest = (unsigned char *)dest;
	tempsrc = (unsigned char *)src;
	i = 0;
	if (tempsrc < tempdest)
		while (++i <= n)
			tempdest[n - i] = tempsrc[n - i];
	else
		while (n-- > 0)
			*(tempdest++) = *(tempsrc++);
	return (dest);
}
/*
int main(void)
{
    char src[] = "Pleaseletmebe";
    unsigned char dest[] = "I will get you";
    size_t n = 10;
    ft_memmove(dest, src, n);
    write(1, &dest, 14);
}
*/
/*
IF src is before(czyli smaller than) dest (as pointer address)
 copz from src to dest starting by end

    unsigned char *temp;
    temp = dest;
    unsigned char *tempsrc;
    tempsrc = src;
    while (n != 0)
    {
        *temp = *tempsrc;
        n--;
        temp++;
        src++;
    }
    return (dest);

}

*/

/*


IF src is before dest (as pointer address) copz from src to dest starting by end



SYNOPSIS
       #include <string.h>

       void *memmove(void *dest, const void *src, size_t n);

DESCRIPTION
The  memmove()  function  copies n bytes from memory area src to memory
 area dest.  The memory areas may overlap: copying takes place as though
the  bytes in src are first copied into a temporary array that does not
overlap src or dest, and the bytes are then copied from  the  temporary
array to dest.

RETURN VALUE
       The memmove() function returns a pointer to dest.

*/