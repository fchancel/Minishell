/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fchancel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/25 15:46:06 by fchancel     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/25 15:53:23 by fchancel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void		free_exit(t_cmd *cmd, t_env *my_env)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (cmd)
	{
		tmp = cmd->next;
		ft_free_2tab((void**)cmd->tab_cmd);
		free(cmd);
		cmd = tmp;
	}
	free(cmd);
	free(my_env->env);
	free(my_env);
}
