/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:45:37 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 19:07:25 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t l_s;

	l_s = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[l_s]);
	while (l_s--)
	{
		if (s[l_s] == c)
			return ((char *)&s[l_s]);
	}
	return (NULL);
}
