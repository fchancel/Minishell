/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec_cmd.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 11:34:33 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 17:41:47 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exec_cmd(char **cmd, char *path, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(path, cmd, env);
	else if (pid < 0)
		return;
	wait(&pid);
	return;
}
