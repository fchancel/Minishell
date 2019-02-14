/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 07:34:56 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 07:40:54 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*n_ptr;

	if (!size && ptr)
	{
		if (!(n_ptr = malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (n_ptr);
	}
	if (!(n_ptr = malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(n_ptr, ptr, size);
		ft_memdel(&ptr);
	}
	return (n_ptr);
}
