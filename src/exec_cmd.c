/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec_cmd.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 11:34:33 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/06 19:15:57 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exec_cmd(t_cmd *cmd, char *path, t_env *my_env)
{
	pid_t	pid;

	if (!cmd->tab_cmd)
		return ;
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, cmd->tab_cmd, my_env->env) == -1)
		{
			if ((access(cmd->tab_cmd[0], X_OK) == -1))
				ft_putendl(" : Permissions denied");
			else
			{
				ft_putstr("Are you stupid ? ");
				ft_putstr(cmd->tab_cmd[0]);
				ft_putendl(" It's not a command");
			}
			free_all(cmd, my_env, EXIT);
			return ;
		}
	}
	else if (pid < 0)
		return ;
	wait(&pid);
	return ;
}
