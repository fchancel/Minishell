/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/25 15:40:07 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 17:05:59 by fchancel    ###    #+. /#+    ###.fr     */
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
		else if (ft_strcmp(cmd[0], "cd") == 0)
		{
			builtin_cd(cmd, my_env);
			return (1);
		}
	}
	return (0);
}

void	builtin_echo(char **cmd, t_env *my_env)
{
	int		i;

	i = 1;
	while (cmd[i])
	{
		if (cmd[i][0] == '$')
		{
			annex_echo(cmd[i], my_env->env);
			i++;
		}
		if (cmd[i] && cmd[i][0] != '$')
		{
			ft_putstr(cmd[i]);
			ft_putchar(' ');
			i++;
		}
	}
	ft_putchar('\n');
}

void	annex_echo(char *cmd, char **env)
{
	char	*tmp;
	int		size;
	int		i;
	char	*line;

	i = 1;
	size = 0;
	while (cmd[i] && (ft_isalnum(cmd[i]) == 1))
	{
		size++;
		i++;
	}
	if ((tmp = ft_strsub(cmd, 1, size)) == NULL)
		display_error_exit("Error ft_strsub in annex_echo");
	line = get_env(env, tmp);
	ft_putstr(line);
	while (cmd[i])
	{
		ft_putchar(cmd[i]);
		i++;
	}
	ft_putchar(' ');
	free(tmp);
}

void	builtin_cd(char **cmd, t_env *my_env)
{
	if (ft_strcmp(cmd[1], "-") == 0)
	{
		if (chdir(my_env->old_pwd) == -1)
			ft_putendl("Error chdir in builin_cd");
	}
	else
	{
		getcwd(my_env->old_pwd, 1000);
		if (chdir(cmd[1]) == -1)
			ft_putendl("Error chdir in builin_cd");
		getcwd(my_env->pwd, 1000);
	}
}
