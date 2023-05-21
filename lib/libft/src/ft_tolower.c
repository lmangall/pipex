/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:31:15 by lmangall          #+#    #+#             */
/*   Updated: 2022/12/09 21:57:29 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <unistd.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c += 32);
	else
		return (c);
}
/*
int main(void)
{
    int c = 104;
    c = ft_tolower(c);
    write (1, &c, 1);
    write (1, "\n", 1);
}
*/