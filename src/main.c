/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:00:18 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/14 16:46:39 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int		main(int ac, char **av, char **env)
{
	char	*cmd;
	char	*path;
	char	**final_path;
	char 	**tab;
	(void)ac;
	(void)av;
	while (1)
	{
		prompt(env);
		cmd = ft_read();
		if (ft_strchr(cmd, ' ') != NULL)
			tab = ft_strsplit(cmd, ' ');
		else
			tab = ft_strsplit(cmd, '\n');
		path = get_env(env, "PATH");
		final_path = get_path(path, tab);
		path = control_access(final_path);
		if (path == NULL)
			ft_putstr("no command found \n");
		else
			exec_cmd(tab, path, env);
		free(cmd);
	}
	return (0);
}
