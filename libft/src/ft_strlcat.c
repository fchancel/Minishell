/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 08:01:29 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 16:57:48 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		l_dest;
	size_t		l_src;
	size_t		l_total;

	l_dest = ft_strlen(dest);
	l_src = ft_strlen(src);
	if (size == 0)
		return (l_src);
	if (size < l_dest)
		l_total = l_src + size;
	else
		l_total = l_dest + l_src;
	l_src = -1;
	while (src[++l_src] && l_src + l_dest < size - 1)
		dest[l_dest + l_src] = src[l_src];
	dest[l_dest + l_src] = '\0';
	return (l_total);
}
