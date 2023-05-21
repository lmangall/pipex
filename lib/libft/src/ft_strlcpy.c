/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:41:32 by lmangall          #+#    #+#             */
/*   Updated: 2022/12/10 14:30:16 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
int main(void)
{
    char dst[20];
    const char src[] = "take me to dst, bitch!";
    size_t size = 15;
     size_t r;

    r = ft_strlcpy(dst, src, size);
    write(1, &dst, 20);
     printf("%zu\n", r);
*/
/*
    strlcpy(dst, src, size);
    write(1, &dst, 20);
*/
/*

The strlcpy() function copies up to size - 1 characters from the NUL-ter‐
     minated string src to dst, NUL-terminating the result.

strlcpy() and strlcat() take the full size of the buffer (not just
     the length) and guarantee to NUL-terminate the result (as long as size is
     larger than 0 or, in the case of strlcat(), as long as there is at least
     one byte free in dst).


SYNOPSIS
     #include <string.h>

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

EXAMPLES
     The following code fragment illustrates the simple case:

           char *s, *p, buf[BUFSIZ];

           ...

           (void)strlcpy(buf, s, sizeof(buf));
           (void)strlcat(buf, p, sizeof(buf));

     To detect truncation, perhaps while building a pathname, something like
     the following might be used:


*/