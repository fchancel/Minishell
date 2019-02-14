/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 06:22:24 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 07:14:50 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int nb_copy;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	nb_copy = n;
	if (nb_copy > 9)
	{
		ft_putnbr(nb_copy / 10);
		ft_putnbr(nb_copy % 10);
	}
	else
		ft_putchar(nb_copy + '0');
}
