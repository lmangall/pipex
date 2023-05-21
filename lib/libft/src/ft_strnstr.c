/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:08:39 by lmangall          #+#    #+#             */
/*   Updated: 2022/12/13 19:56:19 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hlen;
	size_t	nlen;

	hlen = 0;
	if (*needle == '\0' || needle == NULL)
		return ((char *) haystack);
	while (haystack[hlen] != '\0' && hlen < len)
	{
		nlen = 0;
		while (needle[nlen] == haystack[hlen + nlen] && hlen + nlen < len)
		{
			if (needle[nlen + 1] == '\0')
			{
				return ((char *) haystack + hlen);
			}
			nlen++;
		}
		hlen++;
	}
	return (NULL);
}

/*
int main()
{

    char    *s1 = "haystackhaystackneedlehaystack";
    char    *s2 = "needle";
    size_t  len = ft_strlen(s1);

    char    *i1 = strnstr(s1, s2, len);
    char    *i2 = ft_strnstr(s1, s2, len);


    printf("strnstr: %s\nft_strnstr: %s\n", i1,i2);
    return 0;
}
*/

/*

NAME
     strstr, strcasestr, strnstr – locate a substring in a string

LIBRARY
     Standard C Library (libc, -lc)

SYNOPSIS
     #include <string.h>

     char *
     strstr(const char *haystack, const char *needle);

     char *
     strcasestr(const char *haystack, const char *needle);

     char *
     strnstr(const char *haystack, const char *needle, size_t len);

     #include <string.h>
     #include <xlocale.h>

     char *
     strcasestr_l(const char *haystack, const char *needle, locale_t loc);

DESCRIPTION
     The strstr() function locates the first occurrence of the null-
     terminated string needle in the null-terminated string haystack.

     The strcasestr() function is similar to strstr(), but ignores the case
     of both strings.

     The strnstr() function locates the first occurrence of the null-
     terminated string needle in the string haystack, where not more than
     len characters are searched.  Characters that appear after a ‘\0’
     character are not searched.  Since the strnstr() function is a FreeBSD
     specific API, it should only be used when portability is not a
     concern.

     While the strcasestr() function uses the current locale, the
     strcasestr_l() function may be passed a locale directly. See
     xlocale(3) for more information.

RETURN VALUES
     If needle is an empty string, haystack is returned; if needle occurs
     nowhere in haystack, NULL is returned; otherwise a pointer to the
     first character of the first occurrence of needle is returned.



*/