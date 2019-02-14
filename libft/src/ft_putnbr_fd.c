/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 06:28:28 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 07:32:03 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nb_copy;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	nb_copy = n;
	if (nb_copy > 9)
	{
		ft_putnbr_fd(nb_copy / 10, fd);
		ft_putnbr_fd(nb_copy % 10, fd);
	}
	else
		ft_putchar_fd(nb_copy + '0', fd);
}
