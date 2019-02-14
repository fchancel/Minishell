/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display_s2tab.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 08:36:56 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 08:44:45 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_display_s2tab(char **tab, char c)
{
	int		i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar(c);
		i++;
	}
}
