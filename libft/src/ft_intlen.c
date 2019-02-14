/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_intlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/27 12:58:45 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 13:23:16 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_intlen(int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	len = ft_strlen(str);
	free(str);
	return (len);
}
