/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_env.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 14:52:11 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/14 16:19:34 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

char		*get_env(char **env, char *elem)
{
	size_t		size_elem;
	int			i;

	size_elem = ft_strlen(elem);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], elem, size_elem) == 0)
			return ((ft_strrchr(env[i], '=')) + 1);
		i++;
	}
	return (NULL);
}
