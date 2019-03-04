/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_cd.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/28 14:58:44 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/04 18:18:02 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void	builtin_cd(char **cmd, t_env *my_env)
{
	char	*tilde;

	tilde = NULL;
	if (!cmd[1])
	{
		replace_env(&my_env, get_env(my_env->env, "PWD"), "OLDPWD=");
		chdir(get_env(my_env->env, "HOME"));
		replace_env(&my_env, tilde, "PWD=");
		free(tilde);
		return ;
	}
	else if (cmd[1][0] == '~')
		tilde = if_tilde(cmd[1], my_env->env);
	if (ft_strcmp(cmd[1], "-") == 0)
		my_env = cd_back(my_env);
	else
		my_env = cd_normal(my_env, cmd, tilde);
	if (tilde != NULL)
		free(tilde);
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
	free(old_pwd);
	return (my_env);
}

t_env	*cd_normal(t_env *my_env, char **cmd, char *tilde)
{
	char	*old_pwd;
	char	*pwd;

	old_pwd = getcwd(NULL, 0);
	replace_env(&my_env, old_pwd, "OLDPWD=");
	if (tilde != NULL)
	{
		if (chdir(tilde) == -1)
			ft_putendl("Error chdir in builin_cd");
	}
	else if (chdir(cmd[1]) == -1)

		ft_putendl("Error chdir in builin_cd");
	pwd = getcwd(NULL, 0);
	replace_env(&my_env, pwd, "PWD=");
	free(old_pwd);
	free(pwd);
	return (my_env);
}

void	replace_env(t_env **my_env, char *str, char *elem)
{
	int			i;
	size_t		size;

	size = ft_strlen(elem);
	i = 0;
	while ((*my_env)->env[i])
	{
		if (ft_strncmp((*my_env)->env[i], elem, size) == 0)
			break;
		i++;
	}
	free((*my_env)->env[i]);
	(*my_env)->env[i] = ft_strjoin(elem, str);
}

char	*if_tilde(char *str, char **env)
{
	char	*begin_path;
	char	*tmp;

	begin_path = get_env(env, "HOME");
	begin_path = ft_strjoin(begin_path, "/");
	str = ft_strsub(str, 1, ft_strlen(str));
	tmp = str;
	str = ft_strjoin(begin_path, str);
	free(tmp);
	free(begin_path);
	return (str);
}
