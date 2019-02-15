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

int		len_env(char **env)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (env[i])
	{
		count++;
		i++;
	}
	return (count);
}

t_env		*dup_env(char **env)
{
	t_env	my_env;
	int	i;

	i = 0;
	if ((my_env = (t_env *)malloc(sizeof(t_env)) == NULL))
		return (); // erreur de malloc;
	if ((my_env->env = (char **)malloc(sizeof(char *) * (len_env(env)) + 1) == NULL))
		return (); // Erreur de malloc;
	while (env[i])
	{
		my_env->env = ft_strdup(env[i]);
		i++;
	}
	return (my_env);
}

