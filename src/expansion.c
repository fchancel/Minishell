/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   expansion.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 10:52:49 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/06 19:18:37 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

t_cmd	*replace_expansion(t_cmd *cmd, t_env *my_env)
{
	int		i;
	t_cmd	*start;
	char	*tmp;
	char	expansion;

	tmp = NULL;
	start = cmd;
	while (cmd)
	{
		i = 0;
		while (cmd->tab_cmd[i])
		{
			if (cmd->tab_cmd[i][0] == '~' || cmd->tab_cmd[i][0] == '$')
			{
				expansion = cmd->tab_cmd[i][0];
				tmp = cmd->tab_cmd[i];
				cmd->tab_cmd[i] = if_expansion(cmd->tab_cmd[i], my_env->env,
						expansion, ft_strchr(cmd->tab_cmd[i], '$') + 1);
				free(tmp);
			}
			i++;
		}
		cmd = cmd->next;
	}
	return (start);
}

char	*if_expansion(char *str, char **env, char expansion, char *search)
{
	char	*begin_path;
	char	*tmp;

	if (expansion == '~')
	{
		begin_path = get_env(env, "HOME");
		begin_path = ft_strjoin(begin_path, "/");
		str = ft_strsub(str, 1, ft_strlen(str));
		tmp = str;
		str = ft_strjoin(begin_path, str);
		free(tmp);
		free(begin_path);
		return (str);
	}
	else
	{
		begin_path = get_env(env, search);
		if (begin_path == NULL)
			return (ft_strdup(search));
		else
			return (ft_strdup(begin_path));
	}
}
