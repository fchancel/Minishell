/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_env.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 14:52:11 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/21 14:11:49 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
**			Renvoi un pointeur sur la premier occurence trouver dans l'env
**			selon l'elem envoyer
*/

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

/*
**			Permet de recuperer la taille (nb de ligne) de l'env
*/

int		len_env(char **env)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while (env[i])
	{
		count++;
		i++;
	}
	return (count);
}

/*
**			Permet de dupliquer l'env dans un maillon d'une liste chainee
*/

t_env		*dup_env(char **env)
{
	t_env	*my_env;
	int		i;

	i = 0;
	if ((my_env = (t_env*)malloc(sizeof(t_env))) == NULL)
		display_error_exit("error malloc my_env in dup_env");
	if ((my_env->env = (char **)malloc(sizeof(char *) * (len_env(env) + 1))) == NULL)
		display_error_exit("error malloc my_env->env in dup_env");
	while (env[i])
	{
		my_env->env[i] = ft_strdup(env[i]);
		i++;
	}
	return (my_env);
}

