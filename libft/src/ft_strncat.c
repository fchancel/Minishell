/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 06:36:09 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 09:13:12 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	l_dest;
	size_t	l_src;

	l_src = 0;
	l_dest = ft_strlen(dest);
	while (src[l_src] && l_src != n)
	{
		dest[l_dest++] = src[l_src];
		l_src++;
	}
	dest[l_dest] = '\0';
	return (dest);
}
