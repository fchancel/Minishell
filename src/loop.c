/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loop.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/25 14:41:03 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 10:25:23 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int		bol;

int		loop(t_env *my_env)
{
	t_cmd	*cmd;

	cmd = NULL;

	while (1)
	{
		bol = 0;
		prompt();
		signal(SIGINT, &signal_handler);
		cmd = get_line();
		bol = 1;
		loop_lk_list(cmd, my_env);
	}
	return (0);
}

int		loop_lk_list(t_cmd *cmd, t_env *my_env)
{
	char	*path;
	char	**final_path;
	t_cmd	*start;

	start = cmd;
	while (cmd)
	{
		//CHECK BUILTIN EXIT ENV CD ECHO
		if (check_builtins(cmd->tab_cmd) == 1)
			free_all(start, my_env, EXIT);
		path = get_env(my_env->env, "PATH");
		final_path = get_path(path, cmd->tab_cmd);
		path = control_access(final_path);
		if (path == NULL)
			no_command(cmd->tab_cmd[0]);
		else
			exec_cmd(cmd->tab_cmd, path, my_env->env);
		ft_free_2tab((void**)final_path);
		cmd = cmd->next;
	}
	free_all(start, my_env, NO_EXIT);
	return (0);
}

void	signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar('\n');
		if (bol == 0)
			prompt();
	}
}
