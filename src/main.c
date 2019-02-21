/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:00:18 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/21 19:28:14 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int		main(int ac, char **av, char **env)
{
	char	*path;
	char	**final_path;
	t_env	*my_env;
	char	*pwd;
	t_cmd	*cmd;
	(void)ac;
	(void)av;
	my_env = dup_env(env);
	pwd = get_env(my_env->env, "PWD");
	while (1)
	{
		prompt(pwd);									//OK	AFFICHER LE PROMPT
		signal(SIGINT, &signal_handler);
		cmd = get_line(my_env->env);								//OK	RECUPERER UNE LISTE CHAINE AVEC UN DOUBLE TABLEAU POUR LES COMMANDES
		while (cmd)
		{
			path = get_env(my_env->env, "PATH");		//OK	RECUPERE L'ENV'
			final_path = get_path(path, cmd->tab_cmd);	//OK	RECUPERE 
			path = control_access(final_path);
			if (path == NULL)
			{
				ft_putstr("minishell: command not found: ");
				ft_putendl(cmd->tab_cmd[0]);
			}
			else
				exec_cmd(cmd->tab_cmd, path, my_env->env);
			cmd = cmd->next;
		}
	}
	return (0);
}
