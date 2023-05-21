/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:26:55 by lmangall          #+#    #+#             */
/*   Updated: 2023/01/01 21:01:43 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = s;
	while (n != 0)
	{
		*temp = c;
		n--;
		temp++;
	}
	return (s);
}

/*
int    main(void)
   {
       char s[] = "XmeBaby";
       int c = 'X';
       size_t n = 6;
       ft_memset(s, c, n);
       write (1, &s, 8);
       return (0);
   }
*/

/*

DESCRIPTION
       The  memset()  function  fills  the  first  n  bytes of the memory area
       pointed to by s with the constant byte c.

RETURN VALUE
       The memset() function returns a pointer to the memory area s.


https://www.ibm.com/docs/en/i/7.1?topic=functions-memset-set-bytes-value

NAME
       memset - fill memory with a constant byte

SYNOPSIS
       #include <string.h>

       void *memset(void *s, int c, size_t n);

DESCRIPTION
       The  memset()  function  fills  the  first  n  bytes of the memory area
       pointed to by s with the constant byte c.

RETURN VALUE
       The memset() function returns a pointer to the memory area s.

*/