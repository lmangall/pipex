/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:30 by lmangall          #+#    #+#             */
/*   Updated: 2022/12/10 13:54:01 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	t;

	dstlen = ft_strlen(dst);
	t = 0;
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	while (src[t] != '\0' && dstlen + 1 < size)
	{
		dst[dstlen] = src[t];
		dstlen++;
		t++;
	}
	dst[dstlen] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[t]));
}

/*
while                as long as there is at least
                     one byte free in dst

    return (ft_strlen(dst) + ft_strlen(src));

     It will append at most size - ft_strlen(dst) - 1 bytes, NUL-termi‐
     nating the result.

    return the initial length of dst plus the length of src
    */
/*
int main(void)
{
    const char src[] = "... my destination";
    char dst[] = "take me to ...";

    size_t size = 40;
     size_t r;

    r = ft_strlcat(dst, src, size);
     printf("%c\n", *dst);
     printf("%zu\n", r);
*/
/*SYNOPSIS
     #include <string.h>
     (See libbsd(7) for include usage.)

     size_t
     strlcpy(char *dst, const char *src, size_t size);

     size_t
     strlcat(char *dst, const char *src, size_t size);

DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings re‐
     spectively.  They are designed to be safer, more consistent, and less er‐
     ror prone replacements for strncpy(3) and strncat(3).  Unlike those func‐
     tions, strlcpy() and strlcat() take the full size of the buffer (not just
     the length) and guarantee to NUL-terminate the result (as long as size is
     larger than 0 or, in the case of strlcat(), as long as there is at least
     one byte free in dst).  Note that a byte for the NUL should be included
     in size.  Also note that strlcpy() and strlcat() only operate on true “C”
     strings.  This means that for strlcpy() src must be NUL-terminated and
     for strlcat() both src and dst must be NUL-terminated.
     
     The strlcpy() function copies up to size - 1 characters from the NUL-ter‐
     minated string src to dst, NUL-terminating the result.

     The strlcat() function appends the NUL-terminated string src to the end
     of dst.  It will append at most size - ft_strlen(dst) - 1 bytes, NUL-termi‐
     nating the result.

RETURN VALUES
     The strlcpy() and strlcat() functions return the total length of the
     string they tried to create.  For strlcpy() that means the length of src.
     For strlcat() that means the initial length of dst plus the length of
     src.  While this may seem somewhat confusing, it was done to make trunca‐
     tion detection simple.

RETURN VALUES
     The strlcpy() and strlcat() functions return the total length of the
     string they tried to create.  For strlcpy() that means the length of src.
     For strlcat() that means the initial length of dst plus the length of
     src.  While this may seem somewhat confusing, it was done to make trunca‐
     tion detection simple.

     Note, however, that if strlcat() traverses size characters without find‐
     ing a NUL, the length of the string is considered to be size and the des‐
     tination string will not be NUL-terminated (since there was no space for
     the NUL).  This keeps strlcat() from running off the end of a string.  In
     practice this should not happen (as it means that either size is incor‐
     rect or that dst is not a proper “C” string).  The check exists to pre‐
     vent potential security problems in incorrect code.


*/