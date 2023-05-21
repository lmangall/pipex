/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:40:49 by lmangall          #+#    #+#             */
/*   Updated: 2022/12/10 20:16:09 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*temp;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	temp = malloc(sizeof(char) * (size + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
