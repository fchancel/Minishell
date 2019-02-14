/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 05:30:01 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 09:38:15 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	l_dest;
	size_t	l_src;

	l_src = 0;
	l_dest = ft_strlen(dest);
	while (src[l_src])
	{
		dest[l_dest++] = src[l_src];
		l_src++;
	}
	dest[l_dest] = '\0';
	return (dest);
}
