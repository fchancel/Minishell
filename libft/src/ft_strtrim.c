/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 11:18:31 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 16:16:28 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	if (!(s))
		return (NULL);
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
	{
		j++;
		if (s[j] == '\0')
			return (ft_strnew(0));
	}
	i = ft_strlen(s);
	if (s != NULL)
		i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	str = ft_strsub(s, j, i - j + 1);
	return (str);
}
