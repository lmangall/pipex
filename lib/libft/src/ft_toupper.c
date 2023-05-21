/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:55:42 by lmangall          #+#    #+#             */
/*   Updated: 2022/12/09 21:58:15 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <unistd.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -= 32);
	else
		return (c);
}
/*
int main(void)
{
    int c = 104;
    c = ft_toupper(c);
    write (1, &c, 1);
    write (1, "\n", 1);
}
*/