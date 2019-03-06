/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_env.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 14:50:02 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/06 17:01:24 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int			builtin_env(t_cmd *cmd, t_env *my_env)
{
	char 	*tmp;

	if (!cmd->tab_cmd[1])
		print_env(my_env);
	else if (cmd->tab_cmd[1] && (ft_strchr(cmd->tab_cmd[1], '=') == NULL))
	{
		tmp = cmd->tab_cmd[1];
		free(cmd->tab_cmd[0]);
		cmd->tab_cmd[0] = ft_strdup(tmp);
		free(cmd->tab_cmd[1]);
		cmd->tab_cmd[1] = NULL;
		return (0);
	}
	return (1);
}

void		print_env(t_env *my_env)
{
	int		i;

	i = 0;
	while (my_env->env[i])
	{
		ft_putstr(my_env->env[i]);
		ft_putchar('\n');
		i++;
	}
}

void		builtin_setenv(char **cmd, t_env *my_env)
{
	char	*var;
	char	**n_env;
	int		i;
	char	*elem;

	elem = ft_strjoin(cmd[1], "=");
	i = -1;
	n_env = NULL;
	if (!cmd[1] || !cmd[2] || cmd[3])
		ft_putendl("usage : setenv [MYVAR][myvalue]");
	else if ((var = get_env(my_env->env, elem)) != NULL)
		replace_env(&my_env, cmd[2], elem);
	else
	{
		if ((n_env = (char**)ft_memalloc(sizeof(char*)
						* (len_env(my_env->env) + 2))) == NULL)
			display_error_exit("Error malloc n_env in ft_builtin_setenv");
		while (my_env->env[++i])
			n_env[i] = ft_strdup(my_env->env[i]);
		n_env[i] = ft_strjoin(elem, cmd[2]);
		ft_free_2tab((void**)my_env->env);
		my_env->env = n_env;
	}
	free(elem);
}

void		builtin_unsetenv(char **cmd, t_env *my_env)
{
	int		i;
	int		j;
	char	**n_env;

	i = -1;
	j = -1;
	if (!cmd[1] || cmd[2])
		ft_putendl("usage : unsetenv [MYVAR]");
	else if ((get_env(my_env->env, cmd[1])) == NULL)
		return ;
	else
	{
		if ((n_env = (char**)ft_memalloc(sizeof(char*)
						* (len_env(my_env->env) + 1))) == NULL)
			display_error_exit("Error malloc n_env in ft_builtin_setenv");
		while (my_env->env[++i])
		{
			if (!(ft_strncmp(my_env->env[i], cmd[1], ft_strlen(cmd[1])) == 0))
				n_env[++j] = ft_strdup(my_env->env[i]);
		}
		ft_free_2tab((void**)my_env->env);
		my_env->env = n_env;
	}
}
