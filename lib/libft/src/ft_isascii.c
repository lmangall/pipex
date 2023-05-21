/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:20:08 by lmangall          #+#    #+#             */
/*   Updated: 2022/12/09 22:46:25 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
isascii()
              checks whether c is a 7-bit unsigned char value that  fits  into
              the ASCII character set.
*/