/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec_cmd.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 11:34:33 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/04 11:36:39 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exec_cmd(char **cmd, char *path, char **env)
{
	pid_t	pid;

	if (!cmd[0])
		return ;
	pid = fork();
	if (pid == 0)
		execve(path, cmd, env);
	else if (pid < 0)
		return ;
	wait(&pid);
	return ;
}
