/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_cd.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/28 14:58:44 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/04 17:19:20 by fchancel    ###    #+. /#+    ###.fr     */
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
		tilde = ft_strjoin("/Users/", get_env(my_env->env, "USER="));
		chdir(tilde);
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
	char	tmp[1000];

	getcwd(tmp, 1000);
	if (chdir(my_env->old_pwd) == -1)
		ft_putendl("Error chdir in builin_cd");
	free(my_env->old_pwd);
	my_env->old_pwd = ft_strdup(tmp);
	free(my_env->pwd);
	my_env->pwd = getcwd(NULL, 0);
	return (my_env);
}

t_env	*cd_normal(t_env *my_env, char **cmd, char *tilde)
{
	(void)cmd[1];
	free(my_env->old_pwd);
	my_env->old_pwd = getcwd(NULL, 0);
	replace_env(&my_env, my_env->old_pwd, "OLDPWD=");
	if (tilde != NULL)
	{
		if (chdir(tilde) == -1)
			ft_putendl("Error chdir in builin_cd");
	}
	else if (chdir(cmd[1]) == -1)

		ft_putendl("Error chdir in builin_cd");
	getcwd(my_env->pwd, 1000);
	replace_env(&my_env, my_env->pwd, "PWD=");
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
	char	*tilde;
	char	*begin_path;
	char	*tmp;

	begin_path = "/Users/";
	str = ft_strsub(str, 1, ft_strlen(str));
	tmp = str;
	tilde = get_env(env, "USER=");
	tilde = ft_strjoin(begin_path, tilde);
	str = ft_strjoin(tilde, str);
	free(tilde);
	free(tmp);
	return (str);
}
