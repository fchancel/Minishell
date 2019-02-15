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
