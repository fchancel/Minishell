/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 05:29:51 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 14:12:35 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int n)
{
	int	count;

	count = 1;
	while (n / 10 > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char	*array;
	int		bol;
	int		i;

	i = 0;
	bol = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		bol = 1;
	}
	if (!(array = ft_strnew(ft_count(n) + bol)))
		return (NULL);
	i = ft_count(n) + bol;
	while (i != 0)
	{
		array[--i] = n % 10 + '0';
		n = n / 10;
	}
	if (bol == 1)
		array[0] = '-';
	return (array);
}
