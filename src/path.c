/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 16:05:50 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 17:41:56 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

char		**get_path(char *total_path, char **av)
{
	char	**path;
	char	**tmp;
	int		i;
	char	*argument;

	argument = ft_strjoin("/", av[0]);
	i = 0;
	path = ft_strsplit(total_path, ':');
	tmp = path;

	while (tmp[i])
	{
		path[i] = ft_strjoin(path[i], argument);
		i++;
	}
	free(argument);
	return (path);
}

char			*control_access(char **path)
{
	int		i;

	i = 0;
	while (path[i])
	{
		if ((access(path[i], X_OK) == 0))
			return (path[i]);
		i++;
	}
	return (NULL);
}
