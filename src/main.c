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
#include <stdio.h>
int		main(int ac, char **av, char **env)
{
	char	*cmd;
	char	*path;
	char	**final_path;
	int		i;
	ac = 0;
	while (1)
	{
		prompt(env);
		cmd = ft_read();
		av = ft_strsplit(cmd, ' ');
		path = get_env(env, "PATH");
		final_path = get_path(path, av);
		i = control_access(final_path);
		printf("|||||i = %d |||", i );
		if (i < 0)
			return (-1);
		else
			ft_putchar('|');
		free(cmd);
	}
	return (0);
}
