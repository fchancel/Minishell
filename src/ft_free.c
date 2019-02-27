/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/25 15:46:06 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 19:02:15 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void		free_all(t_cmd *cmd, t_env *my_env, int is_exit)
{
	t_cmd	*p_cmd;

	while (cmd)
	{
		p_cmd = cmd->next;
		ft_free_2tab((void**)cmd->tab_cmd);
		free(cmd);
		cmd = p_cmd;
	}
	free(cmd);
	if (is_exit == EXIT)
	{
		free(my_env->pwd);
		free(my_env->old_pwd);
		ft_free_2tab((void**)my_env->env);
		free(my_env);
		exit(0);
	}
}
