/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_cd.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/28 14:58:44 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/06 18:04:48 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void	builtin_cd(char **cmd, t_env *my_env)
{
	if (!cmd[1])
	{
		if (get_env(my_env->env, "HOME") == NULL)
			ft_putendl("cd : HOME not set");
		else
		{
			replace_env(&my_env, get_env(my_env->env, "PWD"), "OLDPWD=");
			chdir(get_env(my_env->env, "HOME"));
			replace_env(&my_env, get_env(my_env->env, "HOME"), "PWD=");
		}
		return ;
	}
	if (ft_strcmp(cmd[1], "-") == 0)
		my_env = cd_back(my_env);
	else
		my_env = cd_normal(my_env, cmd);
}

t_env	*cd_back(t_env *my_env)
{
	char	*pwd;
	char	*old_pwd;

	pwd = get_env(my_env->env, "PWD");
	if (chdir(get_env(my_env->env, "OLDPWD")) == -1)
		ft_putendl("Error chdir in builin_cd");
	replace_env(&my_env, pwd, "OLDPWD=");
	old_pwd = getcwd(NULL, 0);
	replace_env(&my_env, old_pwd, "PWD=");
	ft_putendl(get_env(my_env->env, "PWD="));
	free(old_pwd);
	return (my_env);
}

t_env	*cd_normal(t_env *my_env, char **cmd)
{
	char	*old_pwd;
	char	*pwd;

	old_pwd = getcwd(NULL, 0);
	replace_env(&my_env, old_pwd, "OLDPWD=");
	if (chdir(cmd[1]) == -1)
		ft_putendl("Error chdir in builin_cd");
	pwd = getcwd(NULL, 0);
	replace_env(&my_env, pwd, "PWD=");
	free(old_pwd);
	free(pwd);
	return (my_env);
}
