/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:51:11 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 18:37:01 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	if (!(dest = ft_strnew(ft_strlen(s))))
		return (NULL);
	else
	{
		while (s[i])
		{
			dest[i] = s[i];
			i++;
		}
		return (dest);
	}
}
