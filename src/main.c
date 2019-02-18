/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:00:18 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 19:30:59 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int		main(int ac, char **av, char **env)
{
//	char	*path;
//	char	**final_path;
	t_env	*my_env;
	char	*pwd;
	t_cmd	*cmd;
	int		i = 0;
	(void)ac;
	(void)av;
	my_env = dup_env(env);
	pwd = get_env(my_env->env, "PWD");
	while (1)
	{
		prompt(pwd);									//OK   AFFICHER LE PROMPT
		cmd = get_line();								//OK   RECUPERER UNE LISTE CHAINE AVEC UN DOUBLE TABLEAU POUR LES COMMANDES
	//	path = get_env(my_env->env, "PATH");
		while (cmd)
		{
			while (cmd->tab_cmd[i])
			{
				dprintf(1, "||%s||", cmd->tab_cmd[i]);
				i++;
			}
				dprintf(1, "\n");
			i = 0;
			cmd = cmd->next;
		}
//
//		final_path = get_path(path, cmd->tab_cmd);
//
//		path = control_access(final_path);
//		if (path == NULL)
//		{
//			ft_putstr("minishell: command not found: ");
//			ft_putstr(cmd->tab_cmd[0]);
//		}
//		else
//			exec_cmd(cmd->tab_cmd, path, my_env->env);
	}
	return (0);
}
