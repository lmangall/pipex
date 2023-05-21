/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:54:57 by lmangall          #+#    #+#             */
/*   Updated: 2022/12/09 22:10:46 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (*s != '\0')
	{
		counter++;
		s++;
	}
	return (counter);
}
/*
int main(void)
{
    char str[] = "countme";
    size_t cnt = ft_strlen(str);
    cnt += '0';
    write (1, &cnt, 1);
    return (0);
}
*/
/*

                  IS THERE MORE SIMPLE THAN A COUNTER ?

DESCRIPTION
       The  ft_strlen()  function  calculates  the  length of the
       string pointed to by s, excluding the terminating  null
       byte ('\0').

RETURN VALUE
       The  ft_strlen()  function  returns the number of bytes in
       the string pointed to by s.
*/
