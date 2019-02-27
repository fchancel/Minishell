/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loop.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/25 14:41:03 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 15:33:30 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int		g_bol;

int		loop(t_env *my_env)
{
	t_cmd	*cmd;

	cmd = NULL;
	while (1)
	{
		g_bol = 0;
		prompt();
		signal(SIGINT, &signal_handler);
		cmd = get_line();
		g_bol = 1;
		loop_lk_list(cmd, my_env);
	}
	return (0);
}

int		loop_lk_list(t_cmd *cmd, t_env *my_env)
{
	char	*path;
	char	**final_path;
	t_cmd	*start;
	int		ret;

	start = cmd;
	while (cmd)
	{
		ret = check_builtins(cmd->tab_cmd, my_env);
		if (ret == -1)
			free_all(start, my_env, EXIT);
		else if (ret == 0)
		{
			path = get_env(my_env->env, "PATH");
			final_path = get_path(path, cmd->tab_cmd);
			path = control_access(final_path);
			if (path == NULL)
				no_command(cmd->tab_cmd[0]);
			else
				exec_cmd(cmd->tab_cmd, path, my_env->env);
			ft_free_2tab((void**)final_path);
		}
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
		if (g_bol == 0)
			prompt();
	}
}
