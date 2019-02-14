/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_tab.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 16:53:41 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 09:57:26 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		*ft_sort_tab(int *tab, int size)
{
	int i;
	int j;
	int swap;

	i = 1;
	while (i < size)
	{
		j = i;
		while (tab[j] < tab[j - 1] && j > 0)
		{
			swap = tab[j];
			tab[j] = tab[j - 1];
			tab[j - 1] = swap;
			j--;
		}
		i++;
	}
	return (tab);
}
