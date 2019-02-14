/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 05:53:35 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 08:25:44 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(unsigned long nb, int count, int sign)
{
	if (nb > 9223372036854775807 || count > 19)
	{
		if (sign < 0)
			return (0);
		else
			return (-1);
	}
	return (1);
}

int			ft_atoi(const char *nptr)
{
	int				i;
	unsigned long	nb;
	int				sign;
	int				count;

	sign = 1;
	nb = 0;
	i = 0;
	count = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]) == 1)
	{
		nb = nb * 10 + (nptr[i] - '0');
		if (nptr[i] != '0')
			count++;
		i++;
	}
	if (ft_overflow(nb, count, sign) != 1)
		return (ft_overflow(nb, count, sign));
	return ((int)nb * sign);
}
