/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/25 15:40:07 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 12:47:56 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int		check_builtins(char **cmd, t_env *my_env)
{
	if (cmd[0])
	{
		if (ft_strcmp(cmd[0], "exit") == 0)
			return (-1);
		else if (ft_strcmp(cmd[0], "echo") == 0)
		{
			builtin_echo(cmd, my_env);
			return (1);
		}
	}
	return (0);
}

void	builtin_echo(char **cmd, t_env *my_env)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 1;
	while (cmd[i])
	{
		dprintf(1, "||%s||", cmd[i]);
		i++;
		ft_putchar('\n');
	}

	i = 1;
	while (cmd[i])
	{
		if (cmd[i][0] == '$')
		{
			tmp = ft_strsub(cmd[i], 1, ft_strlen(cmd[i]));
			line = get_env(my_env->env, tmp);
			ft_putstr(line);
			ft_putchar(' ');
			free(tmp);
			i++;
		}
		if (cmd[i])
		{
			ft_putstr(cmd[i]);
			ft_putchar(' ');
			i++;
		}
	}
	ft_putchar('\n');
}
