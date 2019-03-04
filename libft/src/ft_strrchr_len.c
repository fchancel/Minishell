/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr_len.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 11:50:43 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/04 14:26:54 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strrchr_len(const char *s, int c)
{
	size_t l_s;

	l_s = ft_strlen(s);
	if (c == '\0')
		return (l_s);
	while (l_s--)
	{
		if (s[l_s] == c)
			return (l_s);
	}
	return (ft_strlen(s));
}
