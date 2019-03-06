/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/25 15:40:07 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/06 18:29:46 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int		check_builtins(t_cmd *cmd, t_env *my_env)
{
	if (cmd->tab_cmd[0])
	{
		if (ft_strcmp(cmd->tab_cmd[0], "exit") == 0)
			return (-1);
		else if (ft_strcmp(cmd->tab_cmd[0], "echo") == 0)
		{
			builtin_echo(cmd->tab_cmd, my_env);
			return (1);
		}
		else if (ft_strcmp(cmd->tab_cmd[0], "cd") == 0)
		{
			builtin_cd(cmd->tab_cmd, my_env);
			return (1);
		}
		else
		{
			if (parsing_env(cmd, my_env) == 1)
				return (1);
		}
	}
	return (0);
}

int		parsing_env(t_cmd *cmd, t_env *my_env)
{
	if (ft_strcmp(cmd->tab_cmd[0], "env") == 0)
	{
		if ((builtin_env(cmd, my_env) == 0))
				return (0);
		return (1);
	}
	else if (ft_strcmp(cmd->tab_cmd[0], "setenv") == 0)
	{
		builtin_setenv(cmd->tab_cmd, my_env);
		return (1);
	}
	else if (ft_strcmp(cmd->tab_cmd[0], "unsetenv") == 0)
	{
		builtin_unsetenv(cmd->tab_cmd, my_env);
		return (1);
	}
	return (0);
}

void	builtin_echo(char **cmd, t_env *my_env)
{
	int		i;
	(void)my_env;
	i = 1;
	while (cmd[i])
	{
			ft_putstr(cmd[i]);
			ft_putchar(' ');
			i++;
	}
	ft_putchar('\n');
}
