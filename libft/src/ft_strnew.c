/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 07:28:15 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 20:03:12 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = -1;
	str = NULL;
	if ((str = (char *)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	while (i++ != size)
		str[i] = '\0';
	return (str);
}
